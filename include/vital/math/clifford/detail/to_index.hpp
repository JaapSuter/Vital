// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_TO_INDEX_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_TO_INDEX_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/fold.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/bitand.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/shift_left.hpp>

#include <vital/math/clifford/detail/num_bits_set.hpp>
#include <vital/math/clifford/detail/binomial_coefficient.hpp>
#include <vital/math/clifford/detail/nth_number_with_m_bits_inverse.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// --------------------------------------------------------------------------------------
template<int GradeList, class Algebra, int BitwiseRepr>
struct to_index
{
private:

    typedef typename boost::mpl::fold
    <
        boost::mpl::range_c
        <
            int,
            0,
            num_bits_set_c<BitwiseRepr>::value
        >,
        boost::mpl::int_<0>,
        boost::mpl::eval_if
        <
            boost::mpl::bitand_
            <
                boost::mpl::shift_left
                <
                    boost::mpl::int_<1>,
                    boost::mpl::_2                
                >,
                boost::mpl::int_<GradeList>
            >,
            boost::mpl::plus
            <
                binomial_coefficient
                <
                    typename Algebra::space_dimension,
                    boost::mpl::_2
                >,
                boost::mpl::_1
            >,
            boost::mpl::_1
        >
    >::type index_up_to_all_grades_in_front_of_actual_grade;

public:

    typedef typename boost::mpl::plus
    <
        index_up_to_all_grades_in_front_of_actual_grade,
        typename nth_number_with_m_bits_inverse<boost::mpl::int_<BitwiseRepr> >::type
    >::type type;
};

}}}}

#endif
