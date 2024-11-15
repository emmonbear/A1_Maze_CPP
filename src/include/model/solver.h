/**
 * @file solver.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Solver class
 * @version 1.0
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SOLVER_H_
#define SRC_INCLUDE_MODEL_SOLVER_H_

#include <array>
#include <unordered_map>
#include <utility>
#include <vector>

#include "include/model/maze.h"

namespace s21 {

/**
 * @class Solver
 * @brief Solves the maze using a depth-first search algorithm.
 */
class Solver {
 public:
  Solver(Maze* maze, Maze::Point start, Maze::Point end);
  void solve();

 private:
  Maze* maze_;
  Maze::Point start_;
  Maze::Point end_;
  Maze::WallMatrix visited_;

  enum class direction { kUp, kDown, kLeft, kRight };

  bool dfs(int row, int col);
  bool canMoveTo(int row, int col, direction dir);

  static constexpr int kNumberDirections{4};
  /**
   * @brief Array of possible directions.
   */
  static constexpr std::array<direction, kNumberDirections> kDirections = {
      direction::kLeft, direction::kRight, direction::kUp, direction::kDown};

  /**
   * @brief Array of row deltas for each direction.
   */
  static constexpr std::array<int, kNumberDirections> kRowDeltas = {0, 0, -1,
                                                                    1};

  /**
   * @brief Array of column deltas for each direction.
   */
  static constexpr std::array<int, kNumberDirections> kColDeltas = {-1, 1, 0,
                                                                    0};
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SOLVER_H_
