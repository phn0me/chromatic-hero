#include <SDL3/SDL_scancode.h>
#include <input.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_keycode.h>
#include <stdio.h>

void init_inupt(InputState *input_state) {
 SDL_ResetKeyboard();
 input_state->current = SDL_GetKeyboardState(NULL);
}
void update_input(InputState *input_state) {
  input_state->current = SDL_GetKeyboardState(NULL);

  //do other stuffs later on, or something.


  if (input_state->current[SDL_SCANCODE_W]) {
    printf("W Pressed");
      }
}
