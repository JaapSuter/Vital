// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/num_bits_set.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_num_bits_set)
{
    BOOST_STATIC_ASSERT( (0 == num_bits_set_c<0>::type::value) );
    BOOST_STATIC_ASSERT( (1 == num_bits_set_c<1>::type::value) );
    BOOST_STATIC_ASSERT( (1 == num_bits_set_c<2>::type::value) );
    BOOST_STATIC_ASSERT( (2 == num_bits_set_c<3>::type::value) );
    BOOST_STATIC_ASSERT( (1 == num_bits_set_c<4>::type::value) );
    BOOST_STATIC_ASSERT( (2 == num_bits_set_c<5>::type::value) );
    BOOST_STATIC_ASSERT( (2 == num_bits_set_c<6>::type::value) );
    BOOST_STATIC_ASSERT( (3 == num_bits_set_c<7>::type::value) );
    BOOST_STATIC_ASSERT( (1 == num_bits_set_c<8>::type::value) );
    BOOST_STATIC_ASSERT( (2 == num_bits_set_c<9>::type::value) );

    BOOST_STATIC_ASSERT( (8 == num_bits_set_c<255>::type::value) );
    BOOST_STATIC_ASSERT( (1 == num_bits_set_c<256>::type::value) );
    BOOST_STATIC_ASSERT( (2 == num_bits_set_c<257>::type::value) );
}
