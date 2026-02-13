#include "SimpleMath.hpp"

#include <limits>

namespace mathlib {

constexpr int32_t MIN_I32 = std::numeric_limits<int32_t>::min();
constexpr int32_t MAX_I32 = std::numeric_limits<int32_t>::max();

bool add( int32_t a, int32_t b, int32_t& result ) {
    if ( ( b > 0 && a > MAX_I32 - b ) ||
         ( b < 0 && a < MIN_I32 - b ) ) {
        return false;
    }

    result = a + b;

    return true;
}

bool sub( int32_t a, int32_t b, int32_t& result ) {
    if ( ( b < 0 && a > MAX_I32 + b ) ||
         ( b > 0 && a < MIN_I32 + b ) ) {
        return false;
    }

    result = a - b;

    return true;
}

bool mul( int32_t a, int32_t b, int32_t& result ) {
    if ( a == 0 || b == 0 ) {
        result = 0;
        return true;
    }

    if ( a == -1 && b == MIN_I32 ) {
        return false;
    }
    if ( b == -1 && a == MIN_I32 ) {
        return false;
    }

    if ( a > MAX_I32 / b || a < MIN_I32 / b ) {
        return false;
    }

    result = a * b;

    return true;
}

bool div( int32_t a, int32_t b, int32_t& result ) {
    if ( b == 0 ) {
        return false;
    }
    if ( a == MIN_I32 && b == -1 ) {
        return false;
    }

    result = a / b;
    return true;
}

bool pow( int32_t a, int32_t b, int32_t& result ) {
    if ( b < 0 ) {
        return false;
    }

    int32_t tempResult = a;
    for ( int32_t i = 0; i < b; ++i ) {
        if ( !mul( tempResult, a, tempResult ) ) {
            return false;
        }
    }
    result = tempResult;
    return true;
}

bool factorial( int32_t a, int32_t& result ) {
    if ( a < 0 ) {
        return false;
    }
    if ( a == 1 ) {
        result = a;
        return true;
    }

    int32_t tempResult;
    if ( !factorial( a - 1, tempResult ) ) {
        return false;
    }

    return mul( a, tempResult, result );
}

}  // namespace mathlib
