/**
 * @file cave_tab.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the CaveTab class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_CAVE_TAB_H_
#define SRC_INCLUDE_VIEW_CAVE_TAB_H_

#include <QWidget>

namespace s21 {

class CaveTab : public QWidget {
  Q_OBJECT

 public:
  explicit CaveTab(QWidget* parent = nullptr);
  ~CaveTab();
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_CAVE_TAB_H_
