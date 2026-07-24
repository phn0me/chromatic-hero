#ifndef GAME_H
#define GAME_H

#include "engine.h"

#include <stdbool.h>
typedef enum {
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_SHUTDOWN,
} GameState;

typedef struct {
    GameState state;
} Game;

bool game_init(Game* game, Engine* engine);
void game_update(Game* game, Engine* engine, double delta_time);
void process_input(Game *game); //Add SDL_Event *event later on to handle the events.
void game_render(Game* game, Engine* engine, double delta_time );
bool game_shutdown(Game* game);

#endif