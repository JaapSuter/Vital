// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_GRADE_LISTS_GRADE_LISTS_PRODUCT_HPP
#define VITAL_MATH_CLIFFORD_GRADE_LISTS_GRADE_LISTS_PRODUCT_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/limits.hpp>

#include <boost/mpl/int.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// --------------------------------------------------------------------------------------
template<int Lhs, int Rhs, class Predicate, int SpaceDim>
struct grade_list_product
{   
    enum
    {
        value = 0

        #define VITAL_MATH_CLIFFORD_min(_lhs_, _rhs_) \
            (((_lhs_) > (_rhs_)) ? (_rhs_) : (_lhs_))

        #define VITAL_MATH_CLIFFORD_body(_min_grade_, _max_grade_, _result_grade_, _lhs_grade_, _rhs_grade_) \
            ((   (_result_grade_ >= (_max_grade_ - _min_grade_))                                             \
              && (_result_grade_ <  (1 + VITAL_MATH_CLIFFORD_min(SpaceDim - (_min_grade_ + _max_grade_ - SpaceDim), _max_grade_ + _min_grade_))) \
              && (((_result_grade_ - (_max_grade_ - _min_grade_)) % 2) == 0)                                 \
              && Predicate::template apply<_result_grade_, _lhs_grade_, _rhs_grade_>::value                  \
            ) ? (1 << _result_grade_) : 0)
            
        #define VITAL_MATH_CLIFFORD_min_max_grade(_lhs_grade_, _rhs_grade_, _result_grade_) \
            ((_lhs_grade_ < _rhs_grade_) ? (VITAL_MATH_CLIFFORD_body(_lhs_grade_, _rhs_grade_, _result_grade_, _lhs_grade_, _rhs_grade_)) : (VITAL_MATH_CLIFFORD_body(_rhs_grade_, _lhs_grade_, _result_grade_, _lhs_grade_, _rhs_grade_)))

        #define VITAL_MATH_CLIFFORD_grades_exist(_lhs_grade_, _rhs_grade_, _result_grade_) \
            | (((Lhs & (1 << _lhs_grade_)) && (Rhs & (1 << _rhs_grade_))) ? VITAL_MATH_CLIFFORD_min_max_grade(_lhs_grade_, _rhs_grade_, _result_grade_) : 0)

        #define VITAL_MATH_CLIFFORD_unpack_tuple_before_body(_z_, _result_grade_, _lhs_and_rhs_grade) \
            VITAL_MATH_CLIFFORD_grades_exist(BOOST_PP_TUPLE_ELEM(2, 0, _lhs_and_rhs_grade), BOOST_PP_TUPLE_ELEM(2, 1, _lhs_and_rhs_grade), _result_grade_)

        #define VITAL_MATH_CLIFFORD_loop_over_result_grade(_z_, _rhs_grade_, _lhs_grade_) \
            BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, VITAL_MATH_CLIFFORD_unpack_tuple_before_body, (_lhs_grade_, _rhs_grade_))

        #define VITAL_MATH_CLIFFORD_loop_over_rhs_grade(_z_, _lhs_grade_, _ignored_) \
            BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, VITAL_MATH_CLIFFORD_loop_over_result_grade, _lhs_grade_)

        BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, VITAL_MATH_CLIFFORD_loop_over_rhs_grade, _ignored_)

        #undef VITAL_MATH_CLIFFORD_min
        #undef VITAL_MATH_CLIFFORD_body
        #undef VITAL_MATH_CLIFFORD_min_max_grade
        #undef VITAL_MATH_CLIFFORD_grades_exist
        #undef VITAL_MATH_CLIFFORD_unpack_tuple_before_body
        #undef VITAL_MATH_CLIFFORD_loop_over_result_grade
        #undef VITAL_MATH_CLIFFORD_loop_over_rhs_grade
    };

    typedef boost::mpl::int_<value> type;
};

}}}}

#endif
