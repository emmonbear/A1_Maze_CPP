/**
 * @file maze.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Maze class
 * @version 1.0
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_MAZE_H_
#define SRC_INCLUDE_MODEL_MAZE_H_

#include <string>
#include <utility>
#include <vector>

namespace s21 {

class Maze {
 public:
  using Point = std::pair<int, int>;
  using Path = std::vector<Point>;
  using WallVector = std::vector<bool>;
  using WallMatrix = std::vector<WallVector>;

  inline int rows() const { return rows_; }
  inline int cols() const { return cols_; }
  inline const WallMatrix& v_walls() const { return v_walls_; }
  inline const WallMatrix& h_walls() const { return h_walls_; }
  inline const Path& path() const { return path_; }
  inline void set_rows(int rows) { rows_ = rows; }
  void push_path(int row, int col);
  void set_cols(int cols);
  void free_path();
  void resize();

 private:
  int rows_{}, cols_{};
  WallMatrix v_walls_{};
  WallMatrix h_walls_{};
  Path path_{};

  friend class Generator;
  friend class FileHandler;
  friend class Solver;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_MAZE_H_
