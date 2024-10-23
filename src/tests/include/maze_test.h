/**
 * @file maze_test.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the maze test suite
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_TESTS_INCLUDE_MAZE_TEST_H_
#define SRC_TESTS_INCLUDE_MAZE_TEST_H_

#include <gtest/gtest.h>

#include "../include/maze.h"

class MazeTest : public ::testing::Test {
 public:
 protected:
  void compareWalls(const std::vector<std::vector<int>>& actual,
                    const std::vector<std::vector<int>>& expected) {
    for (size_t i = 0; i < actual.size(); ++i) {
      for (size_t j = 0; j < actual[i].size(); ++j) {
        EXPECT_EQ(actual[i][j], expected[i][j]);
      }
    }
  }
  // void SetUp() override { s21::Maze maze; }

  s21::Maze maze;
};

#endif  // SRC_TESTS_INCLUDE_MAZE_TEST_H_
