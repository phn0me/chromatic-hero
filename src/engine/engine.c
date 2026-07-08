#include "engine.h"

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
