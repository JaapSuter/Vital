// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_TYPE_WITH_SIZE_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_TYPE_WITH_SIZE_HPP

#ifdef _MSC_VER
    #pragma once
#endif

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// -----------------------------------------------------------------
template<class Size>
struct type_with_size
{
    char m[Size::value];
};

}}}}

#endif
