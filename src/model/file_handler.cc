/**
 * @file file_handler.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the FileHandler class
 * @version 1.0
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/file_handler.h"

#include <fstream>
#include <string>

namespace s21 {

void FileHandler::load(Maze* maze, const std::string& filename) {
  std::ifstream is{filename};
  loadSize(maze, is);
  loadVerticalWalls(maze, is);
  loadHorizontalWalls(maze, is);
}

void FileHandler::save(const Maze& maze, const std::string& filename) {}

void FileHandler::loadSize(Maze* maze, std::istream& is) {
  is >> maze->rows_ >> maze->cols_;
  maze->resize();
}

void FileHandler::loadVerticalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->v_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void FileHandler::loadHorizontalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->h_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

}  // namespace s21
