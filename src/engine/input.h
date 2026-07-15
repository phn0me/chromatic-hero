#pragma once

#include <SDL3/SDL_scancode.h>

typedef struct InputState {
  const uint8_t *current;
  uint8_t        previous[SDL_SCANCODE_COUNT];
} InputState;
