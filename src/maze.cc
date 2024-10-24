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

#include "include/maze.h"

#include <fstream>
#include <string>
#include <vector>

int main() {
  std::string filename{"data/3x4.txt"};
  s21::Maze maze;

  maze.loadFromFile(filename);
  maze.printMaze();

  return 0;
}
