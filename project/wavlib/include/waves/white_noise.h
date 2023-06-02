#pragma once

#include <vector>
#include <random>

#include "wave_generator.h"

namespace wavlib::waves {
    class WhiteNoise : public WaveGenerator {
        private:
        std::default_random_engine engine;
        std::normal_distribution<double> dist;
        public:
        using WaveGenerator::WaveGenerator;
        double generate(unsigned int sample);
    };
}