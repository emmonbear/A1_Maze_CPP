cmake_minimum_required(VERSION 3.5)

project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODEL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../model/)
set(CONTROLLER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../controller/)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include/)
set(INCLUDE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

set(MODEL
  ${MODEL_DIR}/file_handler.cc
  ${MODEL_DIR}/maze_generator.cc
  ${MODEL_DIR}/maze_solver.cc
  ${MODEL_DIR}/maze.cc
)

set(CONTROLLER
  ${CONTROLLER_DIR}/maze_facade.cc
)

set(HEADERS
  ${INCLUDE_DIR}/model/file_handler.h
  ${INCLUDE_DIR}/model/maze_generator.h
  ${INCLUDE_DIR}/model/maze_solver.h
  ${INCLUDE_DIR}/model/maze.h
  ${INCLUDE_DIR}/controller/maze_facade.h

)

set(TEST_HEADERS
  ${INCLUDE_TEST_DIR}/main_test.h
)

set(TEST_SOURCES
  ${TEST_SOURCE_DIR}/maze_load_test.cc
  ${TEST_SOURCE_DIR}/maze_save_test.cc
  ${TEST_SOURCE_DIR}/maze_generator_test.cc
  ${TEST_SOURCE_DIR}/maze_solver_test.cc
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(MAIN
  ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cc
)

add_executable(${PROJECT_NAME}
  ${TEST_SOURCES}
  ${CONTROLLER}
  ${MODEL}
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
