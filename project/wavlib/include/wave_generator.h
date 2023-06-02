namespace wavlib {
    class WaveGenerator {
        private:
        unsigned int sample_count;
        public:
        virtual double* begin() = 0;
        virtual double* end() = 0;
        virtual double generate(unsigned int sample) = 0;
        WaveGenerator(unsigned int sc): sample_count(sc) {};
        virtual ~WaveGenerator(){};
    };
}

