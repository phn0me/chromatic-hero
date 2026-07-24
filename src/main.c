#include "game.h"
#include "engine.h"
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Engine engine;
    Game game;

    if (!engine_init(&engine, "Chromatic Abberation", 640, 480)) {
        return 1;
    }
    if (!game_init(&game, &engine)) {
        return 1;
    }
    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        process_input(&game, &event);
        game_update(&game, &engine, engine.timer.delta_time);
        engine_update(&engine);
        engine_render(engine.renderer);
        if (game.state == GAME_STATE_SHUTDOWN) {
            running = false;
        }
    }

    engine_shutdown(&engine);
    SDL_Quit();

    return 0;
}