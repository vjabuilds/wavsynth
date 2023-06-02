#include "waves/sampler.h"

#include <iostream>

double *wavlib::waves::Sampler::begin()
{
    return wg->begin();
}

double *wavlib::waves::Sampler::end()
{
    return wg->end();
}

std::vector<double> wavlib::waves::Sampler::vals(int num_samples)
{
    int curr = 0;
    std::vector<double> result;
    wg->populate();
    std::vector<double> local(wg->begin(), wg->end());

    for(int i=0;i<num_samples;i++)
    {
        result.push_back(local[curr]);
        curr += freq;
        curr = curr % local.size();
    }
    return result;
}
