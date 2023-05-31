#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

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
    const int bps = 176400;

    write_data("RIFF");
    write_data(int32_t(44 + bps));
    write_data("wave");
    write_data("fmt\0");
    write_data(int32_t(16));

    write_data(int16_t(1));
    write_data(int16_t(2));

    write_data(int32_t(sample_rate));
    write_data(int32_t(bps));

    write_data(int16_t(4));
    write_data(int16_t(16));
    write_data("data");
    write_data(bps);
}

WavOStream::~WavOStream()
{
    wav_file.close();
}