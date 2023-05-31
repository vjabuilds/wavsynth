#include <fstream>
#include <string>

namespace wavlib {
    class WavOStream {
        public:
        WavOStream(const std::string&);
        virtual ~WavOStream();

        private:
        std::ofstream wav_file;
        std::string file_name;

        void write_preamble();
        template<typename T> void write_data(const T& data);
        protected:
    };
}