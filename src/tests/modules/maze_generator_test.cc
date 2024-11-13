/**
 * @file maze_generator_test.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeGenerator class tests
 * @version 1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <string>

#include "include/controller/maze_facade.h"
#include "tests/include/main_test.h"

namespace Test {

class MazeGeneratorTest : public ::testing::Test {
 protected:
  void TearDown() override { std::remove(filename_.c_str()); }

  s21::MazeFacade facade_;
  std::string filename_ = "test_maze.txt";
};

}  // namespace Test
