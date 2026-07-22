#include "input.h"

#include <stdio.h>
#include <SDL3/SDL_keyboard.h>

void input_init(InputState* input_state) {
    input_state->sdl_keys = SDL_GetKeyboardState(NULL);
    memset(input_state->current, 0, sizeof(input_state->current));
    memset(input_state->previous, 0, sizeof(input_state->previous));
}

void input_update(InputState* input_state) {
    // 1. Save last frame's snapshot
    memcpy(input_state->previous, input_state->current, sizeof(input_state->previous));

    // 2. Take new snapshot from SDL's live pointer
    memcpy(input_state->current, input_state->sdl_keys, sizeof(input_state->current));
}

bool input_is_just_pressed(const InputState* input_state, int scancode) {
    bool current_state = input_state->current[scancode];
    bool prev_state = input_state->previous[scancode];

    printf("JUST_PRESSED: scancode=%d, current=%d, previous=%d, result=%d\n",
           scancode, current_state, prev_state, current_state && !prev_state);

    return current_state && !prev_state;
}

bool input_is_just_released(const InputState* input_state, int scancode) {
    return !input_state->current[scancode] && input_state->previous[scancode];
}