#pragma once
#include <SDL3/SDL_render.h>
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

typedef struct Engine {
    SDL_Window    *window;
    SDL_Renderer  *renderer;
} Engine;

typedef enum GameState {
    GAME_STATE_NONE = 0,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_ENDING
} GameState;
