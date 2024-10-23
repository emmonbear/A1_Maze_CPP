/**
 * @file maze.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Maze class
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/maze.h"

#include <fstream>
#include <string>

namespace s21 {
void Maze::loadFromFile(const std::string& filename) {
  std::fstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open file.");
  }

  loadMazeSize(file);
  loadVerticalWalls(file);
  loadHorizontalWalls(file);
}

void Maze::loadMazeSize(std::fstream& file) {
  file >> rows_ >> cols_;

  vertical_walls_.resize(rows_, std::vector<int>(cols_));
  horizontal_walls_.resize(rows_, std::vector<int>(cols_));
}

void Maze::loadVerticalWalls(std::fstream& file) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      file >> vertical_walls_[i][j];
    }
  }
}

void Maze::loadHorizontalWalls(std::fstream& file) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      file >> horizontal_walls_[i][j];
    }
  }
}

}  // namespace s21
