/**
 * @file rtsyn/internal/rthybrid_electrical_synapse/start.h
 * @brief start callback declaration for RTHybrid Electrical Synapse.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_START_H
#define RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_START_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_start(void *instance);
#ifdef __cplusplus
}
#endif
#endif
