#include <math.h>
#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/set_param.h"
static double finite_or(double value, double fallback) { return isfinite(value) ? value : fallback; }
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_set_param(void *instance, uint32_t param_index, const void *value)
{
    rtsyn_rthybrid_electrical_synapse_instance_t *self = (rtsyn_rthybrid_electrical_synapse_instance_t *)instance;
    if (!self || !value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    switch (param_index) {
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_G_US:
        self->g_us = isfinite(*(const double *)value) ? *(const double *)value : 0.0;
        return RTSYN_ABI_STATUS_OK;
    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

}
