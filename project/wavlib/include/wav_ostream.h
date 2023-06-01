#pragma once
#include <fstream>
#include <string>

namespace wavlib {
    class WavOStream {
        private:
        std::ofstream wav_file;
        std::string file_name;

        unsigned int data_size = 0;
        unsigned int header_size_position = 0;
        unsigned int data_size_position = 0;
        
        template <typename T>
        void write_data(const T &data);

        void write_preamble();

        public:
        WavOStream(const std::string&);
        virtual ~WavOStream();
        void insert_data(int16_t);
        void insert_data(double);
        template<typename T> void insert_data(T, T);

        protected:
    };

    template<typename T> 
    void WavOStream::write_data(const T& data)
    {
        wav_file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    }

    template <typename T>
    void WavOStream::insert_data(T beg, T end)
    {
        for(auto t=beg; t!=end; ++t)
        {
            auto data = *t;
            insert_data(data);
        }
    }
}

