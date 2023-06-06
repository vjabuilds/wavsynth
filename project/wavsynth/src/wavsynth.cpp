#include "wav_ostream.h"
#include "waves/sine_wave.h"
#include "waves/square_wave.h"
#include "waves/sawtooth_wave.h"
#include "waves/white_noise.h"
#include "waves/sampler.h"
#include "karplus_strong.h"
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

  // Sampler samp(make_shared<SquareWave>(SquareWave()), 110);
  // auto data = samp.vals(441000);
  // stream.insert_data(data.begin(), data.end());

  vector<double> freqs = {98, 123, 147, 196, 294, 392, 294, 196, 147, 123, 98};
  for(auto f: freqs)
  {
    KarplusStrongSynth samp(make_shared<WhiteNoise>(WhiteNoise()), f);
    samp.generate(44100 / 2);
    stream.insert_data(samp.begin(), samp.end());
  }
  // vector<double> freqs = {98, 123, 147, 196, 294, 392, 294, 196, 147, 123, 98};
  // KarplusStrongSynth samp(make_shared<WhiteNoise>(WhiteNoise()), 220);
  // samp.generate(441000);
  // stream.insert_data(samp.begin(), samp.end());

  return 0;
}
