#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <stdbool.h>
#include "input.h"

typedef struct {
    Uint64 frequency;
    Uint64 last_tick;
    Uint64 current_tick;
    double delta_time;
} Timer;

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    Timer timer;
    InputState input_state;
} Engine;

bool engine_init(Engine* engine, const char* title, int width, int height);
void engine_shutdown(Engine* engine);
SDL_Renderer* engine_get_renderer(const Engine* engine);
void engine_update(Engine* engine);
void engine_render(SDL_Renderer* renderer);

#endif
