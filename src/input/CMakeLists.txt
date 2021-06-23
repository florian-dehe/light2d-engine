cmake_minimum_required(VERSION 3.10)

set(SRCS EventQueue.cpp InputManager.cpp Input.cpp)

set(HDRS Event.h EventQueue.h Input.h InputManager.h Key.h)

add_library(input OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/input)
