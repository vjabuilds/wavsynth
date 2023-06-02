#pragma once

#include <vector>

#include "wave_generator.h"

namespace wavlib::waves {
    class SawtoothWave : public WaveGenerator {
        private:
        double frequency;
        std::vector<double> data;
        public:
        SawtoothWave(unsigned int, double);
        double* begin();
        double* end();
        double generate(unsigned int sample);
    };
}