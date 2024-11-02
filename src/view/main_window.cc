/**
 * @file main_window.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MainWindow class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/main_window.h"

#include <QVBoxLayout>

#include "include/view/settings.h"

namespace s21 {

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  initWindow();
  setupMainWindow();
  setupTabWidget();
}
MainWindow::~MainWindow() {}

void MainWindow::initWindow() {
  tab_widget_ = new QTabWidget(this);
  maze_tab_ = new MazeTab(this);
  cave_tab_ = new CaveTab(this);
}

void MainWindow::setupTabWidget() {
  tab_widget_->addTab(maze_tab_, "Maze");
  tab_widget_->addTab(cave_tab_, "Cave");
}

void MainWindow::setupMainWindow() {
  QVBoxLayout* main_layout = new QVBoxLayout(this);
  main_layout->addWidget(tab_widget_);
  setLayout(main_layout);
  resize(1000, 1000);
  setMinimumSize(600, 600);
  setStyleSheet(Settings::background_style);
}

}  // namespace s21
