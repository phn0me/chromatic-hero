#pragma once

#include <SDL3/SDL_scancode.h>

typedef struct InputState {
    const bool *current;
    bool *previous[SDL_SCANCODE_COUNT];
} InputState;

void input_init(InputState *input_state);
void input_update(InputState *input_state);
