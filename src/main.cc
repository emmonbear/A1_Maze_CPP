/**
 * @file main.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief
 * @version 1.0
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QApplication>

#include "include/view/maze_tab.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  s21::MazeTab w;
  w.show();

  return app.exec();
}
