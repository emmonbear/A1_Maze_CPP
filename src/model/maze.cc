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
#include <random>
#include <string>

namespace s21 {

void Maze::loadFromFile(const std::string& filename) {
  std::ifstream is{filename};
  loadSize(is);
  loadVerticalWalls(is);
  loadHorizontalWalls(is);
}

void Maze::resize() {
  v_walls_.clear();
  h_walls_.clear();
  v_walls_.resize(rows_, WallVector(cols_, false));
  h_walls_.resize(rows_, WallVector(cols_, false));
}

void Maze::loadSize(std::istream& is) {
  is >> rows_ >> cols_;
  resize();
}

void Maze::loadVerticalWalls(std::istream& is) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int wall_value;
      is >> wall_value;
      v_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void Maze::loadHorizontalWalls(std::istream& is) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int wall_value;
      is >> wall_value;
      h_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

}  // namespace s21
