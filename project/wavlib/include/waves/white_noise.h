#pragma once

#include <vector>
#include <random>

#include "wave_generator.h"

namespace wavlib::waves {
    class WhiteNoise : public WaveGenerator {
        private:
        std::vector<double> data;
        std::default_random_engine engine;
        std::normal_distribution<double> dist;
        public:
        WhiteNoise(unsigned int, double);
        double* begin();
        double* end();
        double generate(unsigned int sample);
    };
}