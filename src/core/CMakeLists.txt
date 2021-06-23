cmake_minimum_required(VERSION 3.10)

set(SRCS Application.cpp Window.cpp Logger.cpp)

set(HDRS Application.h Window.h Logger.h)

add_library(core OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/core)