#include <stdint.h>
typedef enum {
    GAME_STATE_NONE = 0,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSED,
    GAME_STATE_ENDING
} GameState;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

} Color;
