cmake_minimum_required(VERSION 3.10)

set(SRCS Audio.cpp)
set(HDRS Audio.h)

add_library(audio OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/audio)
