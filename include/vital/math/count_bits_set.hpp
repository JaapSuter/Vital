// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_COUNT_BITS_SET_HPP
#define VITAL_MATH_COUNT_BITS_SET_HPP

#ifdef _MSC_VER
    #pragma once
#endif

namespace vital {
    namespace math {

// --------------------------------------------------------------------------------------
inline int count_bits_set(int n)
{
    n = n - ((n >> 1) & 033333333333)
          - ((n >> 2) & 011111111111);
    return ((n + (n >> 3)) & 030707070707) % 63;
}

}}

#endif
