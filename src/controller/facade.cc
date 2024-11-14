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

/**
 * @brief Generates a maze with the specified number of rows and columns.
 * @param rows The number of rows in the maze.
 * @param cols The number of columns in the maze.
 */
void Facade::generate(int rows, int cols) {
  Generator generator(&maze_);

  maze_.set_rows(rows);
  maze_.set_cols(cols);
  generator.generate();
}

/**
 * @brief Loads a maze from a file.
 * @param filename The name of the file to load the maze from.
 */
void Facade::loadFromFile(const std::string& filename) {
  FileHandler::load(&maze_, filename);
}

/**
 * @brief Saves a maze to a file.
 * @param filename The name of the file to save the maze to.
 */
void Facade::saveTofile(const std::string& filename) {
  FileHandler::save(maze_, filename);
}

/**
 * @brief Solves the maze.
 * @param start The starting point in the maze.
 * @param end The ending point in the maze.
 */
void Facade::solve(Maze::Point start, Maze::Point end) {
  Solver solver(&maze_, start, end);
  solver.solve();
}

}  // namespace s21
