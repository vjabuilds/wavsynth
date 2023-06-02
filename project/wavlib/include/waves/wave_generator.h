#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

namespace wavlib::waves {
    class WaveGenerator {
        protected:
        unsigned int sample_count;
        std::vector<double> waveform; 
        const int sampling_freq = 44100;
        virtual double generate(unsigned int sample) = 0;

        public:
        double* begin() {return &(waveform[0]);}
        double* end() {return &(waveform[waveform.size() - 1]) + 1;}

        WaveGenerator(unsigned int sc = 44100): sample_count(sc), waveform(sc) 
        {
            std::iota(waveform.begin(), waveform.end(), 0);
        };

        void populate()
        {
            std::transform(waveform.begin(), waveform.end(), waveform.begin(), [this](double s){return this->generate(s);});
        }

        virtual ~WaveGenerator(){};
    };
}