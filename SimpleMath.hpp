#pragma once

#include <cstdint>

namespace mathlib {
bool add( int32_t a, int32_t b, int32_t& result );
bool sub( int32_t a, int32_t b, int32_t& result );
bool mul( int32_t a, int32_t b, int32_t& result );
bool div( int32_t a, int32_t b, int32_t& result );
bool pow( int32_t a, int32_t b, int32_t& result );
bool factorial( int32_t a, int32_t& result );
}  // namespace mathlib
