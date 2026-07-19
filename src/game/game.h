#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include "engine.h"
typedef enum {
    GAME_STATE_NONE = 0,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_ENDING
} GameState;

typedef struct {
    GameState state;
} Game;

bool init_game(Game* game, Engine* engine);
void update_game(Game* game, Engine* engine, float delta_time);
#endif
