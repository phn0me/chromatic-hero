#include "engine.h"
#include <SDL3/SDL_render.h>

void engine_update(Engine* engine) {
    engine->timer.last_tick = engine->timer.current_tick;
    engine->timer.current_tick = SDL_GetPerformanceCounter();
    engine->timer.delta_time = (double) (engine->timer.current_tick - engine->timer.last_tick) /
                               (double) engine->timer.frequency;
}

void engine_render(SDL_Renderer* renderer) {
    const double now = ((double) SDL_GetTicks()) / 1000.0;
    const float red = (float) (0.5 + 0.5 * SDL_sin(now));
    const float green = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const float blue = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));

    SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool engine_init(Engine* engine, const char* title, int width, int height) {
    memset(engine, 0, sizeof(Engine));
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
    SDL_SetRenderVSync(engine->renderer, 1);
    engine->timer.frequency = SDL_GetPerformanceFrequency();
    engine->timer.current_tick = SDL_GetPerformanceCounter();

    return true;
}

bool engine_shutdown(Engine* engine) {
    if (engine->renderer) {
        SDL_DestroyRenderer(engine->renderer);
        engine->renderer = NULL;
    }
    if (engine->window) {
        SDL_DestroyWindow(engine->window);
        engine->window = NULL;
    }
    return true;
}

SDL_Renderer* engine_get_renderer(const Engine* engine) {
    return engine->renderer;
}
