#include <math.h>
#include <stdlib.h>
#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/create.h"

rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_create(void **out_instance)
{
    if (!out_instance) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    rtsyn_rthybrid_electrical_synapse_instance_t *self = (rtsyn_rthybrid_electrical_synapse_instance_t *)malloc(sizeof(rtsyn_rthybrid_electrical_synapse_instance_t));
    if (!self) return RTSYN_ABI_STATUS_ERROR;

    self->g_us = 0.0;
    self->post_v = 0.0;
    self->pre_v = 0.0;
    self->scale = 0.0;
    self->offset = 0.0;
    self->current = 0.0;

    *out_instance = self;
    return RTSYN_ABI_STATUS_OK;
}
