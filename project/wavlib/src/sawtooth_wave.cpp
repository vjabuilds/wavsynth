#include <algorithm>
#include <numeric>

#include "sawtooth_wave.h"

using namespace wavlib;

SawtoothWave::SawtoothWave(unsigned int sample_count, double f): WaveGenerator(sample_count), data(sample_count), frequency(f)
{
    std::iota(data.begin(), data.end(), 0);
    std::transform(data.begin(), data.end(), data.begin(), [this](double s){return generate(s);});
}

double *SawtoothWave::begin()
{
    return &(data[0]);
}

double *SawtoothWave::end()
{
    return &(data[data.size() - 1]) + 1;
}

double SawtoothWave::generate(unsigned int sample)
{
    auto test = int(44100 / frequency); // samples per full oscilattion
    double inverse = 1.0 / test;
    return inverse * (sample % test);
}
