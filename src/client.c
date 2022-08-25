#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL.h>
#include <GLES2/gl2.h>

#include "nvgr_client.h"

static SDL_Event event;
static SDL_Window *window;
static FILE *file;
static bool quit;

static void update()
{
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      quit = true;
      break;
    default:
      break;
    }
  }
  quit = !nvgr_client_draw_next(file);
  SDL_Delay(40);
  SDL_GL_SwapWindow(window);
}

int main(int argc, char *argv[])
{

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_SetHint(SDL_HINT_OPENGL_ES_DRIVER, "1");
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  window = SDL_CreateWindow("NVG Remote", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  assert(window != NULL);

  SDL_GLContext *context = SDL_GL_CreateContext(window);
  assert(context != NULL);

  SDL_GL_SetSwapInterval(0);

  nvgr_client_init();

  file = fopen("draw.nvg", "rb");

  glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  // #ifdef EMSCRIPTEN
  //   SST_CALL_TERM(sst_web_init(&State))
  //   emscripten_set_main_loop(update, 0, 1);
  // #else
  while (!quit)
  {
    update();
  }
  // #endif

  fclose(file);
}