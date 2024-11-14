/**
 * @file maze_facade.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeFacade class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/controller/facade.h"

#include <string>

namespace s21 {

void MazeFacade::generate(int rows, int cols) {
  MazeGenerator generator(&maze_);

  maze_.set_rows(rows);
  maze_.set_cols(cols);
  generator.generate();
}

void MazeFacade::loadFromFile(const std::string& filename) {
  FileHandler::load(&maze_, filename);
}

void MazeFacade::saveTofile(const std::string& filename) {
  FileHandler::save(maze_, filename);
}

void MazeFacade::solve(Maze::Point start, Maze::Point end) {
  MazeSolver solver(&maze_, start, end);
  solver.solve();
}

}  // namespace s21
