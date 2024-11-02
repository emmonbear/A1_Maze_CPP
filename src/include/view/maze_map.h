/**
 * @file maze_map.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MazeMap class
 * @version 1.0
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAZE_MAP_H_
#define SRC_INCLUDE_VIEW_MAZE_MAP_H_

#include <QImage>
#include <QResizeEvent>
#include <QWidget>

#include "include/model/maze.h"

namespace s21 {

class MazeMap : public QWidget {
  Q_OBJECT

 public:
  explicit MazeMap(QWidget* parent = nullptr, Maze* maze = nullptr);
  ~MazeMap();
  void drawMaze();
  void clearMaze();

 protected:
  void resizeEvent(QResizeEvent* event) override;
  void paintEvent(QPaintEvent* event) override;

 private:
  QImage image_;
  Maze* maze_;
  int cell_width_{}, cell_height_{};

  void drawCells(QPainter* p, int row, int col);
  void drawLeftWall(QPainter* p, int x, int y);
  void drawTopWall(QPainter* p, int x, int y);
  void drawRightWall(QPainter* p, int row, int col, int x, int y);
  void drawBottomWall(QPainter* p, int row, int col, int x, int y);
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_MAP_H_
