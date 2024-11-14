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

/**
 * @brief Sets the number of columns in the maze.
 * @param cols The number of columns.
 */
void Maze::set_cols(int cols) {
  cols_ = cols;
  resize();
}

/**
 * @brief Resizes the maze walls.
 */
void Maze::resize() {
  v_walls_.clear();
  h_walls_.clear();
  v_walls_.resize(rows_, WallVector(cols_, false));
  h_walls_.resize(rows_, WallVector(cols_, false));
}

/**
 * @brief Adds a point to the path.
 * @param row The row of the point.
 * @param col The column of the point.
 */
void Maze::push_path(int row, int col) { path_.push_back({row, col}); }

/**
 * @brief Clears the path in the maze.
 */
void Maze::free_path() { path_.clear(); }

}  // namespace s21
