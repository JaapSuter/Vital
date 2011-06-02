// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/algebra_union.hpp"
#include "vital/math/clifford/algebra.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

using namespace vital::math::clifford::detail;
using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_algebra_union)
{
    typedef algebra<3, 0> a_3_0;
    typedef algebra<4, 1> a_4_1;

    BOOST_STATIC_ASSERT((boost::is_same<algebra_union<a_3_0, a_4_1>::type, a_4_1>::value));
}
