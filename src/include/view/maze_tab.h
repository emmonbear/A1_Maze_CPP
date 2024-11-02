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

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "include/view/maze_map.h"

namespace s21 {

class MazeTab : public QWidget {
  Q_OBJECT

 public:
  explicit MazeTab(QWidget* parent = nullptr);
  ~MazeTab();

  void initWindow();

 private:
  MazeMap* map_;

  QPushButton* open_file_btn_;
  QPushButton* generate_btn_;

  void setupLayouts();
  void setupMainLayout(QVBoxLayout* layout);
  void setupHLayout(QHBoxLayout* layout);
  void setupButtonsLayout(QHBoxLayout* layout);
  void setupSettingsLayout(QGridLayout* layout);
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAZE_TAB_H_
