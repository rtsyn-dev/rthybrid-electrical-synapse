#include <stdlib.h>
#include "rtsyn/internal/rthybrid_electrical_synapse.h"
#include "rtsyn/internal/rthybrid_electrical_synapse/destroy.h"
void RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_destroy(void *instance)
{
    free((rtsyn_rthybrid_electrical_synapse_instance_t *)instance);
}
