#pragma once

#include <vector>

#include "wave_generator.h"

namespace wavlib {
    class SquareWave : public WaveGenerator {
        private:
        double frequency;
        std::vector<double> data;
        public:
        SquareWave(unsigned int, double);
        double* begin();
        double* end();
        double generate(unsigned int sample);
    };
}