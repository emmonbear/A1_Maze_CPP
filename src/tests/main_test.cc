/**
 * @file main_test.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Implementation file for the main test suite
 * @version 1.0
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/main_test.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  if (argc > 1) {
    ::testing::GTEST_FLAG(filter) = argv[1];
  }

  return RUN_ALL_TESTS();
}
