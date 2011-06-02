// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_FACTORIAL_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_FACTORIAL_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template<int N> struct factorial_c;
template<>      struct factorial_c<0> : boost::mpl::int_<  1> {};
template<>      struct factorial_c<1> : boost::mpl::int_<  1> {};
template<>      struct factorial_c<2> : boost::mpl::int_<  2> {};
template<>      struct factorial_c<3> : boost::mpl::int_<  6> {};
template<>      struct factorial_c<4> : boost::mpl::int_< 24> {};
template<>      struct factorial_c<5> : boost::mpl::int_<120> {};

}}}}

#endif
