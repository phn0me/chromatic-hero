#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_stdinc.h>
#include <stdbool.h>

typedef struct Timer {
    Uint64    frequency;
    Uint64    last_tick;
    Uint64    current_tick;
    double     delta_time;
} Timer;

typedef struct Engine {
    SDL_Window   *window;
    SDL_Renderer *renderer;
    Timer        timer;
} Engine;

bool           engine_init(Engine *engine, const char *title, int width, int height);
void           engine_shutdown(Engine *engine);
SDL_Renderer  *engine_get_renderer(const Engine *engine);
void           engine_update(Engine *engine);
