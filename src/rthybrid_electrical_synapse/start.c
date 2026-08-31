#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/start.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_start(void *instance)
{
    return instance ? RTSYN_ABI_STATUS_OK : RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
