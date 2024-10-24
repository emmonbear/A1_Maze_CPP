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
  using Vector = std::vector<int>;
  using WallMatrix = std::vector<Vector>;

  Maze() = default;

  void loadFromFile(const std::string& filename);
  void printMaze() const;

  inline int rows() const { return rows_; }
  inline int cols() const { return cols_; }
  inline const WallMatrix& vertical_walls() const { return vertical_walls_; }
  inline const WallMatrix& horizontal_walls() const {
    return horizontal_walls_;
  }

 private:
  int rows_{}, cols_{};
  WallMatrix vertical_walls_{};
  WallMatrix horizontal_walls_{};

  void loadMazeSize(std::fstream& file);
  void loadVerticalWalls(std::fstream& file);
  void loadHorizontalWalls(std::fstream& file);

  void printTopBorder() const;
  void printVerticalWalls(int row) const;
  void printHorizontalWalls(int row) const;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MAZE_H_
