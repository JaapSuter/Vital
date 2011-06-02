// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_NTH_NUMBER_WITH_M_BITS_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_NTH_NUMBER_WITH_M_BITS_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/range_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/fold.hpp>
#include <vital/math/clifford/detail/next_number_with_same_num_bits.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template<class N, class M, class Result = boost::mpl::int_<0> > 
struct nth_number_with_m_bits
{
    typedef typename boost::mpl::fold
    <
        typename boost::mpl::range_c
        <
            int,
            0,
            N::value
        >::type,

        boost::mpl::int_< ((1 << M::value) - 1)>,
        next_number_with_same_num_bits<boost::mpl::_1>
    >::type type;
};

}}}}

#endif
