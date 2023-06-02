#include <algorithm>
#include <numeric>
#include <random>

#include "waves/white_noise.h"

using namespace wavlib::waves;

double WhiteNoise::generate(unsigned int sample)
{
    return dist(engine);
}
