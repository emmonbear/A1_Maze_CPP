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

#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QVBoxLayout>

#include "include/view/settings.h"

namespace s21 {

MazeTab::MazeTab(QWidget* parent) : QWidget(parent) {
  initWindow();
  setupLayouts();

  connect(open_file_btn_, &QPushButton::clicked, this,
          &MazeTab::onOpenFileButtonClicked);
}

void MazeTab::onOpenFileButtonClicked() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open Maze File", "", "Text Files (*.txt);;All Files (*)");

  if (!file_path.isEmpty()) {
    map_->clearMaze();
    maze_->loadFromFile(file_path.toStdString());
    map_->drawMaze();
  }
}

MazeTab::~MazeTab() { delete maze_; }

void MazeTab::initWindow() {
  maze_ = new Maze();
  map_ = new MazeMap(this, maze_);

  open_file_btn_ = new QPushButton("Open file", this);
  generate_btn_ = new QPushButton("Generate", this);

  open_file_btn_->setStyleSheet(Settings::btn_style);
  generate_btn_->setStyleSheet(Settings::btn_style);
}

void MazeTab::setupLayouts() {
  QVBoxLayout* main_layout = new QVBoxLayout(this);
  QHBoxLayout* h_layout = new QHBoxLayout();
  QHBoxLayout* buttons_layout = new QHBoxLayout();
  QGridLayout* settings_layout = new QGridLayout();

  setupMainLayout(main_layout);
  setupHLayout(h_layout);
  setupButtonsLayout(buttons_layout);
  setupSettingsLayout(settings_layout);

  h_layout->addLayout(settings_layout);
  h_layout->addLayout(buttons_layout);

  main_layout->addWidget(map_);
  main_layout->addLayout(h_layout);

  setLayout(main_layout);
}

void MazeTab::setupMainLayout(QVBoxLayout* layout) {
  layout->setContentsMargins(50, 10, 50, 50);
  layout->setSpacing(10);
}

void MazeTab::setupHLayout(QHBoxLayout* layout) {
  layout->setContentsMargins(50, 10, 50, 50);
  layout->setSpacing(10);
}

void MazeTab::setupButtonsLayout(QHBoxLayout* layout) {
  layout->setSpacing(10);
  layout->addWidget(open_file_btn_);
  layout->addWidget(generate_btn_);
}

void MazeTab::setupSettingsLayout(QGridLayout* layout) {
  QLabel* rows_label = new QLabel("ROWS", this);
  QLabel* cols_label = new QLabel("COLS", this);
  QSpinBox* rows_spin_box = new QSpinBox(this);
  QSpinBox* cols_spin_box = new QSpinBox(this);

  rows_spin_box->setRange(2, 50);
  cols_spin_box->setRange(2, 50);

  rows_label->setFixedWidth(50);
  cols_label->setFixedWidth(50);

  layout->addWidget(rows_label, 0, 0);
  layout->addWidget(rows_spin_box, 0, 1);
  layout->addWidget(cols_label, 1, 0);
  layout->addWidget(cols_spin_box, 1, 1);
  layout->setAlignment(Qt::AlignLeft);
}

}  // namespace s21
