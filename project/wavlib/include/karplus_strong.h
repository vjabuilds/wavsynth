#include <vector>
#include <memory>

#include "waves/wave_generator.h"
#include "waves/sampler.h"

namespace wavlib {
    class KarplusStrongSynth {
        public:
        double* begin();
        double* end();
        void generate(int samples);
        KarplusStrongSynth(std::shared_ptr<waves::WaveGenerator> gen, double freq): sampler(gen, freq), freq(freq) {}

        private:
        std::vector<double> raw_data;
        double freq;
        waves::Sampler sampler;
    };
}