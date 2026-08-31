/**
 * @file rtsyn/internal/rthybrid_electrical_synapse/set_param.h
 * @brief set_param callback declaration for RTHybrid Electrical Synapse.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_SET_PARAM_H
#define RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_SET_PARAM_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_set_param(void *instance, uint32_t param_index, const void *value);
#ifdef __cplusplus
}
#endif
#endif
