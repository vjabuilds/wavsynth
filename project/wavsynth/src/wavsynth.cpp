#include "wav_ostream.h"
#include <iostream>

using namespace wavlib;

int main() {
  WavOStream stream("test.txt");
  std::cout << "Opened this file" << std::endl;
  return 0;
}
