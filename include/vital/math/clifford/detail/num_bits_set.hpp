// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_NUM_BITS_SET_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_NUM_BITS_SET_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template <int N, class Result = boost::mpl::int_<0> >
struct num_bits_set_c
{
    enum
    {
        tmp = N - ((N >> 1) & 033333333333)
                - ((N >> 2) & 011111111111),
        value = ((tmp + (tmp >> 3)) & 030707070707) % 63
    };

    typedef boost::mpl::int_<value> type;
};

// --------------------------------------------------------------------------------------
template <class N, class Result = boost::mpl::int_<0> >
struct num_bits_set : num_bits_set_c<N::value>::type {};
             
}}}}

#endif
