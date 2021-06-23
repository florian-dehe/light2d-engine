cmake_minimum_required(VERSION 3.10)

set(SRCS FileReader.cpp)

set(HDRS FileReader.h)

add_library(utils OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/utils)
