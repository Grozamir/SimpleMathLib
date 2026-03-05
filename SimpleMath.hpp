#pragma once

#include <cstdint>
#include <limits>

namespace mathlib {
    class SimpleMath {
    public:
        int32_t Add(int32_t a, int32_t b);
        int32_t Sub(int32_t a, int32_t b);
        int32_t Mul(int32_t a, int32_t b);
        int32_t Div(int32_t a, int32_t b);
        int32_t Pow(int32_t a, int32_t b);
        int32_t Factorial(int32_t a);

    protected:
        static constexpr int32_t MIN_I32 = std::numeric_limits<int32_t>::min();
        static constexpr int32_t MAX_I32 = std::numeric_limits<int32_t>::max();
    };
} // namespace mathlib
