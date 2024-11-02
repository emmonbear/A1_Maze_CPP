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

#include "include/view/main_window.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  s21::MainWindow w;
  w.show();

  return app.exec();
}
