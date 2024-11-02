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

namespace s21 {

MazeMap::MazeMap(QWidget* parent) : QWidget{parent} {}
MazeMap::~MazeMap() {}

void MazeMap::resizeEvent(QResizeEvent* event) {
  image_ = QImage(event->size(), QImage::Format_ARGB32_Premultiplied);
  image_.fill(Qt::white);
  update();
}

void MazeMap::paintEvent(QPaintEvent* event) {
  QPainter painter{this};
  QRect dirty_rect = event->rect();
  painter.drawImage(dirty_rect, image_, dirty_rect);
}

}  // namespace s21
