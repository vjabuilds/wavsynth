#include "karplus_strong.h"

#include <random>

using namespace wavlib;
using namespace std;

double *KarplusStrongSynth::begin()
{
    return &(raw_data[0]);
}

double *KarplusStrongSynth::end()
{
    return &(raw_data[raw_data.size() - 1]) + 1;
}

void KarplusStrongSynth::generate(int samples)
{
    auto wt = sampler.vals(int(44100 / freq));
    double prev_val = 0;    
    default_random_engine engine;
    binomial_distribution<int> dist(1, 1 - (1.0 / 1.1));
    for(int curr = 0, sample = 0; curr < samples; curr++, sample = (sample + 1) % wt.size())
    {
        int r = dist(engine);
        double new_sample = 0.5 * (wt[sample] + prev_val);
        if (r == 0)
            wt[sample] = new_sample;
        raw_data.push_back(wt[sample]);
        prev_val = new_sample;
    }
}
