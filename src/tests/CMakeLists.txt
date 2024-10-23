cmake_minimum_required(VERSION 3.5)

project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/modules/maze_test.cc
)

set(PROJECT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/../modules/maze.cc
)

set(MAIN
  ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cc
)

add_executable(${PROJECT_NAME}
  ${TEST_SOURCES}
  ${PROJECT_SOURCES}
  ${MAIN}
)

include_directories(${CMAKE_SOURCE_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -g)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/..
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
