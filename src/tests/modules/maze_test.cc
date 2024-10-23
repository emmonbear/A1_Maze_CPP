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

  file << "4 4\n"
       << "0 0 0 1\n"
       << "1 0 1 1\n"
       << "0 1 0 1\n"
       << "0 0 0 1\n\n"

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

TEST_F(MazeTest, loadFromFile1x4) {
  std::string filename{"test_maze.txt"};
  std::ofstream file{filename};

  file << "1 4\n"
       << "0 0 0 1\n"
       << "1 0 1 1\n";
  file.close();

  std::vector<std::vector<int>> expectedVerticalWalls{{0, 0, 0, 1}};

  std::vector<std::vector<int>> expectedHorizontalWalls{{1, 0, 1, 1}};

  maze.loadFromFile(filename);

  EXPECT_EQ(maze.rows(), 1);
  EXPECT_EQ(maze.cols(), 4);

  compareWalls(maze.vertical_walls(), expectedVerticalWalls);
  compareWalls(maze.horizontal_walls(), expectedHorizontalWalls);

  remove(filename.c_str());
}

TEST_F(MazeTest, loadFromFile7x4) {
  std::string filename{"test_maze.txt"};
  std::ofstream file{filename};

  file << "7 4\n"

       << "0 0 0 1\n"
       << "1 0 1 1\n"
       << "0 1 0 1\n"
       << "0 0 0 1\n"
       << "1 0 1 0\n"
       << "0 0 1 0\n"
       << "1 1 0 1\n"

       << "1 0 1 1\n"
       << "1 1 1 1\n"
       << "0 0 0 1\n"
       << "0 1 0 1\n\n"
       << "1 1 1 0\n"
       << "0 1 1 0\n"
       << "1 1 1 1\n";
  file.close();

  std::vector<std::vector<int>> expectedVerticalWalls{
      {0, 0, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {0, 0, 0, 1},
      {1, 0, 1, 0}, {0, 0, 1, 0}, {1, 1, 0, 1}};

  std::vector<std::vector<int>> expectedHorizontalWalls{
      {1, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 1}, {0, 1, 0, 1},
      {1, 1, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}};

  maze.loadFromFile(filename);

  EXPECT_EQ(maze.rows(), 7);
  EXPECT_EQ(maze.cols(), 4);

  compareWalls(maze.vertical_walls(), expectedVerticalWalls);
  compareWalls(maze.horizontal_walls(), expectedHorizontalWalls);

  remove(filename.c_str());
}

TEST_F(MazeTest, loadFromFileNotFound) {
  std::string filename{"non_existent_file.txt"};

  std::ifstream file{filename};

  ASSERT_FALSE(file.is_open());
  EXPECT_THROW(maze.loadFromFile(filename), std::runtime_error);
}
