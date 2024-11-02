/**
 * @file maze.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Maze class
 * @version 1.0
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/maze.h"

#include <fstream>
#include <string>
namespace s21 {

void Maze::loadFromFile(const std::string& filename) {
  std::ifstream is{filename};
  loadSize(is);
  loadVerticalWalls(is);
  loadHorizontalWalls(is);
}

void Maze::loadSize(std::istream& is) {
  is >> rows_ >> cols_;

  v_walls_.resize(rows_, WallVector(cols_));
  h_walls_.resize(rows_, WallVector(cols_));
}
void Maze::loadVerticalWalls(std::istream& is) {
  for (unsigned i = 0; i < rows_; ++i) {
    for (unsigned j = 0; j < cols_; ++j) {
      unsigned wall_value;
      is >> wall_value;
      v_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void Maze::loadHorizontalWalls(std::istream& is) {
  for (unsigned i = 0; i < rows_; ++i) {
    for (unsigned j = 0; j < cols_; ++j) {
      unsigned wall_value;
      is >> wall_value;
      h_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}
}  // namespace s21
