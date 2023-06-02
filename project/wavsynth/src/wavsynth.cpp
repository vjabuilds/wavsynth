#include "wav_ostream.h"
#include "waves/sine_wave.h"
#include "waves/square_wave.h"
#include "waves/sawtooth_wave.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace wavlib;
using namespace wavlib::waves;

int main() {
  WavOStream stream("test.wav");
  const int sample_rate = 44100;
  SawtoothWave sw(sample_rate * 10, 80);
  stream.insert_data(sw.begin(), sw.end());

  return 0;
}
