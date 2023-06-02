#include <algorithm>
#include <numeric>

#include "fourier_synth.h"

using namespace wavlib;
using namespace std;

double *FourierSynth::begin()
{
    return &(raw_data[0]);
}

double *FourierSynth::end()
{
    return &(raw_data[raw_data.size() - 1]) + 1;
}

void FourierSynth::generate()
{
    using f_args = pair<double*, double>;
    vector<f_args> begs(waves.size());
    transform(
                waves.begin(), 
                waves.end(), 
                begs.begin(),  
                [](dtype wave)
                {
                    return f_args(wave.second->begin(), wave.first);
                }
            );
    auto end = waves[0].second->end();
    while(begs[0].first != end) {
        vector<double> local(begs.size());
        transform(begs.begin(), begs.end(), local.begin(), [](f_args& x) 
        {
            return *(x.first++) * x.second;
        }
        );
        raw_data.push_back(accumulate(local.begin(), local.end(), 0.0));
    }
}