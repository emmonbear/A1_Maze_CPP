/**
 * @file settings.h
 * @author Moskalev Ilya (moskalevilua1998@gmail.com)
 * @brief Header file for the Settings class
 * @version 1.0
 * @date 2024-11-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_VIEW_SETTINGS_H_
#define SRC_INCLUDE_VIEW_SETTINGS_H_

namespace s21 {

class Settings {
 public:
  static constexpr const char* background_style =
      "QWidget { background-color: #171421; }";

  static constexpr int btn_width = 150;
  static constexpr int btn_height = 50;
  static constexpr const char* btn_style =
      "QPushButton { "
      "background-color: #26A168; "
      "color: #171421; "
      "height: 50px; "
      "font-family: 'Arial'; "
      "font-size: 24px; "
      "font-weight: bold; "
      "} "
      "QPushButton:hover { "
      "background-color: #171421; "
      "color: #26A168; "
      "}";

  static constexpr const char* tab_style =
      "QTabWidget::pane { "
      "border: 1px solid #171421; "
      "} "
      "QTabBar::tab { "
      "background-color: #171421; "
      "color: #26A168; "
      "font-weight: bold; "
      "font-size: 28px; "
      "border: none; "
      "border-top-left-radius: 10px; "
      "border-top-right-radius: 10px; "
      "min-width: 120px; "
      "padding: 10px; "
      "} "
      "QTabBar::tab:selected { "
      "background-color: #26A168; "
      "color: #171421; "
      "font-weight: bold; "
      "font-size: 28px; "
      "border: none; "
      "border-top-left-radius: 10px; "
      "border-top-right-radius: 10px; "
      "}";

  static constexpr const char* spinbox_style =
      "QSpinBox { "
      "background-color: #171421; "
      "color: #ffffff; "
      "font-family: 'Arial'; "
      "font-size: 24px; "
      "font-weight: bold; "
      "border: 2px solid #ffffff; "
      "padding: 5px; "
      "} "
      "QSpinBox::up-button, QSpinBox::down-button { "
      "background-color: #ffffff; "
      "width: 20px; "
      "border: none; "
      "} "
      "QSpinBox::up-button:hover, QSpinBox::down-button:hover { "
      "background-color: #26A168; "
      "} "
      "QSpinBox::up-arrow, QSpinBox::down-arrow { "
      "width: 10px; "
      "height: 10px; "
      "background-color: #171421; "
      "}";

  static constexpr const char* map_style = "border: 2px color: #171421";
  static constexpr const char* green = "#26A168";
  static constexpr const char* black = "#171421";
  static constexpr int render_size = 500;
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SETTINGS_H_
