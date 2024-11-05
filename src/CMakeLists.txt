cmake_minimum_required(VERSION 3.5)

project(maze VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

set(MODEL_DIR ${CMAKE_SOURCE_DIR}/model)
set(VIEW_DIR ${CMAKE_SOURCE_DIR}/view)
set(CONTROLLER_DIR ${CMAKE_SOURCE_DIR}/controller)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(MODEL
  ${MODEL_DIR}/maze.cc
  ${MODEL_DIR}/maze_generator.cc
  ${MODEL_DIR}/file_handler.cc
)

set(CONTROLLER
  ${CONTROLLER_DIR}/maze_facade.cc
)


set(VIEW
  ${VIEW_DIR}/main_window.cc
  ${VIEW_DIR}/cave_tab.cc
  ${VIEW_DIR}/maze_tab.cc
  ${VIEW_DIR}/maze_renderer.cc
)

set(HEADERS
  ${INCLUDE_DIR}/model/maze.h
  ${INCLUDE_DIR}/model/maze_generator.h
  ${INCLUDE_DIR}/model/file_handler.h
  ${INCLUDE_DIR}/controller/maze_facade.h
  ${INCLUDE_DIR}/view/cave_tab.h
  ${INCLUDE_DIR}/view/maze_tab.h
  ${INCLUDE_DIR}/view/settings.h
  ${INCLUDE_DIR}/view/main_window.h
  ${INCLUDE_DIR}/view/maze_renderer.h
  # ${INCLUDE_DIR}/
  # ${INCLUDE_DIR}/
  # ${INCLUDE_DIR}/
)

set(MAIN
  ${CMAKE_SOURCE_DIR}/main.cc
)

# set(RESOURCE
#   ${CMAKE_SOURCE_DIR}/resource/resource.qrc
# )

set(PROJECT_SOURCES
  ${VIEW}
  ${CONTROLLER}
  ${MODEL}
  ${HEADERS}
  ${MAIN}
  # ${RESOURCE}
  # ${FILE_HANDLER}
  # ${MAP}
  # ${VIEW_HEADERS}
)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)


# qt_finalize_executable(${PROJECT_NAME})

# enable_testing()
# add_subdirectory(tests)