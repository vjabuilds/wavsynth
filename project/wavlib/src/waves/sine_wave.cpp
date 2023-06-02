#include <numeric>
#include <cmath>
#include <algorithm>

#include "waves/sine_wave.h"

using namespace wavlib::waves;

double SineWave::generate(unsigned int sample)
{
    return sin((2 * M_PI * sample) / sample_count);
}