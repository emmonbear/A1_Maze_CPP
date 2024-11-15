/**
 * @file solver.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Solver class
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

/**
 * @brief Constructs a Solver object.
 * @param maze Pointer to the maze to be solved.
 * @param start The starting point in the maze.
 * @param end The ending point in the maze.
 */
Solver::Solver(Maze* maze, Maze::Point start, Maze::Point end)
    : maze_{maze},
      start_{start},
      end_{end},
      visited_(maze_->rows_, Maze::WallVector(maze_->cols_, false)) {}

/**
 * @brief Solves the maze.
 * @throws std::runtime_error if no solution is found for the maze.
 */
void Solver::solve() {
  maze_->free_path();
  if (!dfs(start_.first, start_.second)) {
    throw std::runtime_error("No solution found for the maze.");
  }
}

/**
 * @brief Performs a depth-first search to find the path.
 * @param row The current row.
 * @param col The current column.
 * @return True if a path is found, false otherwise.
 */
bool Solver::dfs(int row, int col) {
  if (row < 0 || row >= maze_->rows() || col < 0 || col >= maze_->cols() ||
      visited_[row][col]) {
    return false;
  }

  visited_[row][col] = true;

  if (row == end_.first && col == end_.second) {
    maze_->push_path(row, col);
    return true;
  }

  for (int i = 0; i < kNumberDirections; ++i) {
    if (canMoveTo(row, col, kDirections[i])) {
      if (dfs(row + kRowDeltas[i], col + kColDeltas[i])) {
        maze_->push_path(row, col);
        return true;
      }
    }
  }

  return false;
}

/**
 * @brief Checks if a move to a specific Direction is possible.
 * @param row The current row.
 * @param col The current column.
 * @param dir The Direction to move.
 * @return True if the move is possible, false otherwise.
 */
bool Solver::canMoveTo(int row, int col, Direction dir) {
  switch (dir) {
    case Direction::kLeft:
      return col > 0 && !maze_->v_walls_[row][col - 1];
    case Direction::kRight:
      return col < maze_->cols() - 1 && !maze_->v_walls_[row][col];
    case Direction::kUp:
      return row > 0 && !maze_->h_walls_[row - 1][col];
    case Direction::kDown:
      return row < maze_->rows() - 1 && !maze_->h_walls_[row][col];
    default:
      return false;
  }
}

}  // namespace s21
