#include <algorithm>
#include <numeric>
#include <cmath>

#include "waves/square_wave.h"

using namespace wavlib::waves;

double SquareWave::generate(unsigned int sample)
{
    return sample < (sample_count / 2) ? -1 : 1;
}
