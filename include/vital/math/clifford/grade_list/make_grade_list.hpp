// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_GRADE_LIST_MAKE_GRADE_LIST_HPP
#define VITAL_MATH_CLIFFORD_GRADE_LIST_MAKE_GRADE_LIST_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/limits.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/mpl/int.hpp>


namespace vital {
    namespace math {
        namespace clifford {

// --------------------------------------------------------------------------------------
template<BOOST_PP_ENUM_BINARY_PARAMS(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, int G, = -1 BOOST_PP_INTERCEPT)>
struct make_grade_list
{
    enum
    {
        value = 0
        
        #define VITAL_MATH_CLIFFORD_local(_z_, _n_, _ignored_) \
        | ((BOOST_PP_CAT(G, _n_) != -1) ? (1 << (BOOST_PP_CAT(G, _n_) >= 0 ? BOOST_PP_CAT(G, _n_) : 0)) : 0)
    
        BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_DIMENSION_PLUS_ONE, VITAL_MATH_CLIFFORD_local, ignored)

        #undef VITAL_MATH_CLIFFORD_local
    };

    typedef boost::mpl::int_<value> type;
};

}}}

#endif
