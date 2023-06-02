#include <algorithm>
#include <numeric>

#include "waves/sawtooth_wave.h"

using namespace wavlib::waves;

double SawtoothWave::generate(unsigned int sample)
{
    return sample / double(sample_count);
}
