#include "wav_ostream.h"
#include "sine_wave.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace wavlib;

int main() {
  WavOStream stream("test.wav");
  const int sample_rate = 44100;
  SineWave sw(sample_rate * 10, 440);
  stream.insert_data(sw.begin(), sw.end());

  return 0;
}
