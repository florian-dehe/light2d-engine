cmake_minimum_required(VERSION 3.10)

set(SRCS Sprite.cpp AnimatedSprite.cpp GameObjectGroup.cpp GameObjectGroup.h)

set(HDRS GameObject.h Sprite.h Scene.h AnimatedSprite.h)

add_library(game_objects OBJECT ${SRCS})

install(FILES ${HDRS} DESTINATION include/light2d/game_objects)
