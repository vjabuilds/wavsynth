#include "wav_ostream.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace wavlib;

int main() {
  WavOStream stream("test.wav");
  const int sample_rate = 44100;
  const std::vector<double> freqs = {440.0, 493.88, 554.37, 587.33, 659.25, 739.99, 783.99, 880, 880, 880, 880, 880};
  int curr_ind = 0;
  double factor = M_PI * 2 * freqs[curr_ind] / sample_rate;
    
  for(int i=0;i<sample_rate * 10;i++)
  {
      if(i && i % sample_rate == 0)
      {
          curr_ind++;
          factor = M_PI * 2 * freqs[curr_ind] / sample_rate;
      }
      
      int16_t data = int16_t(sin(factor * i) * 16000);
      if(i % sample_rate < sample_rate * 0.5)
        stream.insert_data(data);
      else
        stream.insert_data(0);
  }

  return 0;
}
