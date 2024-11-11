/**
 * @file maze_renderer.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeRenderer class
 * @version 1.0
 * @date 2024-11-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/maze_renderer.h"

#include <QPainter>
#include <algorithm>

namespace s21 {

MazeRenderer::MazeRenderer(QWidget* parent, const Maze& maze)
    : QWidget{parent}, maze_{maze}, cell_size_{} {
  setupWindow();
}

MazeRenderer::~MazeRenderer() {}

void MazeRenderer::setupWindow() {
  setWindowTitle("Maze Renderer");
  setFixedSize(Settings::render_size, Settings::render_size);

  image_ = QImage(size(), QImage::Format_ARGB32_Premultiplied);
}

void MazeRenderer::clearMaze() { image_.fill(QColor(Settings::black)); }

void MazeRenderer::paintEvent(QPaintEvent* event) {
  QPainter p{this};
  QRect dirty_rect = event->rect();
  p.drawImage(dirty_rect, image_, dirty_rect);
}

void MazeRenderer::drawMaze() {
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

void MazeRenderer::drawCells(QPainter* p, int row, int col) {
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

void MazeRenderer::drawLeftWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x, y + cell_size_);
}

void MazeRenderer::drawTopWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x + cell_size_, y);
}

void MazeRenderer::drawRightWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_.v_walls()[row][col]) {
    p->drawLine(x + cell_size_, y, x + cell_size_, y + cell_size_);
  }
}

void MazeRenderer::drawBottomWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_.h_walls()[row][col]) {
    p->drawLine(x, y + cell_size_, x + cell_size_, y + cell_size_);
  }
}

void MazeRenderer::calculateCellSize() {
  int max_dimension = std::max(maze_.rows(), maze_.cols());

  cell_size_ = Settings::render_size / max_dimension;
}

}  // namespace s21
