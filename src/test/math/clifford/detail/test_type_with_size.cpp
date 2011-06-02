// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/type_with_size.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_type_with_size)
{
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_< 1> >) ==  1);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_< 2> >) ==  2);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_< 3> >) ==  3);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_< 4> >) ==  4);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_< 5> >) ==  5);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<61> >) == 61);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<62> >) == 62);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<63> >) == 63);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<64> >) == 64);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<65> >) == 65);
    BOOST_STATIC_ASSERT(sizeof(type_with_size<boost::mpl::int_<45385> >) == 45385);
}
