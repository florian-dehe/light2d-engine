cmake_minimum_required(VERSION 3.10)

set(SRCS GuiWindow.cpp)
set(HDRS GuiWindow.h)

add_library(ui OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/ui)