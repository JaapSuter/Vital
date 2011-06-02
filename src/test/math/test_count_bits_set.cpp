// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/count_bits_set.hpp"

#include <boost/test/auto_unit_test.hpp>

using namespace vital::math;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_count_bits_set)
{
    BOOST_CHECK(count_bits_set(0) == 0);
    BOOST_CHECK(count_bits_set(1) == 1);
    BOOST_CHECK(count_bits_set(2) == 1);
    BOOST_CHECK(count_bits_set(3) == 2);
    BOOST_CHECK(count_bits_set(4) == 1);

    BOOST_CHECK(count_bits_set(7) == 3);
    BOOST_CHECK(count_bits_set(8) == 1);

    BOOST_CHECK(count_bits_set(14) == 3);
    BOOST_CHECK(count_bits_set(15) == 4);
    BOOST_CHECK(count_bits_set(16) == 1);
    
    BOOST_CHECK(count_bits_set(255) == 8);
    BOOST_CHECK(count_bits_set(256) == 1);
}
