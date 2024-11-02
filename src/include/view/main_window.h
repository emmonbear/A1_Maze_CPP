/**
 * @file main_window.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the MainWindow class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
#define SRC_INCLUDE_VIEW_MAIN_WINDOW_H_

#include <QTabWidget>
#include <QWidget>

#include "include/view/cave_tab.h"
#include "include/view/maze_tab.h"

namespace s21 {

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  QTabWidget* tab_widget_;
  MazeTab* maze_tab_;
  CaveTab* cave_tab_;

  void initWindow();
  void setupMainWindow();
  void setupTabWidget();
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
