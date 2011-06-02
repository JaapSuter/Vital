// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_GRADE_LISTS_NUM_SCALARS_FOR_GRADE_LIST_HPP
#define VITAL_MATH_CLIFFORD_GRADE_LISTS_NUM_SCALARS_FOR_GRADE_LIST_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <vital/math/clifford/detail/binomial_coefficient.hpp>
#include <vital/math/clifford/limits.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// --------------------------------------------------------------------------------------
template<int GradeList, class Algebra>
struct num_scalars_for_grade_list
{
    enum
    {
        #define VITAL_MATH_CLIFFORD_num_scalars_for_grade_list_IMPL(_z_, _n_, _ignored_) \
            + ((GradeList & (1 << _n_))                                                  \
            ? binomial_coefficient_c<Algebra::space_dimension::value, (Algebra::space_dimension::value < _n_) ? 0 : _n_>::type::value  \
            : 0)

        value = 0 + BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, VITAL_MATH_CLIFFORD_num_scalars_for_grade_list_IMPL, ignored)

        #undef VITAL_MATH_CLIFFORD_num_scalars_for_grade_list_IMPL
    };

    typedef boost::mpl::int_<value> type;
};


}}}}

#endif
