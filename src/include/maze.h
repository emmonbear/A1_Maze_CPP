/**
 * @file maze.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Maze class
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MAZE_H_
#define SRC_INCLUDE_MAZE_H_

#include <string>
#include <vector>

namespace s21 {
class Maze {
 public:
  Maze() = default;

  void loadFromFile(const std::string& filename);

  inline int rows() const { return rows_; }
  inline int cols() const { return cols_; }
  inline const std::vector<std::vector<int>>& vertical_walls() const {
    return vertical_walls_;
  }
  inline const std::vector<std::vector<int>>& horizontal_walls() const {
    return horizontal_walls_;
  }

 private:
  int rows_{}, cols_{};
  std::vector<std::vector<int>> vertical_walls_{};
  std::vector<std::vector<int>> horizontal_walls_{};

  void loadMazeSize(std::fstream& file);
  void loadVerticalWalls(std::fstream& file);
  void loadHorizontalWalls(std::fstream& file);
};
}  // namespace s21

#endif  // SRC_INCLUDE_MAZE_H_
