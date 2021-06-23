cmake_minimum_required(VERSION 3.10)

set(SRCS    imgui.cpp imgui_draw.cpp imgui_demo.cpp imgui_tables.cpp imgui_widgets.cpp
            imgui_impl_opengl3.cpp imgui_impl_glfw.cpp)

set(HDRS    imconfig.h imgui.h imgui_internal.h imstb_rectpack.h imstb_textedit.h imstb_truetype.h
            imgui_impl_opengl3.h imgui_impl_glfw.h)

add_library(imgui OBJECT ${SRCS})


install(FILES ${HDRS} DESTINATION include/light2d/third_party/imgui/)
