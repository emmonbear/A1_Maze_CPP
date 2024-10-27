/**
 * @file cave_creator.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the CaveCreator class
 * @version 1.0
 * @date 2024-10-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/factory/cave_creator.h"

#include <memory>

namespace s21 {
MapPtr CaveCreator::createMap() const { return std::make_unique<Cave>(); }
}  // namespace s21
