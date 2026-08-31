#include <stddef.h>
        #include "rtsyn/rthybrid_electrical_synapse.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/create.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/destroy.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/process.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/read_state.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/set_param.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/start.h"
        #include "rtsyn/internal/rthybrid_electrical_synapse/stop.h"

        static const rtsyn_abi_port_descriptor_t rtsyn_rthybrid_electrical_synapse_ports[RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_COUNT] = {
            [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_POST_SYNAPTIC_VOLTAGE_V] =
        {
            .name = "post_synaptic_voltage_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_PRE_SYNAPTIC_VOLTAGE_V] =
        {
            .name = "pre_synaptic_voltage_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_SCALE_PRE_TO_POST] =
        {
            .name = "scale_pre_to_post",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_OFFSET_PRE_TO_POST] =
        {
            .name = "offset_pre_to_post",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_CURRENT_NA] =
        {
            .name = "current_na",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
        };

        static const rtsyn_abi_param_descriptor_t rtsyn_rthybrid_electrical_synapse_params[RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_COUNT] = {
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_G_US] =
        {
            .name = "g_us",
            .description = "Conductance in micro-siemens",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_state_descriptor_t rtsyn_rthybrid_electrical_synapse_states[RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_COUNT] = {
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_POST_V] =
        {
            .name = "post_v",
            .description = "Post-synaptic voltage",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_PRE_V] =
        {
            .name = "pre_v",
            .description = "Pre-synaptic voltage",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_SCALE] =
        {
            .name = "scale",
            .description = "Pre-to-post scale",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_OFFSET] =
        {
            .name = "offset",
            .description = "Pre-to-post offset",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_G_US] =
        {
            .name = "g_us",
            .description = "Conductance in micro-siemens",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_CURRENT] =
        {
            .name = "current",
            .description = "Output current",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_node_descriptor_t rtsyn_rthybrid_electrical_synapse_descriptor = {
            .name = "rthybrid_electrical_synapse",
            .node_type = RTSYN_ABI_NODE_PLUGIN,
            .port_count = RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_COUNT,
            .ports = rtsyn_rthybrid_electrical_synapse_ports,
            .param_count = RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_COUNT,
            .params = rtsyn_rthybrid_electrical_synapse_params,
            .state_count = RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_COUNT,
            .states = rtsyn_rthybrid_electrical_synapse_states,
            .callbacks = {
                .create = rtsyn_rthybrid_electrical_synapse_create,
                .set_param = rtsyn_rthybrid_electrical_synapse_set_param,
                .read_state = rtsyn_rthybrid_electrical_synapse_read_state,
                .start = rtsyn_rthybrid_electrical_synapse_start,
                .process = rtsyn_rthybrid_electrical_synapse_process,
                .stop = rtsyn_rthybrid_electrical_synapse_stop,
                .destroy = rtsyn_rthybrid_electrical_synapse_destroy,
            },
        };

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_rthybrid_electrical_synapse_get_descriptor(void)
        {
            return &rtsyn_rthybrid_electrical_synapse_descriptor;
        }

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_module_get_descriptor(void)
        {
            return rtsyn_rthybrid_electrical_synapse_get_descriptor();
        }
