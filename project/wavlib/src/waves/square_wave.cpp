#include <algorithm>
#include <numeric>
#include <cmath>

#include "waves/square_wave.h"

using namespace wavlib::waves;

SquareWave::SquareWave(unsigned int sample_count, double f): WaveGenerator(sample_count), data(sample_count), frequency(f)
{
    std::iota(data.begin(), data.end(), 0);
    std::transform(data.begin(), data.end(), data.begin(), [this](double s){return generate(s);});
}

double *SquareWave::begin()
{
    return &(data[0]);
}

double *SquareWave::end()
{
    return &(data[data.size() - 1]) + 1;
}

double SquareWave::generate(unsigned int sample)
{
    auto test = int(44100 / frequency); // samples per full oscilattion
    return (sample % test < test / 2)? -1 : 1;
}
