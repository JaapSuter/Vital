// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_ALGEBRA_UNION_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_ALGEBRA_UNION_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/algebra.hpp>
#include <vital/math/clifford/limits.hpp>
#include <boost/mpl/min_max.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// --------------------------------------------------------------------------------------
template <class Lhs, class Rhs>
struct algebra_union
{
    typedef algebra
    <
        boost::mpl::max<typename Lhs::num_positive_basis_vectors, typename Rhs::num_positive_basis_vectors>::type::value,
        boost::mpl::max<typename Lhs::num_negative_basis_vectors, typename Rhs::num_negative_basis_vectors>::type::value
    > type;
};


}}}}

#endif
