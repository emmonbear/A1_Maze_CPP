/**
 * @file file_handler.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the FileHandler class
 * @version 1.0
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/file_handler.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace s21 {

void FileHandler::load(Maze* maze, const std::string& filename) {
  std::ifstream is{filename};
  validateFile(is);
  is.clear();
  is.seekg(0, std::ios::beg);
  loadSize(maze, is);
  loadVerticalWalls(maze, is);
  loadHorizontalWalls(maze, is);
  is.close();
}

void FileHandler::save(const Maze& maze, const std::string& filename) {
  std::ofstream os{filename};
  saveSize(maze, os);
  saveVerticalWalls(maze, os);
  saveHorizontalWalls(maze, os);
  os.close();
}

void FileHandler::loadSize(Maze* maze, std::istream& is) {
  is >> maze->rows_ >> maze->cols_;
  maze->resize();
}

void FileHandler::loadVerticalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->v_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void FileHandler::loadHorizontalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->h_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

void FileHandler::saveSize(const Maze& maze, std::ostream& os) {
  os << maze.rows_ << " " << maze.cols_ << "\n";
}

void FileHandler::saveVerticalWalls(const Maze& maze, std::ostream& os) {
  for (const auto& row : maze.v_walls_) {
    for (const auto& col : row) {
      os << static_cast<int>(col) << " ";
    }

    os << "\n";
  }

  os << "\n";
}

void FileHandler::saveHorizontalWalls(const Maze& maze, std::ostream& os) {
  for (const auto& row : maze.h_walls_) {
    for (const auto& col : row) {
      os << static_cast<int>(col) << " ";
    }
    os << "\n";
  }
}

void FileHandler::validateFile(std::istream& is) {
  int rows{}, cols{};

  validateSize(is, &rows, &cols);
  validateVerticalWalls(is, rows, cols);
  validateHorizontalWalls(is, rows, cols);
  checkForExtraData(is);
}

void FileHandler::validateSize(std::istream& is, int* rows, int* cols) {
  if (!(is >> *rows >> *cols) || *rows < 2 || *rows > 50 || *cols < 2 ||
      *cols > 50) {
    throw std::runtime_error("Invalid file format");
  }
}

void FileHandler::validateVerticalWalls(std::istream& is, int rows, int cols) {
  int value{};
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      is >> value;
      if (value != 0 && value != 1) {
        throw std::runtime_error("Invalid file format");
      }

      if (j == cols - 1 && value == 0) {
        throw std::runtime_error("Invalid file format: vertical walls");
      }
    }
  }
}

void FileHandler::validateHorizontalWalls(std::istream& is, int rows,
                                          int cols) {
  int value{};

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      is >> value;
      if (value != 0 && value != 1) {
        throw std::runtime_error("Invalid file format");
      }

      if (i == rows - 1 && value != 1) {
        throw std::runtime_error("Invalid file format: horizontal walls");
      }
    }
  }
}

void FileHandler::checkForExtraData(std::istream& is) {
  int extra_data_check;
  if (is >> extra_data_check) {
    throw std::runtime_error("Invalid file format: unexpected additional data");
  }
}

}  // namespace s21
