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
  static void load(Maze* maze, const std::string& filename);
  static void save(const Maze& maze, const std::string& filename);

 private:
  static void loadSize(Maze* maze, std::istream& is);
  static void loadVerticalWalls(Maze* maze, std::istream& is);
  static void loadHorizontalWalls(Maze* maze, std::istream& is);
  static void saveSize(const Maze& maze, std::ostream& os);
  static void saveVerticalWalls(const Maze& maze, std::ostream& os);
  static void saveHorizontalWalls(const Maze& maze, std::ostream& os);
  static void validateFile(std::istream& is);
  static void validateSize(std::istream& is, int* rows, int* cols);
  static void validateVerticalWalls(std::istream& is, int rows, int cols);
  static void validateHorizontalWalls(std::istream& is, int rows, int cols);
  static void checkForExtraData(std::istream& is);
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_FILE_HANDLER_H_
