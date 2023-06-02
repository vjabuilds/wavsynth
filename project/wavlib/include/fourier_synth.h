#include <vector>
#include <memory>

#include "waves/wave_generator.h"

namespace wavlib {
    class FourierSynth {
        public:
        using dtype = std::pair<double, std::shared_ptr<waves::WaveGenerator>>;
        FourierSynth(std::vector<dtype> waves): waves(waves){}

        double* begin();
        double* end();
        void generate();

        private:
        std::vector<dtype> waves;
        std::vector<double> raw_data;
    };
}