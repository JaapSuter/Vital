// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/binomial_coefficient.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_binomial_coefficient)
{
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<1, 0>::type::value) );
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<1, 1>::type::value) );
    
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<2, 0>::type::value) );
    BOOST_STATIC_ASSERT( (2 == binomial_coefficient_c<2, 1>::type::value) );
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<2, 2>::type::value) );
    
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<3, 0>::type::value) );
    BOOST_STATIC_ASSERT( (3 == binomial_coefficient_c<3, 1>::type::value) );
    BOOST_STATIC_ASSERT( (3 == binomial_coefficient_c<3, 2>::type::value) );
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<3, 3>::type::value) );
    
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<4, 0>::type::value) );
    BOOST_STATIC_ASSERT( (4 == binomial_coefficient_c<4, 1>::type::value) );
    BOOST_STATIC_ASSERT( (6 == binomial_coefficient_c<4, 2>::type::value) );
    BOOST_STATIC_ASSERT( (4 == binomial_coefficient_c<4, 3>::type::value) );
    BOOST_STATIC_ASSERT( (1 == binomial_coefficient_c<4, 4>::type::value) );
    
    BOOST_STATIC_ASSERT( ( 1 == binomial_coefficient_c<5, 0>::type::value) );
    BOOST_STATIC_ASSERT( ( 5 == binomial_coefficient_c<5, 1>::type::value) );
    BOOST_STATIC_ASSERT( (10 == binomial_coefficient_c<5, 2>::type::value) );
    BOOST_STATIC_ASSERT( (10 == binomial_coefficient_c<5, 3>::type::value) );
    BOOST_STATIC_ASSERT( ( 5 == binomial_coefficient_c<5, 4>::type::value) );
    BOOST_STATIC_ASSERT( ( 1 == binomial_coefficient_c<5, 5>::type::value) );
}
