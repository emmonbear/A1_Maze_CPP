/**
 * @file creator.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Creator class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/factory/creator.h"

#include <string>

#include "include/file_handler/file_handler.h"

namespace s21 {
MapPtr Creator::createMapFromFile(const std::string& filename) const {
  MapPtr map = createMap();

  FileHandler::load(map.get(), filename);

  return map;
}

MapPtr Creator::createMapFromSetting(int rows, int cols) const {
  MapPtr map = createMap();

  map->generate(rows, cols);

  return map;
}

}  // namespace s21
