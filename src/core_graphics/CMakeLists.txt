cmake_minimum_required(VERSION 3.10)

set(SRCS VertexArray.cpp VertexBuffer.cpp VertexBufferLayout.cpp Shader.cpp IndexBuffer.cpp Texture.cpp)

set(HDRS GraphicsBuffer.h VertexBufferAttribute.h VertexArray.h VertexBuffer.h VertexBufferLayout.h Shader.h IndexBuffer.h Texture.h)

add_library(core_graphics OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/core_graphics)