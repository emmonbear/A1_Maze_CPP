/**
 * @file maze_tab.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MazeTab class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/maze_tab.h"

namespace s21 {

MazeTab::MazeTab(QWidget* parent) : QWidget(parent) {
  maze_layout_ = new MazeLayoutManager(this);
}
MazeTab::~MazeTab() {}

}  // namespace s21
