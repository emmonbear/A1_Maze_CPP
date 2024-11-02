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
  explicit MazeMap(QWidget* parent = nullptr);
  ~MazeMap();

 protected:
  void resizeEvent(QResizeEvent* event) override;
  void paintEvent(QPaintEvent* event) override;

 private:
  Maze* maze_;
  QImage image_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_MAP_H_
