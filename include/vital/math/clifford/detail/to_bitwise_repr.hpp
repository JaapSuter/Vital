// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_TO_BITWISE_REPR_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_TO_BITWISE_REPR_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/detail/binomial_coefficient.hpp>
#include <vital/math/clifford/detail/nth_number_with_m_bits.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/int.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template <int GradeList, class Algebra, int Index, int Grade = 0>
struct to_bitwise_repr
{
private: 

    typedef typename boost::mpl::eval_if_c
    <
        ((GradeList & (1 << Grade)) > 0),
        binomial_coefficient_c
        <
            Algebra::space_dimension::value,
            Grade
        >,
        boost::mpl::int_<0>
    >::type num_scalars_in_this_grade;

public:

    typedef typename boost::mpl::eval_if_c
    <
        (num_scalars_in_this_grade::value > Index),
        nth_number_with_m_bits
        <
            boost::mpl::int_<Index>, 
            boost::mpl::int_<Grade>
        >,
        to_bitwise_repr
        <
            GradeList,
            Algebra,
            Index - num_scalars_in_this_grade::value,
            Grade + 1
        >
    >::type type;
};

}}}}

#endif
