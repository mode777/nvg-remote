#ifndef NVGR_SERVER_H
#define NVGR_SERVER_H

#include <stdio.h>

#include <nanovg.h>

NVGcontext* nvgCreateRemote(FILE* f);

#endif