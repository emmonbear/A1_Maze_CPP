cmake_minimum_required(VERSION 3.5)

project(maze VERSION 2.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FACTORY_DIR ${CMAKE_SOURCE_DIR}/modules/factory)
set(FILE_HANDLER_DIR ${CMAKE_SOURCE_DIR}/modules/file_handler)
set(MAP_DIR ${CMAKE_SOURCE_DIR}/modules/map)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(FACTORY
  ${FACTORY_DIR}/cave_creator.cc
  ${FACTORY_DIR}/creator.cc
  ${FACTORY_DIR}/maze_creator.cc
)

set(FILE_HANDLER
  ${FILE_HANDLER_DIR}/file_handler.cc
)

set(MAP
  ${MAP_DIR}/cave.cc
  ${MAP_DIR}/maze.cc
)
set(HEADERS
  ${INCLUDE_DIR}/factory/cave_creator.h
  ${INCLUDE_DIR}/factory/creator.h
  ${INCLUDE_DIR}/factory/maze_creator.h
  ${INCLUDE_DIR}/file_handler/file_handler.h
  ${INCLUDE_DIR}/map/cave.h
  ${INCLUDE_DIR}/map/map.h
  ${INCLUDE_DIR}/map/maze.h
)

set(MAIN
  ${CMAKE_SOURCE_DIR}/maze.cc
)

set(PROJECT_SOURCES
  ${FACTORY}
  ${FILE_HANDLER}
  ${MAP}
  ${HEADERS}
  ${MAIN}
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

# qt_finalize_executable(${PROJECT_NAME})

# enable_testing()
# add_subdirectory(tests)