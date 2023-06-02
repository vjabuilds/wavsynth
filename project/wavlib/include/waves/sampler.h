#pragma once

#include <memory>
#include <vector>

#include "wave_generator.h"

namespace wavlib::waves {
    class Sampler {
        public:
        Sampler(std::shared_ptr<WaveGenerator> wg, double freq):wg(wg), freq(freq){}
        double* begin();
        double* end();
        std::vector<double> vals(int num_samples);


        private:
        const int sample_rate = 44100;
        double freq;
        std::shared_ptr<WaveGenerator> wg;
    };
}