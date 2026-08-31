/**
 * @file rtsyn/internal/rthybrid_electrical_synapse/create.h
 * @brief create callback declaration for RTHybrid Electrical Synapse.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_CREATE_H
#define RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_CREATE_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_create(void **out_instance);
#ifdef __cplusplus
}
#endif
#endif
