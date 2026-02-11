#include "rthybrid_electrical_synapse_c.h"
#include <math.h>
#include <string.h>

static int key_eq(const char *key, size_t len, const char *lit) {
  size_t n = strlen(lit);
  return (len == n) && (strncmp(key, lit, n) == 0);
}

void rthybrid_electrical_synapse_c_init(rthybrid_electrical_synapse_c_state_t *s) {
  s->g_us = 0.0;
  s->post_v = 0.0;
  s->pre_v = 0.0;
  s->scale = 0.0;
  s->offset = 0.0;
  s->current = 0.0;
}

void rthybrid_electrical_synapse_c_set_config(rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len, double v) {
  if (!isfinite(v)) return;
  if (key_eq(key, len, "g (uS)") || key_eq(key, len, "g (\xC2\xB5S)") ||
      key_eq(key, len, "g (microS)") || key_eq(key, len, "g") ||
      key_eq(key, len, "g_us") || key_eq(key, len, "g_gap")) {
    s->g_us = v;
  } else if (key_eq(key, len, "g (nS)")) {
    s->g_us = v / 1000.0;
  }
}

void rthybrid_electrical_synapse_c_set_input(rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len, double v) {
  if (!isfinite(v)) return;
  if (key_eq(key, len, "Post-synaptic Voltage (V)") || key_eq(key, len, "in_0")) {
    s->post_v = v;
  } else if (key_eq(key, len, "Pre-synaptic Voltage (V)") || key_eq(key, len, "in_1")) {
    s->pre_v = v;
  } else if (key_eq(key, len, "Scale (Pre to Post)") || key_eq(key, len, "in_2")) {
    s->scale = v;
  } else if (key_eq(key, len, "Offset (Pre to Post)") || key_eq(key, len, "in_3")) {
    s->offset = v;
  }
}

void rthybrid_electrical_synapse_c_process(rthybrid_electrical_synapse_c_state_t *s) {
  if (!isfinite(s->g_us) || !isfinite(s->post_v) || !isfinite(s->pre_v) ||
      !isfinite(s->scale) || !isfinite(s->offset)) {
    s->current = 0.0;
    return;
  }
  double scale = s->scale;
  double offset_mv = s->offset * 1000.0;
  if (fabs(scale) < 1e-15) {
    scale = 1.0;
    offset_mv = 0.0;
  }
  if (fabs(scale) > 1e6) scale = (scale > 0.0) ? 1e6 : -1e6;
  if (fabs(offset_mv) > 1e6) offset_mv = (offset_mv > 0.0) ? 1e6 : -1e6;
  
  double v_post_mv = s->post_v * 1000.0;
  double v_pre_mv = s->pre_v * 1000.0 * scale + offset_mv;
  s->current = s->g_us * (v_post_mv - v_pre_mv);
  if (!isfinite(s->current)) s->current = 0.0;
  if (fabs(s->current) > 1e6) s->current = (s->current > 0.0) ? 1e6 : -1e6;
}

double rthybrid_electrical_synapse_c_get_output(const rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len) {
  if (key_eq(key, len, "Current (nA)") || key_eq(key, len, "out")) return s->current;
  return 0.0;
}
