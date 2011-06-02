// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_ALGEBRA_HPP
#define VITAL_MATH_CLIFFORD_ALGEBRA_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>
#include <boost/static_assert.hpp>
#include <vital/math/clifford/limits.hpp>

namespace vital {
    namespace math {
        namespace clifford {

// --------------------------------------------------------------------------------------
template <int P, int Q = 0>
struct algebra
{
    BOOST_STATIC_ASSERT(P >= 1);
    BOOST_STATIC_ASSERT(Q >= 0);

    typedef boost::mpl::int_<P + Q> space_dimension;
    
    BOOST_STATIC_ASSERT(space_dimension::value <= VITAL_MATH_CLIFFORD_MAX_DIMENSION);

    typedef boost::mpl::int_<1 << space_dimension::value> algebra_dimension;

    BOOST_STATIC_ASSERT(algebra_dimension::value <= VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE);

    typedef boost::mpl::int_<P> num_positive_basis_vectors;
    typedef boost::mpl::int_<Q> num_negative_basis_vectors;
};


}}}

#endif
