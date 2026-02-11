#pragma once
#include <stddef.h>

typedef struct {
  double g_us;
  double post_v;
  double pre_v;
  double scale;
  double offset;
  double current;
} rthybrid_electrical_synapse_c_state_t;

void rthybrid_electrical_synapse_c_init(rthybrid_electrical_synapse_c_state_t *s);
void rthybrid_electrical_synapse_c_set_config(rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len, double v);
void rthybrid_electrical_synapse_c_set_input(rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len, double v);
void rthybrid_electrical_synapse_c_process(rthybrid_electrical_synapse_c_state_t *s);
double rthybrid_electrical_synapse_c_get_output(const rthybrid_electrical_synapse_c_state_t *s, const char *key, size_t len);
