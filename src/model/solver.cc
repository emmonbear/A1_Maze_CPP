/**
 * @file maze_solver.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeSolver class
 * @version 1.0
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/solver.h"

#include <stdexcept>
#include <string>

namespace s21 {

MazeSolver::MazeSolver(Maze* maze, Maze::Point start, Maze::Point end)
    : maze_{maze},
      start_{start},
      end_{end},
      visited_(maze_->rows_, Maze::WallVector(maze_->cols_, false)) {}

void MazeSolver::solve() {
  maze_->free_path();
  if (!dfs(start_.first, start_.second)) {
    throw std::runtime_error("No solution found for the maze.");
  }
}

bool MazeSolver::dfs(int row, int col) {
  if (row < 0 || row >= maze_->rows() || col < 0 || col >= maze_->cols() ||
      visited_[row][col]) {
    return false;
  }

  visited_[row][col] = true;

  if (row == end_.first && col == end_.second) {
    maze_->push_path(row, col);
    return true;
  }

  for (int i = 0; i < 4; ++i) {
    if (canMoveTo(row, col, directions[i])) {
      if (dfs(row + row_deltas[i], col + col_deltas[i])) {
        maze_->push_path(row, col);
        return true;
      }
    }
  }

  return false;
}

bool MazeSolver::canMoveTo(int row, int col, direction dir) {
  switch (dir) {
    case direction::kLeft:
      return col > 0 && !maze_->v_walls_[row][col - 1];
    case direction::kRight:
      return col < maze_->cols() - 1 && !maze_->v_walls_[row][col];
    case direction::kUp:
      return row > 0 && !maze_->h_walls_[row - 1][col];
    case direction::kDown:
      return row < maze_->rows() - 1 && !maze_->h_walls_[row][col];
    default:
      return false;
  }
}

}  // namespace s21
