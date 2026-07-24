#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "engine.h"

typedef enum {
    GAME_STATE_RUNNING = 0,
    GAME_STATE_PAUSED,
    GAME_STATE_SHUTDOWN,
} GameState;

typedef struct {
    GameState state;
} Game;

bool game_init(Game* game, Engine* engine);

void game_update(Game* game, Engine* engine, double delta_time);

void process_input(Game* game);

void game_render(Game* game, Engine* engine, double delta_time);

void game_shutdown(Game* game); // ← Return type changed to void

#endif