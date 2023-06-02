#include <algorithm>
#include <numeric>
#include <random>

#include "waves/white_noise.h"

using namespace wavlib::waves;

WhiteNoise::WhiteNoise(unsigned int sample_count, double f): WaveGenerator(sample_count), data(sample_count), dist(0, 1)
{
    std::iota(data.begin(), data.end(), 0);
    std::transform(data.begin(), data.end(), data.begin(), [this](double s){return generate(s);});
}

double *WhiteNoise::begin()
{
    return &(data[0]);
}

double *WhiteNoise::end()
{
    return &(data[data.size() - 1]) + 1;
}

double WhiteNoise::generate(unsigned int sample)
{
    return dist(engine);
}
