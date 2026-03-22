#pragma once

#include <cstdint>
#include <exception>
#include <limits>
#include <string>

namespace mathlib {
    enum class MathErrorCode : uint8_t {
        None = 0,
        Overflow = 1,
        DivisionByZero = 2,
        NegativePower = 3,
        NegativeFactorial = 4
    };

    const char *MathErrorCodeToString(MathErrorCode code);

    class MathException : public std::exception {
    public:
        explicit MathException(const MathErrorCode newCode) : errorCode(newCode) {
        }

        [[nodiscard]] const char *what() const noexcept override {
            return MathErrorCodeToString(errorCode);
        }

        [[nodiscard]] int32_t GetErrorCode() const noexcept {
            return static_cast<int32_t>(errorCode);
        }

    private:
        MathErrorCode errorCode;
    };

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
