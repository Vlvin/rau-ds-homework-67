#pragma once
#include <iostream>

#define SARRSIZE(sarr) sizeof(sarr) / sizeof(*sarr)

#define TEST(name, ...)                                                        \
  std::cout << "[TEST] " << (#name) << ": ";                              \
  __VA_ARGS__ \
  std::cout << "PASSED" << std::endl;



#define CAPTURE_COUT(ss, ...)                                                  \
  {                                                                            \
    auto origcout = std::cout.rdbuf(ss.rdbuf());                               \
    __VA_ARGS__;                                                               \
    std::cout.rdbuf(origcout);                                                 \
  }
