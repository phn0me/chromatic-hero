#ifndef GAME_H
#define GAME_H

#include <stdint.h>
typedef enum {
    GAME_STATE_NONE = 0,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_ENDING
} GameState;

#endif
