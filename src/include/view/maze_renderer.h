/**
 * @file maze_renderer.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MazeRenderer class
 * @version 1.0
 * @date 2024-11-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAZE_RENDERER_H_
#define SRC_INCLUDE_VIEW_MAZE_RENDERER_H_

#include <QImage>
#include <QPaintEvent>
#include <QWidget>

#include "include/model/maze.h"
#include "include/view/settings.h"

namespace s21 {

class MazeRenderer : public QWidget {
  Q_OBJECT

 public:
  explicit MazeRenderer(QWidget* parent = nullptr, const Maze& maze = Maze());
  ~MazeRenderer();

  void drawMaze();
  void clearMaze();
  void drawPath();

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  const Maze& maze_;
  int cell_size_{};
  QImage image_;

  void setupWindow();
  void drawCells(QPainter* p, int row, int col);
  void drawLeftWall(QPainter* p, int x, int y);
  void drawTopWall(QPainter* p, int x, int y);
  void drawRightWall(QPainter* p, int row, int col, int x, int y);
  void drawBottomWall(QPainter* p, int row, int col, int x, int y);
  void calculateCellSize();
  // void clearPath();
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_RENDERER_H_
