// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_NTH_NUMBER_WITH_M_BITS_INVERSE_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_NTH_NUMBER_WITH_M_BITS_INVERSE_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/int.hpp>
#include <vital/math/clifford/detail/num_bits_set.hpp>
#include <vital/math/clifford/detail/nth_number_with_m_bits.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template <class BitwiseRepr, class Result = boost::mpl::int_<0> > 
struct nth_number_with_m_bits_inverse
{
    typedef typename boost::mpl::eval_if
    <
        typename boost::mpl::equal_to
        <
            typename nth_number_with_m_bits
            <
                Result, 
                typename num_bits_set<BitwiseRepr>::type 
            >::type, 
            
            BitwiseRepr 
        >::type,
        
        Result,
        nth_number_with_m_bits_inverse<BitwiseRepr, typename Result::next>
    >::type type;
};

}}}}

#endif
