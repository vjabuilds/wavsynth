#include <fstream>
#include <string>

namespace wavlib {
    class WavOStream {
        public:
        WavOStream(const std::string&);
        virtual ~WavOStream();
        void insert_data(int16_t);

        private:
        std::ofstream wav_file;
        std::string file_name;

        unsigned int data_size = 0;
        unsigned int header_size_position = 0;
        unsigned int data_size_position = 0;

        void write_preamble();
        template<typename T> void write_data(const T& data);
        protected:
    };
}