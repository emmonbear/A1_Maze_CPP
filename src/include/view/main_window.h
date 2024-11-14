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

#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

#include "include/controller/facade.h"
#include "include/view/renderer.h"

namespace s21 {

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  void initWindow();

 private slots:
  void onOpenFileButtonClicked();
  void onGenerateButtonClicked();
  void onSaveButtonClicked();
  void onSolveButtonClicked();

 private:
  Facade* facade_;
  Renderer* renderer_;

  QPushButton* open_file_btn_;
  QPushButton* generate_btn_;
  QPushButton* save_btn_;
  QPushButton* solve_btn_;
  QSpinBox* rows_spin_box_;
  QSpinBox* cols_spin_box_;
  QSpinBox* start_row_spin_box_;
  QSpinBox* start_col_spin_box_;
  QSpinBox* end_row_spin_box_;
  QSpinBox* end_col_spin_box_;

  void setupLayouts();
  void setupVerticalLayout(QVBoxLayout* v_layout);
  void setupButtonLayout(QGridLayout* button_layout);
  void updateSolveSpinBoxRanges();
  void updateGenerateSpinBoxRanges();
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_MAIN_WINDOW_H_
