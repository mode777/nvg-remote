#ifndef NVGR_CLIENT_H
#define NVGR_CLIENT_H

#include <stdbool.h>

void nvgr_client_init();
bool nvgr_client_draw_next(FILE* f);

#endif