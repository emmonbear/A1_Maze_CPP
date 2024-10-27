/**
 * @file map.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the abstract Map class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MAP_MAP_H_
#define SRC_INCLUDE_MAP_MAP_H_

#include <iostream>
#include <string>

namespace s21 {

class Map {
 public:
  virtual ~Map() = default;
  virtual void loadFromStream(std::istream& is) = 0;
  virtual void saveToStream(std::ostream& os) const = 0;
  virtual void print() const = 0;

 protected:
  int rows_{}, cols_{};
};
}  // namespace s21

#endif  // SRC_INCLUDE_MAP_MAP_H_
