/**
     * @file rtsyn/internal/rthybrid_electrical_synapse.h
     * @brief Internal state for the RTHybrid Electrical Synapse module.
     *
     * SPDX-License-Identifier: GPL-3.0-or-later
     */
    #ifndef RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_H
    #define RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_H

    #include <stddef.h>
    #include <stdint.h>

    #ifdef __cplusplus
    extern "C" {
    #endif

    typedef struct rtsyn_rthybrid_electrical_synapse_instance_s {
        double g_us;
double post_v;
double pre_v;
double scale;
double offset;
double current;
    } rtsyn_rthybrid_electrical_synapse_instance_t;

    typedef enum rtsyn_rthybrid_electrical_synapse_instance_ports_e : uint32_t {
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_POST_SYNAPTIC_VOLTAGE_V = 0,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_PRE_SYNAPTIC_VOLTAGE_V = 1,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_SCALE_PRE_TO_POST = 2,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_OFFSET_PRE_TO_POST = 3,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_CURRENT_NA = 4,
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PORT_COUNT = 5,
    } rtsyn_rthybrid_electrical_synapse_instance_ports_t;

    typedef enum rtsyn_rthybrid_electrical_synapse_instance_params_e : uint32_t {
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_G_US = 0,
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_PARAM_COUNT = 1,
    } rtsyn_rthybrid_electrical_synapse_instance_params_t;

    typedef enum rtsyn_rthybrid_electrical_synapse_instance_states_e : uint32_t {
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_POST_V = 0,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_PRE_V = 1,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_SCALE = 2,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_OFFSET = 3,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_G_US = 4,
RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_CURRENT = 5,
        RTSYN_RTHYBRID_ELECTRICAL_SYNAPSE_STATE_COUNT = 6,
    } rtsyn_rthybrid_electrical_synapse_instance_states_t;

    #ifdef __cplusplus
    }
    #endif

    #endif /* RTSYN_INTERNAL_RTHYBRID_ELECTRICAL_SYNAPSE_H */
