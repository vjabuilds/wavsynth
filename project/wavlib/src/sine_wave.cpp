#include <numeric>
#include <cmath>
#include <algorithm>

#include "sine_wave.h"

using namespace wavlib;

double SineWave::generate(unsigned int sample)
{
    return sin(2 * M_PI * sample * frequency / 44100);
}

SineWave::SineWave(unsigned int sample_count, double f): WaveGenerator(sample_count), data(sample_count), frequency(f)
{
    std::iota(data.begin(), data.end(), 0);
    std::transform(data.begin(), data.end(), data.begin(), [this](double s){return generate(s);});
}

double *SineWave::begin()
{
    return &(data[0]);
}

double* SineWave::end()
{
    return &(data[data.size() - 1]) + 1;
}
