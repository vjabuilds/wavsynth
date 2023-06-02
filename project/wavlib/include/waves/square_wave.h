#pragma once

#include <vector>

#include "wave_generator.h"

namespace wavlib::waves {
    class SquareWave : public WaveGenerator {
        public:
        using WaveGenerator::WaveGenerator;
        double generate(unsigned int sample);
    };
}