/**
 * @file generator.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Generator class
 * @version 1.0
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/model/generator.h"

#include <fstream>
#include <random>
#include <string>

namespace s21 {

/**
 * @brief Constructs a Generator object.
 * @param maze Pointer to the maze to be generated.
 */
Generator::Generator(Maze* maze) : maze_{maze} {}

/**
 * @brief Generates the maze.
 *
 * @details
 *
 * Eller's algorithm creates 'perfect' mazes, having only a single path between
 * any two cells, one row at a time. The algorithm itself is incredibly fast,
 * and far more memory efficient than other popular algorithms (such as Prim's
 * and Kruskal's) requiring storage proportional to only a single row. This
 * makes it possible to create mazes of indefinite length on systems with
 * limited memory.
 *
 * There is very little written about Eller's Algorithm on the internet. The
 * best source I could find (Walter Pullen's excellent Think Labyrinth website)
 * has a single paragraph description which, while very helpful, I found
 * inadequate to implement the algorithm. Additionally, the algorithm described
 * in Mathematics and Physics for Programmers doesn't seem to work. Needless to
 * say, uncovering information about this very interesting algorithm was
 * frustrating.
 * I was able to work out the missing details, and I'm confident that the
 * algorithm I came up with is indeed Eller's algorithm. This page is intended
 * to (hopefully) alleviate the suffering of future searchers interested in this
 * fascinating maze generator.
 *
 * @section The Algorithm
 * Note: Assume that there all left-most cells have a wall.
 *
 * 1. **Create the first row.** No cells will be members of any set.
 * 2. **Join any cells not members of a set to their own unique set.**
 * 3. **Create right-walls, moving from left to right:**
 *    - Randomly decide to add a wall or not.
 *    - If the current cell and the cell to the right are members of the same
 * set, always create a wall between them. (This prevents loops)
 *    - If you decide not to add a wall, union the sets to which the current
 * cell and the cell to the right are members.
 * 4. **Create bottom-walls, moving from left to right:**
 *    - Randomly decide to add a wall or not. Make sure that each set has at
 * least one cell without a bottom-wall (This prevents isolations)
 *    - If a cell is the only member of its set, do not create a bottom-wall.
 *    - If a cell is the only member of its set without a bottom-wall, do not
 * create a bottom-wall.
 * 5. **Decide to keep adding rows, or stop and complete the maze.**
 *    - If you decide to add another row:
 *      - Output the current row.
 *      - Remove all right walls.
 *      - Remove cells with a bottom-wall from their set.
 *      - Remove all bottom walls.
 *      - Continue from Step 2.
 *    - If you decide to complete the maze:
 *      - Add a bottom wall to every cell.
 *      - Moving from left to right:
 *        - If the current cell and the cell to the right are members of a
 * different set:
 *          - Remove the right wall.
 *          - Union the sets to which the current cell and cell to the right are
 * members.
 *      - Output the final row.
 */
void Generator::generate() {
  initFirstRow();

  for (int row = 0; row < maze_->rows_ - 1; ++row) {
    setUnique();
    generateVerticalWalls(row);
    generateHorizontalWalls(row);
    prepareRowForGeneration(row);
  }
  generateLastRow();
  clearGenerator();
}

/**
 * @brief Initializes the first row of the maze.
 */
void Generator::initFirstRow() {
  for (int col = 0; col < maze_->cols_; ++col) {
    sets_.emplace_back(0);
  }
}

/**
 * @brief Sets unique values for the sets.
 */
void Generator::setUnique() {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (!sets_[col]) {
      sets_[col] = counter_;
      ++counter_;
    }
  }
}

/**
 * @brief Generates a random boolean value.
 * @return A random boolean value.
 */
bool Generator::randomBool() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);

  return dist(gen);
}

/**
 * @brief Creates a set with a given index and element.
 * @param index The index of the set.
 * @param element The element to be added to the set.
 */
void Generator::createSet(int index, int element) {
  int set = sets_[index + 1];
  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == set) {
      sets_[col] = element;
    }
  }
}

/**
 * @brief Checks if an element is the only one in its set.
 * @param element The element to check.
 * @return True if the element is the only one in its set, false otherwise.
 */
bool Generator::isSingleElementInSet(int element) {
  int count{0};

  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == element) {
      count++;
    }
  }

  return count == 1;
}

/**
 * @brief Counts the number of horizontal walls in a given row for a specific
 * element.
 * @param row The row to check.
 * @param element The element to check.
 * @return The number of horizontal walls.
 */
int Generator::countHorizontalWalls(int row, int element) {
  int count{0};

  for (int col = 0; col < maze_->cols_; ++col) {
    if (sets_[col] == element && maze_->h_walls_[row][col] == false) {
      ++count;
    }
  }
  return count;
}

/**
 * @brief Avoids creating a bottom wall if it would isolate an element.
 * @param row The row to check.
 */
void Generator::avoidBottomWallIfIsolated(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (countHorizontalWalls(row, sets_[col]) == 0) {
      maze_->h_walls_[row][col] = false;
    }
  }
}

/**
 * @brief Prepares a row for generation.
 * @param row The row to prepare.
 */
void Generator::prepareRowForGeneration(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    if (maze_->h_walls_[row][col]) {
      sets_[col] = 0;
    }
  }
}

/**
 * @brief Generates vertical walls for a given row.
 * @param row The row to generate vertical walls for.
 */
void Generator::generateVerticalWalls(int row) {
  for (int col = 0; col < maze_->cols_ - 1; ++col) {
    bool choise = randomBool();
    if (choise || sets_[col] == sets_[col + 1]) {
      maze_->v_walls_[row][col] = true;
    } else {
      createSet(col, sets_[col]);
    }
  }

  maze_->v_walls_[row][maze_->cols_ - 1] = true;
}

/**
 * @brief Generates horizontal walls for a given row.
 * @param row The row to generate horizontal walls for.
 */
void Generator::generateHorizontalWalls(int row) {
  for (int col = 0; col < maze_->cols_; ++col) {
    bool choise = randomBool();

    if (choise && !isSingleElementInSet(sets_[col])) {
      maze_->h_walls_[row][col] = true;
    }
  }

  avoidBottomWallIfIsolated(row);
}

/**
 * @brief Generates the last row of the maze.
 */
void Generator::generateLastRow() {
  setUnique();
  generateVerticalWalls(maze_->rows_ - 1);
  checkEndLine();
}

/**
 * @brief Checks the end line of the maze.
 */
void Generator::checkEndLine() {
  for (int col = 0; col < maze_->cols_ - 1; ++col) {
    if (sets_[col] != sets_[col + 1]) {
      maze_->v_walls_[maze_->rows_ - 1][col] = false;
      createSet(col, sets_[col]);
    }
    maze_->h_walls_[maze_->rows_ - 1][col] = true;
  }
  maze_->h_walls_[maze_->rows_ - 1][maze_->cols_ - 1] = true;
}

/**
 * @brief Clears the generator.
 */
void Generator::clearGenerator() {
  counter_ = 1;
  sets_.clear();
}
}  // namespace s21
