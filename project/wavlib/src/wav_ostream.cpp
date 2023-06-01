#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "wav_ostream.h"

using namespace wavlib;

WavOStream::WavOStream(const std::string& fn): file_name(fn)
{
    this->wav_file = std::ofstream(fn, std::ofstream::binary | std::ofstream::out);
    write_preamble();
}

template<typename T> 
void WavOStream::write_data(const T& data)
{
    wav_file.write(reinterpret_cast<const char*>(&data), sizeof(data));
}

template<>
void WavOStream::write_data(const std::string& data)
{
    wav_file.write(data.c_str(), data.length());
}

template<>
void WavOStream::write_data(const decltype("nice")& data)
{
    wav_file.write(data, sizeof(data) - 1);
}

void WavOStream::write_preamble() 
{

    const int sample_rate = 44100;
    const int bits_per_sample = 16;
    const int format_lenght = 16;

    const int format = 1;
    const int channels = 2;

    const int bps = sample_rate * bits_per_sample * channels / 8;

    write_data("RIFF");
    //write_data(int32_t(44 + bps * 10 - 8));
    write_data(int32_t(0));
    write_data("WAVE");
    write_data("fmt ");
    write_data(int32_t(format_lenght));

    write_data(int16_t(format));
    write_data(int16_t(channels));

    write_data(int32_t(sample_rate));
    write_data(int32_t(bps));

    write_data(int16_t(bits_per_sample * channels / 8));
    write_data(int16_t(bits_per_sample));
    write_data("data");
    //write_data(bps * 10);
    write_data(0);

    // const double freq = 220.0;
    // const std::vector<double> freqs = {440.0, 493.88, 554.37, 587.33, 659.25, 739.99, 783.99, 880, 880, 880, 880, 880};
    // int curr_ind = 0;
    // double factor = M_PI * 2 * freqs[curr_ind] / sample_rate;
    
    // for(int i=0;i<sample_rate * 10;i++)
    // {
    //     if(i && i % sample_rate == 0)
    //     {
    //         curr_ind++;
    //         factor = M_PI * 2 * freqs[curr_ind] / sample_rate;
    //     }
        
    //     int16_t data = int16_t(sin(factor * i) * 32000);
    //     write_data(data);
    //     write_data(data);
    // }
}

WavOStream::~WavOStream()
{
    wav_file.close();
}