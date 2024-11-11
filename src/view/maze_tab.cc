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
#include <QLabel>
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

MazeTab::~MazeTab() {}

void MazeTab::onOpenFileButtonClicked() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open Maze File", "../datasets", "Text Files (*.txt)");

  if (!file_path.isEmpty()) {
    facade_->loadFromFile(file_path.toStdString());
    renderer_->clearMaze();
    renderer_->drawMaze();
  }
}

void MazeTab::initWindow() {
  facade_ = new MazeFacade();
  renderer_ = new MazeRenderer(nullptr, facade_->maze());
  renderer_->show();

  rows_spin_box_ = new QSpinBox(this);
  cols_spin_box_ = new QSpinBox(this);
  open_file_btn_ = new QPushButton("Open file", this);
  generate_btn_ = new QPushButton("Generate", this);
  save_btn_ = new QPushButton("Save", this);
  solve_btn_ = new QPushButton("Solve", this);

  start_row_spin_box_ = new QSpinBox(this);
  start_col_spin_box_ = new QSpinBox(this);
  end_row_spin_box_ = new QSpinBox(this);
  end_col_spin_box_ = new QSpinBox(this);

  open_file_btn_->setStyleSheet(Settings::btn_style);
  generate_btn_->setStyleSheet(Settings::btn_style);
  save_btn_->setStyleSheet(Settings::btn_style);
  solve_btn_->setStyleSheet(Settings::btn_style);
  rows_spin_box_->setStyleSheet(Settings::spinbox_style);
  cols_spin_box_->setStyleSheet(Settings::spinbox_style);
  start_row_spin_box_->setStyleSheet(Settings::spinbox_style);
  start_col_spin_box_->setStyleSheet(Settings::spinbox_style);
  end_row_spin_box_->setStyleSheet(Settings::spinbox_style);
  end_col_spin_box_->setStyleSheet(Settings::spinbox_style);
}

void MazeTab::setupLayouts() {
  QGridLayout* settings_layout = new QGridLayout();
  QGridLayout* button_layout = new QGridLayout();
  QVBoxLayout* main_layout = new QVBoxLayout(this);

  setupButtonLayout(button_layout);
  setupSettingsLayout(settings_layout);
  main_layout->addStretch(1);
  main_layout->addLayout(settings_layout);
  main_layout->addStretch(1);
  main_layout->addLayout(button_layout);
  setLayout(main_layout);
}

void MazeTab::setupButtonLayout(QGridLayout* button_layout) {
  button_layout->addWidget(open_file_btn_, 0, 0);
  button_layout->addWidget(save_btn_, 1, 0);
  button_layout->addWidget(generate_btn_, 0, 1);
  button_layout->addWidget(solve_btn_, 1, 1);
}

void MazeTab::setupSettingsLayout(QGridLayout* settings_layout) {
  QLabel* rows_label = new QLabel("ROWS", this);
  QLabel* cols_label = new QLabel("COLS", this);
  QLabel* start_label = new QLabel("START (row, col)", this);
  QLabel* end_label = new QLabel("END (row, col)", this);

  rows_label->setStyleSheet(Settings::label_style);
  cols_label->setStyleSheet(Settings::label_style);
  start_label->setStyleSheet(Settings::label_style);
  end_label->setStyleSheet(Settings::label_style);

  settings_layout->addWidget(rows_label, 0, 0);
  settings_layout->addWidget(rows_spin_box_, 0, 1);
  settings_layout->addWidget(cols_label, 1, 0);
  settings_layout->addWidget(cols_spin_box_, 1, 1);
  settings_layout->addWidget(start_label, 2, 0);
  settings_layout->addWidget(start_row_spin_box_, 2, 1);
  settings_layout->addWidget(start_col_spin_box_, 2, 2);
  settings_layout->addWidget(end_label, 3, 0);
  settings_layout->addWidget(end_row_spin_box_, 3, 1);
  settings_layout->addWidget(end_col_spin_box_, 3, 2);
}

}  // namespace s21
