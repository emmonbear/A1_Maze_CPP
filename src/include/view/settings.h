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

  static constexpr const char* map_style = "border: 2px color: #171421";
  static constexpr const char* green = "#26A168";
  static constexpr const char* black = "#171421";
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SETTINGS_H_
