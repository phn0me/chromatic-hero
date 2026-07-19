#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL_scancode.h>

typedef struct {
    const bool* current;
    bool previous[SDL_SCANCODE_COUNT];
} InputState;

void input_init(InputState* input_state);
void input_update(InputState* input_state);
void input_just_pressed(InputState* input_state);
void input_just_released(InputState* input_state);

#endif
