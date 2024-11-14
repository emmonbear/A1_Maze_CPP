/**
 * @file facade.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Facade class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/controller/facade.h"

#include <string>

namespace s21 {

void Facade::generate(int rows, int cols) {
  Generator generator(&maze_);

  maze_.set_rows(rows);
  maze_.set_cols(cols);
  generator.generate();
}

void Facade::loadFromFile(const std::string& filename) {
  FileHandler::load(&maze_, filename);
}

void Facade::saveTofile(const std::string& filename) {
  FileHandler::save(maze_, filename);
}

void Facade::solve(Maze::Point start, Maze::Point end) {
  Solver solver(&maze_, start, end);
  solver.solve();
}

}  // namespace s21
