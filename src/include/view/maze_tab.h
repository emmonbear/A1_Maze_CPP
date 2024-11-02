/**
 * @file maze_tab.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MazeTab class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAZE_TAB_H_
#define SRC_INCLUDE_VIEW_MAZE_TAB_H_

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "include/view/maze_layout_manager.h"

namespace s21 {

class MazeTab : public QWidget {
  Q_OBJECT

 public:
  explicit MazeTab(QWidget* parent = nullptr);
  ~MazeTab();

 private:
  MazeLayoutManager* maze_layout_;
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_TAB_H_
