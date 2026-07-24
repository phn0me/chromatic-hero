#include "game.h"
#include <stdio.h>

bool game_init(Game* game, Engine* engine) {
    (void) game;
    (void) engine;
    return true;
}

void process_input(Game* game) {
    const bool* key_state = SDL_GetKeyboardState(NULL);
    if (key_state[SDL_SCANCODE_ESCAPE]) {
        game->state = GAME_STATE_SHUTDOWN;
    }
}

void game_update(Game* game, Engine* engine, double delta_time) {
    (void) engine;
    (void) delta_time;
    // Switch statement kept for future expansion
    switch (game->state) {
        case GAME_STATE_RUNNING:
            break;
        case GAME_STATE_PAUSED:
            break;
        case GAME_STATE_SHUTDOWN:
            break;
    }
}

void game_shutdown(Game* game) {
    (void) game;
    // Add cleanup here later
}

// Stub for render (you'll implement this in Issue 0x5)
void game_render(Game* game, Engine* engine, double delta_time) {
    (void) game;
    (void) engine;
    (void) delta_time;
}