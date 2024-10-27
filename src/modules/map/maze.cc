/**
 * @file maze.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Maze class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/map/maze.h"

#include <iostream>

namespace s21 {
void Maze::loadFromStream(std::istream& is) {
  loadSize(is);
  loadVerticalWalls(is);
  loadHorizontalWalls(is);
}

void Maze::saveToStream(std::ostream& os) const {
  saveSize(os);
  saveVerticalWalls(os);
  saveHorizontalWalls(os);
}

void Maze::print() const {
  printTopBorder();

  for (int row = 0; row < rows_; ++row) {
    printVerticalWalls(row);
    printHorizontalWalls(row);
  }
}

void Maze::loadSize(std::istream& is) {
  is >> rows_ >> cols_;

  vertical_walls_.resize(rows_, WallVector(cols_));
  horizontal_walls_.resize(rows_, WallVector(cols_));
}

void Maze::loadVerticalWalls(std::istream& is) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int wall_value;
      is >> wall_value;
      vertical_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void Maze::loadHorizontalWalls(std::istream& is) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int wall_value;
      is >> wall_value;
      horizontal_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void Maze::saveSize(std::ostream& os) const {
  os << rows_ << " " << cols_ << "\n";
}

void Maze::saveVerticalWalls(std::ostream& os) const {
  for (const auto& row : vertical_walls_) {
    for (const auto& col : row) {
      os << static_cast<int>(col) << " ";
    }
    os << "\n";
  }

  os << "\n";
}

void Maze::saveHorizontalWalls(std::ostream& os) const {
  for (const auto& row : horizontal_walls_) {
    for (const auto& col : row) {
      os << static_cast<int>(col) << " ";
    }
    os << "\n";
  }
}

void Maze::printTopBorder() const {
  for (int j = 0; j < cols_; ++j) {
    std::cout << "+---";
  }

  std::cout << "+" << std::endl;
}

void Maze::printVerticalWalls(int row) const {
  std::cout << "|";

  for (int col = 0; col < cols_; ++col) {
    std::cout << "   " << (vertical_walls_[row][col] ? "|" : " ");
  }

  std::cout << std::endl << "+";
}

void Maze::printHorizontalWalls(int row) const {
  for (int col = 0; col < cols_; ++col) {
    std::cout << (horizontal_walls_[row][col] ? "---+" : "   +");
  }

  std::cout << std::endl;
}
}  // namespace s21
