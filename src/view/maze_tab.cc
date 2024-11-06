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

  connect(generate_btn_, &QPushButton::clicked, this,
          &MazeTab::onGenerateButtonClicked);

  connect(save_btn_, &QPushButton::clicked, this,
          &MazeTab::onSaveButtonClicked);

  connect(solve_btn_, &QPushButton::clicked, this,
          &MazeTab::onSolveButtonClicked);
}

MazeTab::~MazeTab() { delete facade_; }

void MazeTab::onOpenFileButtonClicked() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open Maze File", "../datasets", "Text Files (*.txt)");

  if (!file_path.isEmpty()) {
    renderer_->clearMaze();
    facade_->loadFromFile(file_path.toStdString());
    renderer_->drawMaze();
  }
}

void MazeTab::onGenerateButtonClicked() {
  renderer_->clearMaze();
  facade_->generate(rows_spin_box_->value(), cols_spin_box_->value());
  renderer_->drawMaze();
}

void MazeTab::onSaveButtonClicked() {
  QString file_path = QFileDialog::getSaveFileName(this, "", "../datasets",
                                                   "Text Files (*.txt)");
  if (!file_path.isEmpty()) {
    if (!file_path.endsWith(".txt")) {
      file_path += ".txt";
    }
    facade_->saveTofile(file_path.toStdString());
  }
}

void MazeTab::onSolveButtonClicked() {
  int start_row = start_row_spin_box_->value();
  int start_col = start_col_spin_box_->value();
  int end_row = end_row_spin_box_->value();
  int end_col = end_col_spin_box_->value();

  facade_->solve({start_row, start_col}, {end_row, end_col});
  renderer_->drawPath();
}

void MazeTab::initWindow() {
  facade_ = new MazeFacade();
  renderer_ = new MazeRenderer(this, facade_->maze());
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

  main_layout->addWidget(renderer_);
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
  layout->addWidget(save_btn_);
  layout->addWidget(solve_btn_);
}
//
void MazeTab::setupSettingsLayout(QGridLayout* layout) {
  QLabel* rows_label = new QLabel("ROWS", this);
  QLabel* cols_label = new QLabel("COLS", this);
  QLabel* start_label = new QLabel("START (x, y)", this);
  QLabel* end_label = new QLabel("END (x, y)", this);

  rows_spin_box_->setRange(2, 500);
  cols_spin_box_->setRange(2, 500);

  rows_label->setFixedWidth(50);
  cols_label->setFixedWidth(50);

  layout->addWidget(rows_label, 0, 0);
  layout->addWidget(rows_spin_box_, 0, 1);

  layout->addWidget(cols_label, 1, 0);
  layout->addWidget(cols_spin_box_, 1, 1);

  layout->addWidget(start_label, 2, 0);
  layout->addWidget(start_row_spin_box_, 2, 1);
  layout->addWidget(start_col_spin_box_, 2, 2);

  layout->addWidget(end_label, 3, 0);
  layout->addWidget(end_row_spin_box_, 3, 1);
  layout->addWidget(end_col_spin_box_, 3, 2);
  layout->setAlignment(Qt::AlignLeft);
}

}  // namespace s21
