CC := clang
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -O0 -g3 -fsanitize=address,undefined
LIBS := $(shell pkg-config --libs sdl3)

SRCS := src/main.c src/engine/engine.c src/engine/input.c
TARGET := chromatic_hero_debug

all: debug

debug: $(SRCS)
	$(CC) $(CFLAGS) -Isrc/engine -o $(TARGET) $(SRCS) $(LIBS)

run: debug
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all debug run clean
