/**
 * @file maze_test.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Maze class test suite
 * @version 1.0
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/maze_test.h"

#include <fstream>
#include <string>
#include <vector>

TEST_F(MazeTest, loadFromFile4x4) {
  std::string filename{"test_maze.txt"};
  std::ofstream file{filename};

  file << "4 3\n"
       << "0 0 0 1\n"
       << "1 0 1 1\n"
       << "0 1 0 1\n"
       << "0 0 0 1\n"
       << "1 0 1 0\n"
       << "0 0 1 0\n"
       << "1 1 0 1\n"
       << "1 1 1 1\n";
  file.close();

  std::vector<std::vector<int>> expectedVerticalWalls{
      {0, 0, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {0, 0, 0, 1}};

  std::vector<std::vector<int>> expectedHorizontalWalls{
      {1, 0, 1, 0}, {0, 0, 1, 0}, {1, 1, 0, 1}, {1, 1, 1, 1}};

  maze.loadFromFile(filename);

  EXPECT_EQ(maze.rows(), 4);
  EXPECT_EQ(maze.cols(), 4);

  compareWalls(maze.vertical_walls(), expectedVerticalWalls);
  compareWalls(maze.horizontal_walls(), expectedHorizontalWalls);

  remove(filename.c_str());
}
