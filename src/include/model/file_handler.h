/**
 * @file file_handler.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the FileHandler class
 * @version 1.0
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_FILE_HANDLER_H_
#define SRC_INCLUDE_MODEL_FILE_HANDLER_H_

#include <string>

#include "include/model/maze.h"

namespace s21 {
class FileHandler {
 public:
  void load(Maze* maze, const std::string& filename);
  void save(const Maze& maze, const std::string& filename);
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_HANDLER_H_
