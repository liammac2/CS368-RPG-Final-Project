cmake_minimum_required(VERSION 3.6)
project(CS368FinalProject_RPG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Player.cpp Player.hpp Game.cpp Game.hpp Skill.cpp Skill.hpp Item.cpp Item.hpp Enemy.cpp Enemy.hpp Character.cpp Character.hpp Engine.cpp Engine.hpp TextureManager.cpp TextureManager.hpp Tile.cpp Tile.hpp)
add_executable(CS368FinalProject_RPG ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(CS368FinalProject_RPG ${SFML_LIBRARIES})
endif()