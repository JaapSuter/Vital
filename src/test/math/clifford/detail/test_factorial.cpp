// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/factorial.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_factorial)
{
    BOOST_STATIC_ASSERT( (factorial_c<0>::type::value == 1) );
    BOOST_STATIC_ASSERT( (factorial_c<1>::type::value == 1) );
    BOOST_STATIC_ASSERT( (factorial_c<2>::type::value == 1*2) );
    BOOST_STATIC_ASSERT( (factorial_c<3>::type::value == 1*2*3) );
    BOOST_STATIC_ASSERT( (factorial_c<4>::type::value == 1*2*3*4) );
    BOOST_STATIC_ASSERT( (factorial_c<5>::type::value == 1*2*3*4*5) );
}
