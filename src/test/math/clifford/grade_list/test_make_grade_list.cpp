// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>

using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_make_grade_list)
{
    BOOST_STATIC_ASSERT(make_grade_list< >::value ==  0);
    BOOST_STATIC_ASSERT(make_grade_list<0>::value ==  1);
    BOOST_STATIC_ASSERT(make_grade_list<1>::value ==  2);
    BOOST_STATIC_ASSERT(make_grade_list<2>::value ==  4);
    BOOST_STATIC_ASSERT(make_grade_list<3>::value ==  8);
    BOOST_STATIC_ASSERT(make_grade_list<4>::value == 16);
    BOOST_STATIC_ASSERT(make_grade_list<5>::value == 32);

    BOOST_STATIC_ASSERT((make_grade_list<0, 1, 2, 3, 4, 5>::value == 63));
    BOOST_STATIC_ASSERT((make_grade_list<5, 4, 3, 2, 1, 0>::value == 63));

    BOOST_STATIC_ASSERT((make_grade_list<5, 4, 3, 2, 1, 0>::value == 63));

    BOOST_STATIC_ASSERT((make_grade_list<0, 2>::value == 5));
}
