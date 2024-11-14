/**
 * @file facade.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Facade class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_FACADE_H_
#define SRC_INCLUDE_CONTROLLER_FACADE_H_

#include <string>

#include "include/model/file_handler.h"
#include "include/model/generator.h"
#include "include/model/maze.h"
#include "include/model/solver.h"

namespace s21 {

/**
 * @class Facade
 * @brief Provides a simplified interface for generating, loading, saving, and
 * solving a maze.
 */
class Facade {
 public:
  void generate(int rows, int cols);
  void loadFromFile(const std::string& filename);
  void saveTofile(const std::string& filename);
  void solve(Maze::Point start, Maze::Point end);
  inline const Maze& maze() const { return maze_; }

 private:
  Maze maze_{};
};
}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_FACADE_H_
