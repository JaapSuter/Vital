// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_COUNT_LEADING_ZEROES_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_COUNT_LEADING_ZEROES_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template<class T>
struct count_leading_zeroes
{
private:   

    enum
    {
        n_0 = 0,
        t_0 = T::value,
        n_1 = ((t_0 & 0x0000FFFF) == 0) ? (n_0  + 16) : n_0,
        t_1 = ((t_0 & 0x0000FFFF) == 0) ? (t_0 >> 16) : t_0,
        n_2 = ((t_1 & 0x000000FF) == 0) ? (n_1  +  8) : n_1,
        t_2 = ((t_1 & 0x000000FF) == 0) ? (t_1 >>  8) : t_1,
        n_3 = ((t_2 & 0x0000000F) == 0) ? (n_2  +  4) : n_2,
        t_3 = ((t_2 & 0x0000000F) == 0) ? (t_2 >>  4) : t_2,
        n_4 = ((t_3 & 0x00000003) == 0) ? (n_3  +  2) : n_3,
        t_4 = ((t_3 & 0x00000003) == 0) ? (t_3 >>  2) : t_3,
        n_5 = ((t_4 & 0x00000001) == 0) ? (n_4  +  1) : n_4,
    };

public:

    typedef boost::mpl::int_<n_5> type;
};

}}}}

#endif
