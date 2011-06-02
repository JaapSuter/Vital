// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/enable_if_for_expression.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>

#ifdef _MSC_VER
    #pragma warning(disable:4189)
#endif

using namespace vital::math::clifford::detail;
using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
struct multi_vector : expression {};

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_enable_if_for_expression)
{
    // should compile
    typedef enable_if_for_expression<multi_vector>::type foo;
    typedef enable_if_for_expression<expression>::type foo;
        
    // shouldn't compile
    // typedef enable_if_for_expression<void>::type foo;
}
