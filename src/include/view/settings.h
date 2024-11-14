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

/**
 * @class Settings
 * @brief Contains various settings for the application's UI.
 */
class Settings {
 public:
  /**
   * @brief Background style for the widget.
   */
  static constexpr const char* background_style =
      "QWidget { background-color: #171421; }";

  /**
   * @brief Width of the buttons.
   */
  static constexpr int btn_width = 150;

  /**
   * @brief Height of the buttons.
   */
  static constexpr int btn_height = 50;

  /**
   * @brief Style for the buttons.
   */
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

  /**
   * @brief Style for the spin boxes.
   */
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

  /**
   * @brief Green color code.
   */
  static constexpr const char* green = "#26A168";

  /**
   * @brief Black color code.
   */
  static constexpr const char* black = "#171421";

  /**
   * @brief Size of the render area.
   */
  static constexpr int render_size = 500;
};
}  // namespace s21

#endif  // SRC_INCLUDE_VIEW_SETTINGS_H_
