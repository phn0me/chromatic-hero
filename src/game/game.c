#include "game.h"
#include "engine.h"

bool game_init(Game* game, Engine* engine) {
    (void) engine;
    game->state = GAME_STATE_RUNNING;

    return true;
}

void game_update(Game* game, Engine* engine, double delta_time) {
    (void) engine;
    (void) delta_time;

    switch (game->state) {
        case GAME_STATE_RUNNING:
            break;
        case GAME_STATE_PAUSED:
            break;
        case GAME_STATE_NONE:
            break;
        case GAME_STATE_ENDING:
            break;
    }
}
