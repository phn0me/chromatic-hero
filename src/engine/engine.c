#include "engine.h"
#include <stdio.h>

Uint64 last_tick = 0;
Uint64 current_tick = 0;
float delta_time = 0.0F;
void engine_update(void)
{
    last_tick = current_tick;
    current_tick = SDL_GetTicks();
    delta_time = (current_tick - last_tick) / 1000.0F;
    printf("\r%f", delta_time);
}

bool engine_init(Engine *engine, const char *title, int width, int height)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to init SDL: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(title, width, height,
                                     SDL_WINDOW_RESIZABLE,
                                     &engine->window, &engine->renderer)) {
        SDL_Log("Failed to create window/renderer: %s", SDL_GetError());
        return false;
    }

    SDL_SetRenderLogicalPresentation(engine->renderer, width, height,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);
    return true;
}

void engine_shutdown(Engine *engine)
{
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

SDL_Renderer *engine_get_renderer(const Engine *engine)
{
    return engine->renderer;
}
