CC := clang
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -O0 -g3 -fsanitize=address,undefined
LIBS := $(shell pkg-config --libs sdl3)
TARGET := chromatic_hero_debug

all: debug

debug: main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: all debug run clean
