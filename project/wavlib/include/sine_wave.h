#include <vector>

#include "wave_generator.h"

namespace wavlib {
    class SineWave : public WaveGenerator {
        private:
        double frequency;
        std::vector<double> data;
        public:
        SineWave(unsigned int, double);
        double* begin();
        double* end();
        double generate(unsigned int sample);
    };
}