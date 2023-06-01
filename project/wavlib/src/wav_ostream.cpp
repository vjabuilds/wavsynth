#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "wav_ostream.h"

using namespace wavlib;

template<>
void WavOStream::write_data(const decltype("nice")& data)
{
    wav_file.write(data, sizeof(data) - 1);
}

template<>
void WavOStream::write_data(const std::string& data)
{
    wav_file.write(data.c_str(), data.length());
}

WavOStream::WavOStream(const std::string& fn): file_name(fn)
{
    this->wav_file = std::ofstream(fn, std::ofstream::binary | std::ofstream::out);
    write_preamble();
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
    this->header_size_position = this->wav_file.tellp();
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
    this->data_size_position = this->wav_file.tellp();
    write_data(int32_t(0));
}

WavOStream::~WavOStream()
{
    this->wav_file.seekp(this->header_size_position, std::ofstream::beg);
    write_data(int32_t(32 + this->data_size));
    this->wav_file.seekp(this->data_size_position, std::ofstream::beg);
    write_data(int32_t(this->data_size));
    wav_file.close();
}

void wavlib::WavOStream::insert_data(double data)
{
    insert_data(int16_t(data * 32000));
}

void WavOStream::insert_data(int16_t data)
{
    write_data(data);
    write_data(data);
    data_size += 2 * sizeof(int16_t);
}