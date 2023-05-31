#include <fstream>
#include <string>
#include <iostream>

#include "wav_ostream.h"

using namespace wavlib;

WavOStream::WavOStream(const std::string& fn): file_name(fn)
{
    this->wav_file = std::ofstream(fn, std::ofstream::app | std::ofstream::out);
    write_preamble();
}

void WavOStream::write_preamble() 
{
    wav_file << "This is nice!" << std::endl;
}

WavOStream::~WavOStream()
{
    wav_file.close();
}