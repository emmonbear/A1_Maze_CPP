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

#include "include/controller/maze_facade.h"

#include <string>

namespace s21 {

void MazeFacade::generate(int rows, int cols) {
  maze_.set_rows(rows);
  maze_.set_cols(cols);
  generator_.generate(&maze_);
}

void MazeFacade::loadFromFile(const std::string& filename) {
  FileHandler::load(&maze_, filename);
}

}  // namespace s21
