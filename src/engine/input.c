#include <SDL3/SDL_scancode.h>
#include <input.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_keycode.h>
#include <stdio.h>

void input_init(InputState *input_state) {
 SDL_ResetKeyboard();
 input_state->current = SDL_GetKeyboardState(NULL);
}

void input_update(InputState *input_state) {
    input_state->current = SDL_GetKeyboardState(NULL);

    if (!input_state->current[SDL_SCANCODE_W] && input_state->previous[SDL_SCANCODE_W]) {
        printf("W Just released\n");
    }

    if (input_state->current[SDL_SCANCODE_W] && !input_state->previous[SDL_SCANCODE_W]) {
        printf("W Just pressed\n");
    }

    memcpy(input_state->previous, input_state->current, SDL_SCANCODE_COUNT);
}
