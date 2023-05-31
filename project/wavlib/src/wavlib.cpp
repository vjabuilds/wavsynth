#include "wavlib.h"

#include <iostream>

using namespace hello;

int32_t wavlib::saySomething(const std::string &something) const noexcept {
  if (something.empty()) {
    std::cerr << "No value passed\n";
    return 1;
  }

  std::cout << something << '\n';
  return 0;
}