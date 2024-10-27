cmake_minimum_required(VERSION 3.5)

project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FACTORY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../modules/factory)
set(FILE_HANDLER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../modules/file_handler)
set(MAP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../modules/map)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(INCLUDE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

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

set(TEST_HEADERS
  ${INCLUDE_TEST_DIR}/main_test.h
  ${INCLUDE_TEST_DIR}/maze_test.h
)

set(TEST_SOURCES
  ${TEST_SOURCE_DIR}/maze_test.cc
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(MAIN
  ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cc
)

add_executable(${PROJECT_NAME}
  ${TEST_SOURCES}
  ${FACTORY}
  ${FILE_HANDLER}
  ${MAP}
  ${TEST_HEADERS}
  ${HEADERS}
  ${MAIN}
)

include_directories(${CMAKE_SOURCE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g -fprofile-arcs -ftest-coverage)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread gcov)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/..
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
