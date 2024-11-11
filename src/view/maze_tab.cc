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
#include <QFormLayout>
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

  connect(generate_btn_, &QPushButton::clicked, this,
          &MazeTab::onGenerateButtonClicked);

  connect(save_btn_, &QPushButton::clicked, this,
          &MazeTab::onSaveButtonClicked);

  connect(solve_btn_, &QPushButton::clicked, this,
          &MazeTab::onSolveButtonClicked);
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

void MazeTab::onGenerateButtonClicked() {
  renderer_->clearMaze();
  facade_->generate(rows_spin_box_->value(), cols_spin_box_->value());
  renderer_->drawMaze();
}

void MazeTab::onSaveButtonClicked() {}

void MazeTab::onSolveButtonClicked() {}

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
  solve_btn_->setStyleSheet(Settings::btn_style);
  rows_spin_box_->setStyleSheet(Settings::spinbox_style);
  cols_spin_box_->setStyleSheet(Settings::spinbox_style);
  start_row_spin_box_->setStyleSheet(Settings::spinbox_style);
  start_col_spin_box_->setStyleSheet(Settings::spinbox_style);
  end_row_spin_box_->setStyleSheet(Settings::spinbox_style);
  end_col_spin_box_->setStyleSheet(Settings::spinbox_style);

  rows_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  cols_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  start_row_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  start_col_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  end_row_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  end_col_spin_box_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  rows_spin_box_->setMinimum(2);
  rows_spin_box_->setMaximum(50);
  cols_spin_box_->setMinimum(2);
  cols_spin_box_->setMaximum(50);
}

void MazeTab::setupLayouts() {
  QVBoxLayout* main_layout = new QVBoxLayout(this);
  QHBoxLayout* h_layout = new QHBoxLayout();
  QVBoxLayout* v_layout = new QVBoxLayout();
  QGridLayout* button_layout = new QGridLayout();

  setupVerticalLayout(v_layout);
  setupButtonLayout(button_layout);
  h_layout->addWidget(renderer_);
  h_layout->addSpacerItem(
      new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
  h_layout->addLayout(v_layout);

  main_layout->addStretch(1);
  main_layout->addLayout(h_layout);
  main_layout->addStretch(1);
  main_layout->addLayout(button_layout);
  setLayout(main_layout);
}

void MazeTab::setupVerticalLayout(QVBoxLayout* v_layout) {
  QLabel* generate_label = new QLabel("GENERATE", this);
  QLabel* solve_label = new QLabel("SOLVE", this);
  QLabel* rows_label = new QLabel("Rows:", this);
  QLabel* cols_label = new QLabel("Cols:", this);
  QLabel* start_label = new QLabel("Start:", this);
  QLabel* end_label = new QLabel("End:", this);

  generate_label->setAlignment(Qt::AlignCenter);
  generate_label->setStyleSheet(
      "font-weight: bold; color: #26A168;font-size: 24px;");
  solve_label->setAlignment(Qt::AlignCenter);
  solve_label->setStyleSheet(
      "font-weight: bold; color: #26A168;font-size: 24px;");
  start_label->setStyleSheet("font-size: 24px;");
  end_label->setStyleSheet("font-size: 24px;");
  rows_label->setStyleSheet("font-size: 24px;");
  cols_label->setStyleSheet("font-size: 24px;");
  v_layout->addWidget(generate_label);

  QFormLayout* generate_form_layout = new QFormLayout();
  generate_form_layout->addRow(rows_label, rows_spin_box_);
  generate_form_layout->addRow(cols_label, cols_spin_box_);

  v_layout->addLayout(generate_form_layout);

  v_layout->addWidget(solve_label);

  QFormLayout* solve_form_layout = new QFormLayout();
  QHBoxLayout* start_hbox_layout = new QHBoxLayout();
  start_hbox_layout->addWidget(start_row_spin_box_);
  start_hbox_layout->addWidget(start_col_spin_box_);
  solve_form_layout->addRow(start_label, start_hbox_layout);

  QHBoxLayout* end_hbox_layout = new QHBoxLayout();
  end_hbox_layout->addWidget(end_row_spin_box_);
  end_hbox_layout->addWidget(end_col_spin_box_);
  solve_form_layout->addRow(end_label, end_hbox_layout);

  v_layout->addLayout(solve_form_layout);
}

void MazeTab::setupButtonLayout(QGridLayout* button_layout) {
  button_layout->addWidget(open_file_btn_, 0, 0);
  button_layout->addWidget(save_btn_, 1, 0);
  button_layout->addWidget(generate_btn_, 0, 1);
  button_layout->addWidget(solve_btn_, 1, 1);
}

}  // namespace s21
