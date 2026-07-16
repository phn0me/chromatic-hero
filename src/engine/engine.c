#include "engine.h"
#include <SDL3/SDL_keyboard.h>
#include "input.h"
void engine_update(Engine* engine) {
    engine->timer.last_tick = engine->timer.current_tick;
    engine->timer.current_tick = SDL_GetPerformanceCounter();
    engine->timer.delta_time = (double) (engine->timer.current_tick - engine->timer.last_tick) /
                               (double) engine->timer.frequency;
    input_update(&engine->input_state);
}

bool engine_init(Engine* engine, const char* title, int width, int height) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to init SDL: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_RESIZABLE, &engine->window,
                                     &engine->renderer)) {
        SDL_Log("Failed to create window/renderer: %s", SDL_GetError());
        return false;
    }

    SDL_SetRenderLogicalPresentation(engine->renderer, width, height,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);

    engine->timer.frequency = SDL_GetPerformanceFrequency();
    engine->timer.current_tick = SDL_GetPerformanceCounter();

    input_init(&engine->input_state);
    return true;
}

void engine_shutdown(Engine* engine) {
    if (engine->renderer) {
        SDL_DestroyRenderer(engine->renderer);
        engine->renderer = NULL;
    }
    if (engine->window) {
        SDL_DestroyWindow(engine->window);
        engine->window = NULL;
    }
    SDL_Quit();
}

SDL_Renderer* engine_get_renderer(const Engine* engine) {
    return engine->renderer;
}
