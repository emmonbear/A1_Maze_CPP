/**
 * @file maze_layout_manager.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MazeLayoutManager class
 * @version 1.0
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAZE_LAYOUT_MANAGER_H_
#define SRC_INCLUDE_VIEW_MAZE_LAYOUT_MANAGER_H_

#include <QVBoxLayout>

namespace s21 {

class MazeLayoutManager : public QVBoxLayout {
 public:
  explicit MazeLayoutManager(QWidget* parent = nullptr);
  ~MazeLayoutManager();
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_LAYOUT_MANAGER_H_
