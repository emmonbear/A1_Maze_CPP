/**
 * @file maze_map.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeMap class
 * @version 1.0
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/maze_map.h"

#include <QPainter>

#include "include/view/settings.h"

namespace s21 {

MazeMap::MazeMap(QWidget* parent, Maze* maze) : QWidget{parent}, maze_{maze} {}

MazeMap::~MazeMap() {}

void MazeMap::resizeEvent(QResizeEvent* event) {
  image_ = QImage(event->size(), QImage::Format_ARGB32_Premultiplied);
  image_.fill(QColor(Settings::black));
  drawMaze();
  update();
}

void MazeMap::paintEvent(QPaintEvent* event) {
  QPainter p{this};
  QRect dirty_rect = event->rect();
  p.drawImage(dirty_rect, image_, dirty_rect);
}

void MazeMap::clearMaze() { image_.fill(QColor(Settings::black)); }

void MazeMap::drawMaze() {
  if (maze_->cols() == 0 || maze_->rows() == 0) {
    return;
  }

  QPainter p(&image_);
  p.setPen(QPen(Qt::white, 2));

  cell_width_ = image_.width() / maze_->cols();
  cell_height_ = image_.height() / maze_->rows();

  for (int row = 0; row < maze_->rows(); ++row) {
    for (int col = 0; col < maze_->cols(); ++col) {
      drawCells(&p, row, col);
    }
  }
  update();
}

void MazeMap::drawCells(QPainter* p, int row, int col) {
  int x = col * cell_width_;
  int y = row * cell_height_;

  if (col == 0) {
    drawLeftWall(p, x, y);
  }
  if (row == 0) {
    drawTopWall(p, x, y);
  }
  drawRightWall(p, row, col, x, y);
  drawBottomWall(p, row, col, x, y);
}

void MazeMap::drawLeftWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x, y + cell_height_);
}

void MazeMap::drawTopWall(QPainter* p, int x, int y) {
  p->drawLine(x, y, x + cell_width_, y);
}

void MazeMap::drawRightWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_->v_walls()[row][col]) {
    p->drawLine(x + cell_width_, y, x + cell_width_, y + cell_height_);
  }
}

void MazeMap::drawBottomWall(QPainter* p, int row, int col, int x, int y) {
  if (maze_->h_walls()[row][col]) {
    p->drawLine(x, y + cell_height_, x + cell_width_, y + cell_height_);
  }
}

}  // namespace s21
