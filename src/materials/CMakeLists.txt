cmake_minimum_required(VERSION 3.10)

set(SRCS SpriteMaterial.cpp)
set(HDRS SpriteMaterial.h)

add_library(materials OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/materials)
