/**
 * @file file_handler.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the FileHandler class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/file_handler/file_handler.h"

#include <fstream>
#include <string>

namespace s21 {
void FileHandler::load(Map* map, const std::string& filename) {
  std::ifstream is{filename};

  if (!is.is_open()) {
    throw std::runtime_error("Error: could not open file:" + filename);
  }

  map->loadFromStream(is);
  is.close();
}

void FileHandler::save(const Map& map, const std::string& filename) {}
}  // namespace s21
