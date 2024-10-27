/**
 * @file file_handler.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the FileHandler class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_FILE_HANDLER_FILE_HANDLER_H_
#define SRC_INCLUDE_FILE_HANDLER_FILE_HANDLER_H_

#include <string>

#include "include/map/map.h"

namespace s21 {
class FileHandler {
 public:
  static void load(Map* map, const std::string& filename);
  static void save(const Map& map, const std::string& filename);
};
}  // namespace s21

#endif  // SRC_INCLUDE_FILE_HANDLER_FILE_HANDLER_H_
