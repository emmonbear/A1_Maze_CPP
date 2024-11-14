/**
 * @file generator.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Generator class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_GENERATOR_H_
#define SRC_INCLUDE_MODEL_GENERATOR_H_

#include <vector>

#include "include/model/maze.h"

namespace s21 {

class Generator {
 public:
  using Vector = std::vector<int>;  ///< Alias for a vector of integers.

  explicit Generator(Maze* maze);
  void generate();

 private:
  Maze* maze_{};
  Vector sets_{};
  int counter_{1};

  void initFirstRow();
  void setUnique();
  bool randomBool();
  void createSet(int index, int element);
  bool isSingleElementInSet(int element);
  int countHorizontalWalls(int row, int element);
  void avoidBottomWallIfIsolated(int row);
  void prepareRowForGeneration(int row);
  void generateVerticalWalls(int row);
  void generateHorizontalWalls(int row);
  void generateLastRow();
  void checkEndLine();
  void clearGenerator();
};

}  // namespace s21
#endif  // SRC_INCLUDE_MODEL_GENERATOR_H_
