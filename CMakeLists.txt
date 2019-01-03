cmake_minimum_required(VERSION 3.6)
project(main C)

set(CMAKE_C_STANDARD 99)

add_executable(main ./src/main.c ./src/game.c ./src/ui.c ./src/utils.c src/model.c)
