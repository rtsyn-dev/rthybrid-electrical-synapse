use rtsyn_plugin::prelude::*;
use serde_json::Value;
use std::mem::MaybeUninit;

#[repr(C)]
struct RthybridElectricalSynapseCState {
    g_us: f64,
    post_v: f64,
    pre_v: f64,
    scale: f64,
    offset: f64,
    current: f64,
}

unsafe extern "C" {
    fn rthybrid_electrical_synapse_c_init(state: *mut RthybridElectricalSynapseCState);
    fn rthybrid_electrical_synapse_c_set_config(
        state: *mut RthybridElectricalSynapseCState,
        key: *const u8,
        len: usize,
        value: f64,
    );
    fn rthybrid_electrical_synapse_c_set_input(
        state: *mut RthybridElectricalSynapseCState,
        key: *const u8,
        len: usize,
        value: f64,
    );
    fn rthybrid_electrical_synapse_c_process(state: *mut RthybridElectricalSynapseCState);
    fn rthybrid_electrical_synapse_c_get_output(
        state: *const RthybridElectricalSynapseCState,
        key: *const u8,
        len: usize,
    ) -> f64;
}

struct RthybridElectricalSynapseC {
    state: RthybridElectricalSynapseCState,
}

impl Default for RthybridElectricalSynapseC {
    fn default() -> Self {
        let mut state = MaybeUninit::<RthybridElectricalSynapseCState>::uninit();
        unsafe {
            rthybrid_electrical_synapse_c_init(state.as_mut_ptr());
            Self {
                state: state.assume_init(),
            }
        }
    }
}

impl PluginDescriptor for RthybridElectricalSynapseC {
    fn name() -> &'static str {
        "RTHybrid Electrical Synapse"
    }

    fn kind() -> &'static str {
        "rthybrid_electrical_synapse"
    }

    fn plugin_type() -> PluginType {
        PluginType::Standard
    }

    fn inputs() -> &'static [&'static str] {
        &[
            "Post-synaptic Voltage (V)",
            "Pre-synaptic Voltage (V)",
            "Scale (Pre to Post)",
            "Offset (Pre to Post)",
        ]
    }

    fn outputs() -> &'static [&'static str] {
        &["Current (nA)"]
    }

    fn internal_variables() -> &'static [&'static str] {
        &["post_v", "pre_v", "scale", "offset", "g_us", "current"]
    }

    fn default_vars() -> Vec<(&'static str, Value)> {
        vec![("g_us", 0.0.into())]
    }

    fn behavior() -> PluginBehavior {
        PluginBehavior {
            supports_start_stop: true,
            supports_restart: true,
            supports_apply: false,
            extendable_inputs: ExtendableInputs::None,
            loads_started: false,
            external_window: false,
            starts_expanded: true,
            start_requires_connected_inputs: Vec::new(),
            start_requires_connected_outputs: Vec::new(),
        }
    }
}

impl PluginRuntime for RthybridElectricalSynapseC {
    fn set_config_value(&mut self, key: &str, value: &Value) {
        if let Some(v) = value.as_f64() {
            unsafe { rthybrid_electrical_synapse_c_set_config(&mut self.state, key.as_ptr(), key.len(), v) };
        }
    }

    fn set_input_value(&mut self, key: &str, value: f64) {
        unsafe { rthybrid_electrical_synapse_c_set_input(&mut self.state, key.as_ptr(), key.len(), value) };
    }

    fn process_tick(&mut self, _tick: u64, _period_seconds: f64) {
        unsafe { rthybrid_electrical_synapse_c_process(&mut self.state) };
    }

    fn get_output_value(&self, key: &str) -> f64 {
        unsafe { rthybrid_electrical_synapse_c_get_output(&self.state, key.as_ptr(), key.len()) }
    }

    fn get_internal_value(&self, key: &str) -> Option<f64> {
        match key {
            "post_v" => Some(self.state.post_v),
            "pre_v" => Some(self.state.pre_v),
            "scale" => Some(self.state.scale),
            "offset" => Some(self.state.offset),
            "g_us" => Some(self.state.g_us),
            "current" => Some(self.state.current),
            _ => None,
        }
    }
}

rtsyn_plugin::export_plugin!(RthybridElectricalSynapseC);
