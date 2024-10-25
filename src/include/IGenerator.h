/**
 * @file IGenerator.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-10-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_IGENERATOR_H_
#define SRC_INCLUDE_IGENERATOR_H_

namespace s21 {
class IGenerator {
 public:
  virtual void generate() = 0;
  virtual ~IGenerator() = default;
};
}  // namespace s21

#endif  // SRC_INCLUDE_IGENERATOR_H_
