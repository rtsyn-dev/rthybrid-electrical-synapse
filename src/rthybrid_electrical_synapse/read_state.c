#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/read_state.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    const rtsyn_rthybrid_electrical_synapse_instance_t *self = (const rtsyn_rthybrid_electrical_synapse_instance_t *)instance;
    if (!self || !out_value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    switch (state_index) {

    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_POST_V: *(double *)out_value = self->post_v; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_PRE_V: *(double *)out_value = self->pre_v; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_SCALE: *(double *)out_value = self->scale; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_OFFSET: *(double *)out_value = self->offset; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_G_US: *(double *)out_value = self->g_us; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_CURRENT: *(double *)out_value = self->current; return RTSYN_ABI_STATUS_OK;

    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
}
