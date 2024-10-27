/**
 * @file creator.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the abstract Creator class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_FACTORY_CREATOR_H_
#define SRC_INCLUDE_FACTORY_CREATOR_H_

#include <memory>
#include <string>

#include "include/map/map.h"

namespace s21 {

using MapPtr = std::unique_ptr<Map>;

class Creator {
 public:
  virtual ~Creator() = default;

  MapPtr createMapFromFile(const std::string& filename) const;
  MapPtr createMapFromSetting(int rows, int cols) const;

 protected:
  virtual MapPtr createMap() const = 0;
};
}  // namespace s21

#endif  // SRC_INCLUDE_FACTORY_CREATOR_H_
