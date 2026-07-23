#include "game.h"
#include "engine.h"
#include <stdio.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Engine engine;
    Game game;

    if (!engine_init(&engine, "Chromatic Aberration", 640, 480)) {
        return 1;
    }

    if (!game_init(&game, &engine)) {
        engine_shutdown(&engine);
        return 1;
    }

    while (game.state == GAME_STATE_RUNNING) {  // Ensure this matches enum!
        SDL_Event event;
        const bool *key_state = SDL_GetKeyboardState(NULL);

        // Pump events (handles window close, input, etc.)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                game.state = GAME_STATE_PAUSED;
            }
        }

        engine_update(&engine);  // Updates input_state BEFORE checking

        if (key_state[SDL_SCANCODE_ESCAPE]) {
            printf("ESCAPE pressed\n");
            game.state = GAME_STATE_PAUSED;
            break;  // Exit loop
        }

        engine_render(engine.renderer);
    }

    engine_shutdown(&engine);
    return 0;
}