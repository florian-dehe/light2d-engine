cmake_minimum_required(VERSION 3.10)

set(SRCS stb/stb_image.cpp)
set(HDRS_STB stb/stb_image.h)

add_subdirectory(imgui)

add_library(third_party OBJECT ${SRCS})
target_link_libraries(third_party imgui)

install(FILES ${HDRS_STB} DESTINATION include/light2d/third_party/stb)
install(DIRECTORY soloud DESTINATION include/light2d/third_party)
