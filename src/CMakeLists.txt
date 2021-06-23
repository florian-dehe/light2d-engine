cmake_minimum_required(VERSION 3.10)

set(CMAKE_POSITION_INDEPENDENT_CODE true)

project(Light2DEngine VERSION 0.1)

option(BUILD_SHARED_LIBS "Build shared library" ON) 

add_subdirectory(core)
add_subdirectory(core_graphics)
add_subdirectory(utils)
add_subdirectory(input)
add_subdirectory(rendering)
add_subdirectory(game_objects)
add_subdirectory(third_party)
add_subdirectory(materials)
add_subdirectory(ui)
add_subdirectory(audio)

##### Loading Libraries
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(PkgConfig REQUIRED)

find_package(OpenGL REQUIRED)

pkg_check_modules(GLEW glew REQUIRED IMPORTED_TARGET)
pkg_check_modules(GLFW glfw3 REQUIRED IMPORTED_TARGET)

set(LIBS ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})

set(LIBS_MODULES    $<TARGET_OBJECTS:core>
                    $<TARGET_OBJECTS:core_graphics>
                    $<TARGET_OBJECTS:utils>
                    $<TARGET_OBJECTS:input>
                    $<TARGET_OBJECTS:rendering>
                    $<TARGET_OBJECTS:game_objects>
                    $<TARGET_OBJECTS:third_party>
                    $<TARGET_OBJECTS:imgui>
                    $<TARGET_OBJECTS:materials>
                    $<TARGET_OBJECTS:ui>
                    $<TARGET_OBJECTS:audio>)

#### Target
add_library(light2d ${LIBS_MODULES})
target_link_libraries(light2d PUBLIC ${LIBS})
if(WIN32)
  target_link_libraries(light2d PUBLIC imm32)
endif()

target_link_directories(light2d  PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/lib/>)
if (WIN32)
    target_link_libraries(light2d PRIVATE soloud_static64)
    target_link_libraries(light2d PUBLIC winmm)
else()
    target_link_libraries(light2d PRIVATE soloud_static)
    target_link_libraries(light2d PUBLIC asound)
endif()

### Install
install(TARGETS light2d DESTINATION lib EXPORT light2dTargets)
install(FILES "light2d.h" DESTINATION include/light2d)
if (WIN32)
    install(FILES "../lib/libsoloud_static64.a" DESTINATION bin)
endif()

### CMake packaging
install(EXPORT light2dTargets FILE light2dTargets.cmake DESTINATION lib/cmake/light2d)

include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/light2dConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/light2d"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/light2dConfigVersion.cmake"
  VERSION "${Light2DEngine_VERSION_MAJOR}.${Light2DEngine_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/light2dConfig.cmake DESTINATION lib/cmake/light2d)

# Exporting the targets
export(EXPORT light2dTargets  FILE "${CMAKE_CURRENT_BINARY_DIR}/light2DTargets.cmake")
