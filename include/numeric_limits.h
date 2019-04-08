#ifndef NSTL_NUMERIC_LIMITS_H
#define NSTL_NUMERIC_LIMITS_H

namespace nstl {
    template <class T> class numeric_limits;
    template<> class numeric_limits<bool>;
    template<> class numeric_limits<char>;
    template<> class numeric_limits<signed char>;
    template<> class numeric_limits<unsigned char>;
    template<> class numeric_limits<wchar_t>;
    //template<> class numeric_limits<char8_t>;    // C++20 feature
    template<> class numeric_limits<char16_t>;   // C++11 feature
    template<> class numeric_limits<char32_t>;   // C++11 feature
    template<> class numeric_limits<short>;
    template<> class numeric_limits<unsigned short>;
    template<> class numeric_limits<int>;
    template<> class numeric_limits<unsigned int>;
    template<> class numeric_limits<long>;
    template<> class numeric_limits<unsigned long> {
    public:
        static unsigned long max() {
            return 4294967295;
        }
    };
    template<> class numeric_limits<long long>;
    template<> class numeric_limits<unsigned long long>;
    template<> class numeric_limits<float>;
    template<> class numeric_limits<double>;
    template<> class numeric_limits<long double>;
};

#endif //NSTL_NUMERIC_LIMITS_H
