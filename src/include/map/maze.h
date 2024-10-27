/**
 * @file maze.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Maze class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MAP_MAZE_H_
#define SRC_INCLUDE_MAP_MAZE_H_

#include <string>
#include <vector>

#include "include/map/map.h"

namespace s21 {
class Maze : public Map {
 public:
  using WallVector = std::vector<bool>;
  using WallMatrix = std::vector<WallVector>;

  void loadFromStream(std::istream& is) override;
  void saveToStream(std::ostream& os) const override;

  void print() const override;

  inline const WallMatrix& vertical_walls() const { return vertical_walls_; }
  inline const WallMatrix& horizontal_walls() const {
    return horizontal_walls_;
  }

 private:
  WallMatrix vertical_walls_;
  WallMatrix horizontal_walls_;

  void loadSize(std::istream& is);
  void loadVerticalWalls(std::istream& is);
  void loadHorizontalWalls(std::istream& is);
  void saveSize(std::ostream& os) const;
  void saveVerticalWalls(std::ostream& os) const;
  void saveHorizontalWalls(std::ostream& os) const;
  void printTopBorder() const;
  void printVerticalWalls(int row) const;
  void printHorizontalWalls(int row) const;
};
}  // namespace s21

#endif  // SRC_INCLUDE_MAP_MAZE_H_
