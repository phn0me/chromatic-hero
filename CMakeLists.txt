cmake_minimum_required(VERSION 4.3)
project(chromatic_aberration C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build type defaults to Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler flags
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -Wconversion -Wshadow -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

# Find SDL3
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

# Executable
add_executable(chromatic_abberation
        src/main.c
        src/engine/engine.c
        src/game/game.c
)

# Include directories
target_include_directories(chromatic_abberation PRIVATE
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/engine
        ${PROJECT_SOURCE_DIR}/src/game
)

# Link SDL3 and sanitizers
target_link_libraries(chromatic_abberation PRIVATE PkgConfig::SDL3)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_options(chromatic_abberation PRIVATE
            -fsanitize=address,undefined
    )
endif()