#include "wav_ostream.h"
#include "waves/sine_wave.h"
#include "waves/square_wave.h"
#include "waves/sawtooth_wave.h"
#include "waves/white_noise.h"
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
  auto ptr1 = make_shared<SineWave>(SineWave(sample_rate * 10, 440));
  auto ptr2 = make_shared<SineWave>(SineWave(sample_rate * 10, 880));
  FourierSynth fs(vector<FourierSynth::dtype>{
    {0.33, make_shared<SineWave>(SineWave(sample_rate * 10, 110))},
    {0.33, make_shared<SineWave>(SineWave(sample_rate * 10, 440))},
    {0.33, make_shared<SineWave>(SineWave(sample_rate * 10, 880))}
  });
  fs.generate();
  stream.insert_data(fs.begin(), fs.end());

  return 0;
}
