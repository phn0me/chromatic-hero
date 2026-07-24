#include "game.h"

#include <stdio.h>

#include "engine.h"

bool game_init(Game* game, Engine* engine) {
    (void)game;
    (void)engine;
    //Do more init stuff.
    //Incase of implementing other stuff.
    return true;
}

void process_input(Game *game, SDL_Event *event) {
   const bool *key_state = SDL_GetKeyboardState(NULL);
    // Pump events (handles window close, input, etc.)
    (void)event;
    if (key_state[SDL_SCANCODE_ESCAPE]) {
        game->state = GAME_STATE_SHUTDOWN;
    }

}

void game_update(Game* game, Engine* engine, double delta_time) {
    (void)engine;
    (void)delta_time;

    switch (game->state) {
        case GAME_STATE_RUNNING:
            break;
        case GAME_STATE_PAUSED:
            break;
        case GAME_STATE_SHUTDOWN:
            break;
    }
}
