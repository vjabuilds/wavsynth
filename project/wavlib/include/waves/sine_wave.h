#pragma once

#include <vector>

#include "wave_generator.h"

namespace wavlib::waves {
    class SineWave : public WaveGenerator {
        public:
        using WaveGenerator::WaveGenerator;
        virtual double generate(unsigned int sample);
    };
}