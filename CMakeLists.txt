cmake_minimum_required(VERSION 3.8)
project(paint)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c canvas.c canvas.h command.c command.h inputValidation.c inputValidation.h draw.c draw.h lineMod.c lineMod.h)

add_executable(paint ${SOURCE_FILES})