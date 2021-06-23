cmake_minimum_required(VERSION 3.10)

set(SRCS Camera.cpp Viewport.cpp Mesh.cpp Renderer.cpp Transform.cpp Material.cpp)

set(HDRS Camera.h Viewport.h Mesh.h Renderer.h Transform.h Material.h)

add_library(rendering OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/rendering)