// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_BINOMIAL_COEFFICIENT_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_BINOMIAL_COEFFICIENT_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/detail/factorial.hpp>
#include <boost/mpl/int.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template <int N, int K>
struct binomial_coefficient_c : boost::mpl::int_
<
    factorial_c<N>::value / (factorial_c<K>::value * factorial_c<N - K>::value)
> {};

// --------------------------------------------------------------------------------------
template <class N, class K>
struct binomial_coefficient : binomial_coefficient_c<N::value, K::value> {};

}}}}

#endif
