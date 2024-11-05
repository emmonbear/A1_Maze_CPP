/**
 * @file maze_facade.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MazeFacade class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_MAZE_FACADE_H_
#define SRC_INCLUDE_CONTROLLER_MAZE_FACADE_H_

#include <string>

#include "include/model/maze.h"
#include "include/model/maze_generator.h"

namespace s21 {

class MazeFacade {
 public:
  void generate(int rows, int cols);
  void loadFromFile(const std::string& filename);

  inline const Maze& maze() const { return maze_; }

 private:
  Maze maze_{};
  MazeGenerator generator_{};
};
}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_MAZE_FACADE_H_
