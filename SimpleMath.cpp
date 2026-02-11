#include "SimpleMath.hpp"

namespace mathlib {

    int32_t add(int32_t a, int32_t b) {
        return a + b;
    }

    int32_t sub(int32_t a, int32_t b) {
        return a - b;
    }

    int32_t mul(int32_t a, int32_t b) {
        return a * b;
    }

    bool div(int32_t a, int32_t b, int32_t& result) {
        if ( b == 0 ) {
            return false;
        }
        result = a / b;
        return true;
    }

    int32_t pow(int32_t a, int32_t b) {
        int32_t result = a;
        for ( int32_t i = 0; i < b; ++i ) {
            result *= a;
        }
        return 0;
    }

    int32_t factorial(int32_t a) {
        if ( a == 1 ) {
            return 1;
        }
        return a * factorial(a - 1);
    }

}
