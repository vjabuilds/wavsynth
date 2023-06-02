#include "wav_ostream.h"
#include "waves/sine_wave.h"
#include "waves/square_wave.h"
#include "waves/sawtooth_wave.h"
#include "waves/white_noise.h"
#include "waves/sampler.h"
#include "fourier_synth.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace wavlib;
using namespace wavlib::waves;
using namespace std;

int main() {
  WavOStream stream("test.wav");
  const int sample_rate = 44100;
  Sampler samp(make_shared<SineWave>(SineWave()), 440);
  auto data = samp.vals(441000);
  stream.insert_data(data.begin(), data.end());

  return 0;
}
