/**
 * @file maze_creator.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeCreator class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/factory/maze_creator.h"

#include <memory>

namespace s21 {
MapPtr MazeCreator::createMap() const { return std::make_unique<Maze>(); }
}  // namespace s21
