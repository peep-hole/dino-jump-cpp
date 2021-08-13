cmake_minimum_required(VERSION 3.19)
project(sfml_proj)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Game.h Game.cpp GameObject.cpp GameObject.h)

add_executable(sfml_proj ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(sfml_proj ${SFML_LIBRARIES})
endif()

