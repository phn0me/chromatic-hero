#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct Engine {
    SDL_Window   *window;
    SDL_Renderer *renderer;
} Engine;

bool           engine_init(Engine *engine, const char *title, int width, int height);
void           engine_shutdown(Engine *engine);
SDL_Renderer  *engine_get_renderer(const Engine *engine);
