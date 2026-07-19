#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include "engine.h"

#include <stdbool.h>
typedef enum {
    GAME_STATE_NONE = 0,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_ENDING,
} GameState;

typedef struct {
    GameState state;
} Game;

bool game_init(Game* game, Engine* engine);
void game_update(Game* game, Engine* engine, double delta_time);
void game_render(Game* game, Engine* engine, double delta_time );
void game_destroy(Game* game);
#endif
