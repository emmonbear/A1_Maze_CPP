/**
 * @file maze.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Maze
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "include/factory/creator.h"
#include "include/factory/maze_creator.h"

int main() {
  auto creator = std::make_unique<s21::MazeCreator>();

  auto maze = creator->createMapFromFile("data/3x4.txt");
  maze->print();

  return 0;
}
