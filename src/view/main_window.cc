/**
 * @file maze_tab.cc
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Implementation file for the MainWindow class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/view/main_window.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QSpinBox>
#include <QVBoxLayout>

#include "include/view/settings.h"

namespace s21 {

/**
 * @brief Constructs a MainWindow object.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  initWindow();
  setupLayouts();

  connect(open_file_btn_, &QPushButton::clicked, this,
          &MainWindow::onOpenFileButtonClicked);

  connect(generate_btn_, &QPushButton::clicked, this,
          &MainWindow::onGenerateButtonClicked);

  connect(save_btn_, &QPushButton::clicked, this,
          &MainWindow::onSaveButtonClicked);

  connect(solve_btn_, &QPushButton::clicked, this,
          &MainWindow::onSolveButtonClicked);
}

MainWindow::~MainWindow() { delete facade_; }

/**
 * @brief Handles the click event of the open file button.
 */
void MainWindow::onOpenFileButtonClicked() {
  QString file_path = QFileDialog::getOpenFileName(
      nullptr, "Open Maze File", "../datasets", "Text Files (*.txt)");

  if (!file_path.isEmpty()) {
    try {
      facade_->loadFromFile(file_path.toStdString());
      renderer_->clearMaze();
      renderer_->drawMaze();
      updateGenerateSpinBoxRanges();
      updateSolveSpinBoxRanges();
    } catch (const std::runtime_error& e) {
      setUpMessageBox("File upload error",
                      QString("Incorrect file format: %1").arg(e.what()));
    }
  }
}

/**
 * @brief Handles the click event of the generate button.
 */
void MainWindow::onGenerateButtonClicked() {
  renderer_->clearMaze();
  facade_->generate(rows_spin_box_->value(), cols_spin_box_->value());
  renderer_->drawMaze();
  updateSolveSpinBoxRanges();
}

/**
 * @brief Handles the click event of the save button.
 */
void MainWindow::onSaveButtonClicked() {
  QString file_path = QFileDialog::getSaveFileName(nullptr, "", "../datasets",
                                                   "Text Files (*.txt)");
  if (!file_path.isEmpty()) {
    if (!file_path.endsWith(".txt")) {
      file_path += ".txt";
    }
    facade_->saveTofile(file_path.toStdString());
  }
}

/**
 * @brief Handles the click event of the solve button.
 */
void MainWindow::onSolveButtonClicked() {
  int start_row = start_row_spin_box_->value();
  int start_col = start_col_spin_box_->value();
  int end_row = end_row_spin_box_->value();
  int end_col = end_col_spin_box_->value();

  try {
    facade_->solve({start_row, start_col}, {end_row, end_col});
    renderer_->drawPath();
  } catch (const std::runtime_error& e) {
    setUpMessageBox("Maze solve error", QString(e.what()));
  }
}

/**
 * @brief Initializes the main window.
 */
void MainWindow::initWindow() {
  facade_ = new Facade();
  renderer_ = new Renderer(this, facade_->maze());

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

  open_file_btn_->setStyleSheet(Settings::kBtnStyle);
  generate_btn_->setStyleSheet(Settings::kBtnStyle);
  save_btn_->setStyleSheet(Settings::kBtnStyle);
  solve_btn_->setStyleSheet(Settings::kBtnStyle);
  rows_spin_box_->setStyleSheet(Settings::kSpinboxStyle);
  cols_spin_box_->setStyleSheet(Settings::kSpinboxStyle);
  start_row_spin_box_->setStyleSheet(Settings::kSpinboxStyle);
  start_col_spin_box_->setStyleSheet(Settings::kSpinboxStyle);
  end_row_spin_box_->setStyleSheet(Settings::kSpinboxStyle);
  end_col_spin_box_->setStyleSheet(Settings::kSpinboxStyle);

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

  setFixedSize(750, 660);
  setStyleSheet(Settings::kBackgroundStyle);
}

/**
 * @brief Sets up the layouts for the main window.
 */
void MainWindow::setupLayouts() {
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

/**
 * @brief Sets up the vertical layout.
 * @param v_layout The vertical layout to set up.
 */
void MainWindow::setupVerticalLayout(QVBoxLayout* v_layout) {
  QLabel* generate_label = new QLabel("GENERATE", this);
  QLabel* solve_label = new QLabel("SOLVE", this);
  QLabel* rows_label = new QLabel("Rows:", this);
  QLabel* cols_label = new QLabel("Cols:", this);
  QLabel* start_label = new QLabel("Start:", this);
  QLabel* end_label = new QLabel("End:", this);

  generate_label->setAlignment(Qt::AlignCenter);
  generate_label->setStyleSheet(Settings::kGreenLabelStyle);
  solve_label->setAlignment(Qt::AlignCenter);
  solve_label->setStyleSheet(Settings::kGreenLabelStyle);
  start_label->setStyleSheet(Settings::kWhiteLabelStyle);
  end_label->setStyleSheet(Settings::kWhiteLabelStyle);
  rows_label->setStyleSheet(Settings::kWhiteLabelStyle);
  cols_label->setStyleSheet(Settings::kWhiteLabelStyle);
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

/**
 * @brief Sets up the button layout.
 * @param button_layout The button layout to set up.
 */
void MainWindow::setupButtonLayout(QGridLayout* button_layout) {
  button_layout->addWidget(open_file_btn_, 0, 0);
  button_layout->addWidget(save_btn_, 1, 0);
  button_layout->addWidget(generate_btn_, 0, 1);
  button_layout->addWidget(solve_btn_, 1, 1);
}

/**
 * @brief Updates the ranges of the solve spin boxes.
 */
void MainWindow::updateSolveSpinBoxRanges() {
  int rows = facade_->maze().rows() - 1;
  int cols = facade_->maze().cols() - 1;
  start_row_spin_box_->setMinimum(0);
  start_col_spin_box_->setMinimum(0);
  end_row_spin_box_->setMinimum(0);
  end_col_spin_box_->setMinimum(0);

  start_row_spin_box_->setMaximum(rows);
  start_col_spin_box_->setMaximum(cols);
  start_row_spin_box_->setValue(0);
  start_col_spin_box_->setValue(0);

  end_row_spin_box_->setMaximum(rows);
  end_col_spin_box_->setMaximum(cols);

  end_row_spin_box_->setValue(rows);
  end_col_spin_box_->setValue(cols);
}

/**
 * @brief Updates the ranges of the generate spin boxes.
 */
void MainWindow::updateGenerateSpinBoxRanges() {
  rows_spin_box_->setValue(facade_->maze().rows());
  cols_spin_box_->setValue(facade_->maze().cols());
}

void MainWindow::setUpMessageBox(const QString& title, const QString& text) {
  QMessageBox messageBox;
  messageBox.setIcon(QMessageBox::Critical);
  messageBox.setWindowTitle(title);
  messageBox.setText(text);
  messageBox.setStyleSheet(Settings::kMessageBoxStyle);
  messageBox.exec();
}
}  // namespace s21
