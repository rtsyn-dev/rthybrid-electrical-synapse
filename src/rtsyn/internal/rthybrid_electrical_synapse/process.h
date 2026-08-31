/**
 * @file rtsyn/internal/rthybrid_electrical_synapse/process.h
 * @brief process callback declaration for RTHybrid Electrical Synapse.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_PROCESS_H
#define RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_PROCESS_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_process(void *instance, const rtsyn_abi_runtime_context_t *context);
#ifdef __cplusplus
}
#endif
#endif
