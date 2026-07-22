#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL_scancode.h>
#include <stdbool.h>

typedef struct {
    const bool* sdl_keys;             // Live pointer from SDL (borrowed)
    bool current[SDL_SCANCODE_COUNT]; // Your snapshot
    bool previous[SDL_SCANCODE_COUNT];
} InputState;

void input_init(InputState* input_state);
void input_update(InputState* input_state);
bool input_is_just_pressed(const InputState* input_state, int scancode);
bool input_is_just_released(const InputState* input_state, int scancode);

#endif