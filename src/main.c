#include <SDL3/SDL_init.h>
#define SDL_MAIN_USE_CALLBACKS 1
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>

#include "engine.h"
#include "game.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    Engine* engine = calloc(1, sizeof(Engine));
    if (!engine) {
        SDL_Log("Failed to allocate Engine");
        return SDL_APP_FAILURE;
    }

    if (!engine_init(engine, "Chromatic Hero", 640, 480)) {
        free(engine);
        return SDL_APP_FAILURE;
    }

    Game* game = calloc(1, sizeof(Game));
    if (!game_init(game, engine)) {
        free(game);
        return SDL_APP_FAILURE;
    }

    *appstate = engine;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    (void) appstate;

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    Engine* engine = (Engine*) appstate;
    Game* game = (Game*)engine appstate;
    engine_update(engine);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    (void) result;

    Engine* engine = (Engine*) appstate;
    if (!engine) {
        return;
    }

    engine_shutdown(engine);
    free(engine);
}
