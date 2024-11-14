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
#include <stdexcept>
#include <string>

namespace s21 {

/**
 * @brief Loads a maze from a file.
 * @param maze Pointer to the maze to be loaded.
 * @param filename The name of the file to load the maze from.
 */
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

/**
 * @brief Saves a maze to a file.
 * @param maze The maze to be saved.
 * @param filename The name of the file to save the maze to.
 */
void FileHandler::save(const Maze& maze, const std::string& filename) {
  std::ofstream os{filename};
  saveSize(maze, os);
  saveVerticalWalls(maze, os);
  saveHorizontalWalls(maze, os);
  os.close();
}

/**
 * @brief Loads the size of the maze from a stream.
 * @param maze Pointer to the maze to be loaded.
 * @param is The input stream to load the size from.
 */
void FileHandler::loadSize(Maze* maze, std::istream& is) {
  is >> maze->rows_ >> maze->cols_;
  maze->resize();
}

/**
 * @brief Loads the vertical walls of the maze from a stream.
 * @param maze Pointer to the maze to be loaded.
 * @param is The input stream to load the vertical walls from.
 */
void FileHandler::loadVerticalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->v_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

/**
 * @brief Loads the horizontal walls of the maze from a stream.
 * @param maze Pointer to the maze to be loaded.
 * @param is The input stream to load the horizontal walls from.
 */
void FileHandler::loadHorizontalWalls(Maze* maze, std::istream& is) {
  for (int i = 0; i < maze->rows_; ++i) {
    for (int j = 0; j < maze->cols_; ++j) {
      int wall_value;
      is >> wall_value;
      maze->h_walls_[i][j] = static_cast<bool>(wall_value);
    }
  }
}

/**
 * @brief Saves the size of the maze to a stream.
 * @param maze The maze to be saved.
 * @param os The output stream to save the size to.
 */
void FileHandler::saveSize(const Maze& maze, std::ostream& os) {
  os << maze.rows_ << " " << maze.cols_ << "\n";
}

/**
 * @brief Saves the vertical walls of the maze to a stream.
 * @param maze The maze to be saved.
 * @param os The output stream to save the vertical walls to.
 */
void FileHandler::saveVerticalWalls(const Maze& maze, std::ostream& os) {
  for (const auto& row : maze.v_walls_) {
    for (size_t col = 0; col < row.size(); ++col) {
      os << static_cast<int>(row[col]);
      if (col < row.size() - 1) {
        os << " ";
      }
    }

    os << "\n";
  }

  os << "\n";
}

/**
 * @brief Saves the horizontal walls of the maze to a stream.
 * @param maze The maze to be saved.
 * @param os The output stream to save the horizontal walls to.
 */
void FileHandler::saveHorizontalWalls(const Maze& maze, std::ostream& os) {
  for (const auto& row : maze.h_walls_) {
    for (size_t col = 0; col < row.size(); ++col) {
      os << static_cast<int>(row[col]);
      if (col < row.size() - 1) {
        os << " ";
      }
    }
    os << "\n";
  }
}

/**
 * @brief Validates the file format.
 * @param is The input stream to validate.
 */
void FileHandler::validateFile(std::istream& is) {
  int rows{}, cols{};

  validateSize(is, &rows, &cols);
  validateVerticalWalls(is, rows, cols);
  validateHorizontalWalls(is, rows, cols);
  checkForExtraData(is);
}

/**
 * @brief Validates the size of the maze.
 * @param is The input stream to validate.
 * @param rows Pointer to store the number of rows.
 * @param cols Pointer to store the number of columns.
 */
void FileHandler::validateSize(std::istream& is, int* rows, int* cols) {
  if (!(is >> *rows >> *cols) || *rows < 2 || *rows > 50 || *cols < 2 ||
      *cols > 50) {
    throw std::runtime_error("Invalid file format");
  }
}

/**
 * @brief Validates the vertical walls of the maze.
 * @param is The input stream to validate.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @throws std::runtime_error if the file format is invalid.
 */
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

/**
 * @brief Validates the horizontal walls of the maze.
 * @param is The input stream to validate.
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @throws std::runtime_error if the file format is invalid.
 */
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

/**
 * @brief Checks for extra data in the file.
 * @param is The input stream to check.
 * @throws std::runtime_error if there is unexpected additional data in the
 * file.
 */
void FileHandler::checkForExtraData(std::istream& is) {
  int extra_data_check;
  if (is >> extra_data_check) {
    throw std::runtime_error("Invalid file format: unexpected additional data");
  }
}

}  // namespace s21
