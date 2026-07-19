#include "input.h"

#include <SDL3/SDL_keyboard.h>

void input_init(InputState* input_state) {
    input_state->current = SDL_GetKeyboardState(NULL);
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    memset(input_state->previous, 0, sizeof(input_state->previous));
}

void input_update(InputState* input_state) {
    // Update current state from SDL
    input_state->current = SDL_GetKeyboardState(NULL);

    // Swap: copy current → previous for next frame
    // NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    memcpy(input_state->previous, input_state->current, sizeof(input_state->previous));
}

bool input_is_just_pressed(const InputState* input_state, int scancode) {
    return input_state->current[scancode] && !input_state->previous[scancode];
}

bool input_is_just_released(const InputState* input_state, int scancode) {
    return !input_state->current[scancode] && input_state->previous[scancode];
}