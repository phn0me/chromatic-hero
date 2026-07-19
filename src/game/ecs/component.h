#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdint.h>
#include "vec2.h"

typedef struct {
    Vec2i value;
} Position;

typedef struct {
    Vec2f value;
} Velocity;

typedef struct {
    int16_t value;
} Health;
#endif
