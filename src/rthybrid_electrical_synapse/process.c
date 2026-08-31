#include <math.h>
#include <string.h>
#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/process.h"

static double period_seconds_from_context(const rtsyn_abi_runtime_context_t *context)
{
    if (!context || context->period_ns == 0U) return 0.001;
    return (double)context->period_ns / 1000000000.0;
}

static int read_f64(const rtsyn_abi_runtime_context_t *context, uint32_t port_index, double *out_value)
{
    if (!context || !context->api || !context->api->read || !out_value) return 0;
    double value = 0.0;
    if (context->api->read(context, port_index, &value) != RTSYN_ABI_STATUS_OK) return 0;
    if (!isfinite(value)) return 0;
    *out_value = value;
    return 1;
}

static void clamp_f64(double *value, double fallback)
{
    if (!isfinite(*value)) {
        *value = fallback;
    } else if (fabs(*value) > 1e6) {
        *value = *value > 0.0 ? 1e6 : -1e6;
    }
}

typedef void (*rtsyn_rk4_deriv_fn_t)(const double *state, double *deriv, void *user_data);
static void rk4_step(double *state, size_t n, double dt, rtsyn_rk4_deriv_fn_t deriv_fn, void *user_data)
{
    double k1[8] = {0};
    double k2[8] = {0};
    double k3[8] = {0};
    double k4[8] = {0};
    double tmp[8] = {0};
    if (!state || !deriv_fn || n == 0 || n > 8 || dt <= 0.0) return;
    deriv_fn(state, k1, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k1[i];
    deriv_fn(tmp, k2, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k2[i];
    deriv_fn(tmp, k3, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + dt * k3[i];
    deriv_fn(tmp, k4, user_data);
    for (size_t i = 0; i < n; ++i) state[i] += (dt / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
}



rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    rtsyn_rthybrid_electrical_synapse_instance_t *self = (rtsyn_rthybrid_electrical_synapse_instance_t *)instance;
    if (!self || !context || !context->api || !context->api->write)
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    (void)read_f64(context, RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_POST_SYNAPTIC_VOLTAGE_V, &self->post_v);
    (void)read_f64(context, RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_PRE_SYNAPTIC_VOLTAGE_V, &self->pre_v);
    (void)read_f64(context, RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_SCALE_PRE_TO_POST, &self->scale);
    (void)read_f64(context, RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_OFFSET_PRE_TO_POST, &self->offset);
    if (!isfinite(self->g_us) || !isfinite(self->post_v) || !isfinite(self->pre_v) ||
        !isfinite(self->scale) || !isfinite(self->offset)) {
        self->current = 0.0;
    } else {
        double scale = self->scale;
        double offset_mv = self->offset * 1000.0;
        if (fabs(scale) < 1e-15) {
            scale = 1.0;
            offset_mv = 0.0;
        }
        if (fabs(scale) > 1e6) scale = (scale > 0.0) ? 1e6 : -1e6;
        if (fabs(offset_mv) > 1e6) offset_mv = (offset_mv > 0.0) ? 1e6 : -1e6;
        self->current = self->g_us * ((self->post_v * 1000.0) - ((self->pre_v * 1000.0 * scale) + offset_mv));
        clamp_f64(&self->current, 0.0);
    }
    (void)context->api->write(context, RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_CURRENT_NA, &self->current);
    return RTSYN_ABI_STATUS_OK;

}
