/**
 * @file maze_renderer.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the Renderer class
 * @version 1.0
 * @date 2024-11-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/renderer.h"

#include <QPainter>
#include <algorithm>

namespace s21 {

/**
 * @brief Constructs a Renderer object.
 * @param parent The parent widget.
 * @param maze The maze to be rendered.
 */
Renderer::Renderer(QWidget* parent, const Maze& maze)
    : QWidget{parent}, maze_{maze}, cell_size_{} {
  setupWindow();
}

/**
 * @brief Destructor for the Renderer class.
 */
Renderer::~Renderer() {}

/**
 * @brief Sets up the window.
 */
void Renderer::setupWindow() {
  setWindowTitle("Maze Renderer");
  setFixedSize(Settings::kRenderAreaSize, Settings::kRenderAreaSize);

  image_ = QImage(size(), QImage::Format_ARGB32_Premultiplied);
}

/**
 * @brief Clears the maze.
 */
void Renderer::clearMaze() { image_.fill(QColor(Settings::kBlack)); }

/**
 * @brief Handles the paint event.
 * @param event The paint event.
 */
void Renderer::paintEvent(QPaintEvent* event) {
  QPainter p{this};
  QRect dirty_rect = event->rect();
  p.drawImage(dirty_rect, image_, dirty_rect);
}

/**
 * @brief Draws the path in the maze.
 */
void Renderer::drawMaze() {
  if (maze_.cols() == 0 || maze_.rows() == 0) {
    return;
  }

  QPainter p(&image_);
  p.setPen(QPen(Qt::white, 2));

  calculateCellSize();

  for (int row = 0; row < maze_.rows(); ++row) {
    for (int col = 0; col < maze_.cols(); ++col) {
      drawCells(&p, row, col);
    }
  }
  update();
}

/**
 * @brief Draws the cells of the maze.
 * @param p The painter used for drawing.
 * @param row The row of the cell.
 * @param col The column of the cell.
 */
void Renderer::drawCells(QPainter* p, int row, int col) {
  int x = col * cell_size_;
  int y = row * cell_size_;

  if (col == 0) {
    drawLeftWall(p, x, y);
  }
  if (row == 0) {
    drawTopWall(p, x, y);
  }
  drawRightWall(p, row, col, x, y);
  drawBottomWall(p, row, col, x, y);
}

/**
 * @brief Draws the left wall of a cell.
 * @param p The painter used for drawing.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 */
void Renderer::drawLeftWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x, y + cell_size_);
}

/**
 * @brief Draws the top wall of a cell.
 * @param p The painter used for drawing.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 */
void Renderer::drawTopWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x + cell_size_, y);
}

/**
 * @brief Draws the right wall of a cell.
 * @param p The painter used for drawing.
 * @param row The row of the cell.
 * @param col The column of the cell.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 */
void Renderer::drawRightWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_.v_walls()[row][col]) {
    p->drawLine(x + cell_size_, y, x + cell_size_, y + cell_size_);
  }
}

/**
 * @brief Draws the bottom wall of a cell.
 * @param p The painter used for drawing.
 * @param row The row of the cell.
 * @param col The column of the cell.
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 */
void Renderer::drawBottomWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_.h_walls()[row][col]) {
    p->drawLine(x, y + cell_size_, x + cell_size_, y + cell_size_);
  }
}

/**
 * @brief Calculates the size of each cell in the maze.
 */
void Renderer::calculateCellSize() {
  int max_dimension = std::max(maze_.rows(), maze_.cols());

  cell_size_ = Settings::kRenderAreaSize / max_dimension;
}

/**
 * @brief Draws the path in the maze.
 */
void Renderer::drawPath() {
  clearMaze();
  drawMaze();
  Maze::Path path = maze_.path();
  QPainter p(&image_);
  p.setPen(QPen(QColor(Settings::kGreen), 3));

  for (size_t i = 0; i < path.size() - 1; ++i) {
    int x1 = path[i].second * cell_size_ + cell_size_ / 2;
    int y1 = path[i].first * cell_size_ + cell_size_ / 2;
    int x2 = path[i + 1].second * cell_size_ + cell_size_ / 2;
    int y2 = path[i + 1].first * cell_size_ + cell_size_ / 2;

    p.drawLine(x1, y1, x2, y2);
  }

  update();
}

}  // namespace s21
