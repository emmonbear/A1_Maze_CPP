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

void Maze::generate() {
  resize();
  initFirstRow();

  for (int row = 0; row < rows_ - 1; ++row) {
    setUnique();
    generateVerticalWalls(row);
    generateHorizontalWalls(row);
    prepareRowForGeneration(row);
  }
  checkEndLine();
  clearGenerator();
}

void Maze::initFirstRow() {
  for (int col = 0; col < cols_; ++col) {
    sets_.emplace_back(0);
  }
}

void Maze::setUnique() {
  for (int col = 0; col < cols_; ++col) {
    if (!sets_[col]) {
      sets_[col] = counter_;
      ++counter_;
    }
  }
}

bool Maze::randomBool() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);

  return dist(gen);
}

void Maze::createSet(int index, int element) {
  for (int col = 0; col < cols_; ++col) {
    if (sets_[col] == sets_[index + 1]) {
      sets_[col] = element;
    }
  }
}

bool Maze::isSingleElementInSet(int element) {
  int count{0};
  for (int col = 0; col < cols_; ++col) {
    if (sets_[col] == element) {
      count++;
    }
  }

  return count == 1;
}

int Maze::countHorizontalWalls(int row, int element) {
  int count{0};

  for (int col = 0; col < cols_; ++col) {
    if (sets_[col] == element && h_walls_[row][col] == false) {
      ++count;
    }
  }
  return count;
}

void Maze::avoidBottomWallIfIsolated(int row) {
  for (int col = 0; col < cols_; ++col) {
    if (countHorizontalWalls(row, sets_[col]) == 0) {
      h_walls_[row][col] = false;
    }
  }
}

void Maze::generateVerticalWalls(int row) {
  for (int col = 0; col < cols_ - 1; ++col) {
    bool choise = randomBool();
    if (choise || sets_[col] == sets_[col + 1]) {
      v_walls_[row][col] = true;
    } else {
      createSet(col, sets_[col]);
    }
  }

  v_walls_[row][cols_ - 1] = true;
}

void Maze::generateHorizontalWalls(int row) {
  for (int col = 0; col < cols_; ++col) {
    bool choise = randomBool();

    if (choise && !isSingleElementInSet(sets_[col])) {
      h_walls_[row][col] = true;
    }
  }

  avoidBottomWallIfIsolated(row);
}

void Maze::prepareRowForGeneration(int row) {
  for (int col = 0; col < cols_; ++col) {
    if (h_walls_[row][col]) {
      sets_[col] = 0;
    }
  }
}

void Maze::checkEndLine() {
  for (int col = 0; col < cols_ - 1; ++col) {
    if (sets_[col] != sets_[col + 1]) {
      v_walls_[rows_ - 1][col] = false;
      createSet(col, sets_[col]);
    }
    h_walls_[rows_ - 1][col] = true;
  }
  h_walls_[rows_ - 1][cols_ - 1] = true;
}

void Maze::generateLastRow() {
  setUnique();
  generateVerticalWalls(rows_ - 1);
}

void Maze::clearGenerator() {
  counter_ = 1;
  sets_.clear();
}

}  // namespace s21
