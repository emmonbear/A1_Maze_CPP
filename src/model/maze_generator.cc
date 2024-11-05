/**
 * @file maze_generator.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeGenerator class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/maze_generator.h"

#include <fstream>
#include <random>
#include <string>

namespace s21 {

void MazeGenerator::generate(Maze* maze) {
  maze_ = maze;
  initFirstRow();

  for (int row = 0; row < maze_->rows_ - 1; ++row) {
    setUnique();
    generateVerticalWalls(row);
    generateHorizontalWalls(row);
    prepareRowForGeneration(row);
  }
  generateLastRow();
  clearGenerator();
}

void MazeGenerator::initFirstRow() {
  for (int col = 0; col < maze_->cols_; ++col) {
    sets_.emplace_back(0);
  }
}

void MazeGenerator::setUnique() {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (!sets_[col]) {
      sets_[col] = counter_;
      ++counter_;
    }
  }
}

bool MazeGenerator::randomBool() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);

  return dist(gen);
}

void MazeGenerator::createSet(int index, int element) {
  int set = sets_[index + 1];
  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == set) {
      sets_[col] = element;
    }
  }
}

bool MazeGenerator::isSingleElementInSet(int element) {
  int count{0};

  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == element) {
      count++;
    }
  }

  return count == 1;
}

int MazeGenerator::countHorizontalWalls(int row, int element) {
  int count{0};

  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == element && maze_->h_walls_[row][col] == false) {
      ++count;
    }
  }
  return count;
}

void MazeGenerator::avoidBottomWallIfIsolated(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (countHorizontalWalls(row, sets_[col]) == 0) {
      maze_->h_walls_[row][col] = false;
    }
  }
}

void MazeGenerator::prepareRowForGeneration(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (maze_->h_walls_[row][col]) {
      sets_[col] = 0;
    }
  }
}
void MazeGenerator::generateVerticalWalls(int row) {
  for (int col = 0; col < maze_->cols_ - 1; ++col) {
    bool choise = randomBool();
    if (choise || sets_[col] == sets_[col + 1]) {
      maze_->v_walls_[row][col] = true;
    } else {
      createSet(col, sets_[col]);
    }
  }

  maze_->v_walls_[row][maze_->cols_ - 1] = true;
}

void MazeGenerator::generateHorizontalWalls(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    bool choise = randomBool();

    if (choise && !isSingleElementInSet(sets_[col])) {
      maze_->h_walls_[row][col] = true;
    }
  }

  avoidBottomWallIfIsolated(row);
}

void MazeGenerator::generateLastRow() {
  setUnique();
  generateVerticalWalls(maze_->rows_ - 1);
  checkEndLine();
}

void MazeGenerator::checkEndLine() {
  for (int col = 0; col < maze_->cols_ - 1; ++col) {
    if (sets_[col] != sets_[col + 1]) {
      maze_->v_walls_[maze_->rows_ - 1][col] = false;
      createSet(col, sets_[col]);
    }
    maze_->h_walls_[maze_->rows_ - 1][col] = true;
  }
  maze_->h_walls_[maze_->rows_ - 1][maze_->cols_ - 1] = true;
}

void MazeGenerator::clearGenerator() {
  counter_ = 1;
  sets_.clear();
}
}  // namespace s21
