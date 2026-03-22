#include "SimpleMath.hpp"

#include <stdexcept>

namespace mathlib {
    const char *MathErrorCodeToString(const MathErrorCode code) {
        switch (code) {
            case MathErrorCode::Overflow: return "Overflow";
            case MathErrorCode::DivisionByZero: return "Division by zero";
            case MathErrorCode::NegativePower: return "Negative power";
            case MathErrorCode::NegativeFactorial: return "Negative factorial";
            default: return "Unknown error";
        }
    }

    int32_t SimpleMath::Add(int32_t a, int32_t b) {
        if ((b > 0 && a > MAX_I32 - b) ||
            (b < 0 && a < MIN_I32 - b)) {
            throw MathException(MathErrorCode::Overflow);
        }

        return a + b;
    }

    int32_t SimpleMath::Sub(int32_t a, int32_t b) {
        if ((b < 0 && a > MAX_I32 + b) ||
            (b > 0 && a < MIN_I32 + b)) {
            throw MathException(MathErrorCode::Overflow);
        }

        return a - b;
    }

    int32_t SimpleMath::Mul(int32_t a, int32_t b) {
        if (a == 0 || b == 0) {
            return 0;
        }

        if (a == -1 && b == MIN_I32) {
            throw MathException(MathErrorCode::Overflow);
        }
        if (b == -1 && a == MIN_I32) {
            throw MathException(MathErrorCode::Overflow);
        }
        if (a > MAX_I32 / b || a < MIN_I32 / b) {
            throw MathException(MathErrorCode::Overflow);
        }

        return a * b;
    }

    int32_t SimpleMath::Div(int32_t a, int32_t b) {
        if (b == 0) {
            throw MathException(MathErrorCode::DivisionByZero);
        }
        if (a == MIN_I32 && b == -1) {
            throw MathException(MathErrorCode::Overflow);
        }

        return a / b;
    }

    int32_t SimpleMath::Pow(int32_t a, int32_t b) {
        if (b < 0) {
            throw MathException(MathErrorCode::NegativePower);
        }

        int32_t result = 1;
        for (int32_t i = 0; i < b; ++i) {
            result = Mul(result, a);
        }

        return result;
    }

    int32_t SimpleMath::Factorial(int32_t a) {
        if (a < 0) {
            throw MathException(MathErrorCode::NegativeFactorial);
        }
        if (a == 0 || a == 1) {
            return 1;
        }

        int32_t result = Factorial(a - 1);

        return Mul(a, result);
    }
} // namespace mathlib
