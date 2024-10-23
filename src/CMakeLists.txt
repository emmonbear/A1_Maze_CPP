cmake_minimum_required(VERSION 3.5)

project(maze VERSION 2.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(MODULES
  ${MODULES_DIR}/maze.cc
)

set(HEADERS
  ${INCLUDE_DIR}/maze.h
)

set(MAIN
  ${CMAKE_SOURCE_DIR}/maze.cc
)

set(PROJECT_SOURCES
  ${MODULES}
  ${HEADERS}
  ${MAIN}
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -g)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

# qt_finalize_executable(${PROJECT_NAME})

# enable_testing()
# add_subdirectory(tests)