// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/algebra.hpp"
#include "vital/math/clifford/limits.hpp"

#include "vital/math/clifford/sign_table/sign_table.hpp"

#ifndef VITAL_MATH_CLIFFORD_SPEED_UP_SIGN_TABLE_TEST_COMPILATION
    #define VITAL_MATH_CLIFFORD_SPEED_UP_SIGN_TABLE_TEST_COMPILATION 1
#endif

#if VITAL_MATH_CLIFFORD_SPEED_UP_SIGN_TABLE_TEST_COMPILATION
    #include "vital/math/clifford/sign_table/sign_table_0_0.hpp"
    #include "vital/math/clifford/sign_table/sign_table_1_0.hpp"
    #include "vital/math/clifford/sign_table/sign_table_1_1.hpp"
    #include "vital/math/clifford/sign_table/sign_table_2_0.hpp"
    #include "vital/math/clifford/sign_table/sign_table_3_0.hpp"
    #include "vital/math/clifford/sign_table/sign_table_4_1.hpp"
#endif

#ifdef _MSC_VER
    #pragma warning(disable:4127)
    #pragma warning(disable:4511)
    #pragma warning(disable:4512)
#endif

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>

using namespace vital::math::clifford;
using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_sign_table)
{
    /*
    
    const int   _1 = 0;
    const int  e_1 = 1;
    const int  e_2 = 2;
    const int  e_3 = 4;
    const int e_12 = 3;
    const int e_13 = 5;
    const int e_23 = 6;
    const int e_123 = 7;

    // Test 2D euclidian space;
    {
        typedef algebra<2> space;

        //      1      e_1  e_2   e_12
        // 1    1      e_1  e_2   e_12
        // e_1  e_1      1  e_12   e_2
        // e_2  e_2  -e_12     1  -e_1
        // e_12 e_12  -e_2   e_1    -1

        BOOST_STATIC_ASSERT((sign_table<  _1,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1,  e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1, e_12, space>::type::value ==  1));
                                              
        BOOST_STATIC_ASSERT((sign_table< e_1,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1,  e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1, e_12, space>::type::value ==  1));
                                              
        BOOST_STATIC_ASSERT((sign_table< e_2,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_2,  e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_2,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_2, e_12, space>::type::value == -1));
                                              
        BOOST_STATIC_ASSERT((sign_table<e_12,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_12,  e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_12,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_12, e_12, space>::type::value == -1));
    }

    // Test 3d euclidian space;
    {
        typedef algebra<3> space;

        //            1    e_1    e_2    e_3   e_12   e_13   e_23  e_123
        //     1      1    e_1    e_2    e_3   e_12   e_13   e_23  e_123
        //   e_1    e_1      1   e_12   e_13    e_2    e_3  e_123   e_23
        //   e_2    e_2  -e_12      1   e_23   -e_1  -e_23    e_3  -e_13
        //   e_3    e_3  -e_13  -e_23      1  e_123   -e_1   -e_2   e_12
        //  e_12   e_12   -e_2    e_1  e_123     -1  -e_23   e_13   -e_3
        //  e_13   e_13   -e_3 -e_123    e_1   e_23     -1  -e_12    e_2
        //  e_23   e_23  e_123   -e_3    e_2  -e_13   e_12     -1   -e_1
        // e_123  e_123   e_23  -e_13   e_12   -e_3    e_2   -e_1     -1

        BOOST_STATIC_ASSERT((sign_table<   _1,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,   e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,   e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,  e_12, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,  e_13, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1,  e_23, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<   _1, e_123, space>::type::value ==  1));

        BOOST_STATIC_ASSERT((sign_table<  e_1,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,   e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,   e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,  e_12, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,  e_13, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1,  e_23, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_1, e_123, space>::type::value ==  1));
                                        
        BOOST_STATIC_ASSERT((sign_table<  e_2,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,   e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,   e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,  e_12, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,  e_13, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_2,  e_23, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_2, e_123, space>::type::value == -1));
                                        
        BOOST_STATIC_ASSERT((sign_table<  e_3,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,   e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,   e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,  e_12, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,  e_13, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_3,  e_23, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<  e_3, e_123, space>::type::value ==  1));

        BOOST_STATIC_ASSERT((sign_table< e_12,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_12,   e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_12,   e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_12,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_12,  e_12, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_12,  e_13, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_12,  e_23, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_12, e_123, space>::type::value == -1));

        BOOST_STATIC_ASSERT((sign_table< e_13,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_13,   e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_13,   e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_13,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_13,  e_12, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_13,  e_13, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_13,  e_23, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_13, e_123, space>::type::value ==  1));

        BOOST_STATIC_ASSERT((sign_table< e_23,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_23,   e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_23,   e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_23,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_23,  e_12, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_23,  e_13, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_23,  e_23, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_23, e_123, space>::type::value == -1));

        BOOST_STATIC_ASSERT((sign_table<e_123,    _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_123,   e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_123,   e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_123,   e_3, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_123,  e_12, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_123,  e_13, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_123,  e_23, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_123, e_123, space>::type::value == -1));
    }

    // Test a space with negative index;
    {
        typedef algebra<1, 1> space;

        //      1      e_1  e_2   e_12
        // 1    1      e_1  e_2   e_12
        // e_1  e_1      1  e_12   e_2
        // e_2  e_2  -e_12    -1   e_1
        // e_12 e_12  -e_2  -e_1     1
        
        BOOST_STATIC_ASSERT((sign_table<  _1,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1,  e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<  _1, e_12, space>::type::value ==  1));
        
        BOOST_STATIC_ASSERT((sign_table< e_1,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1,  e_1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1,  e_2, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_1, e_12, space>::type::value ==  1));
        
        BOOST_STATIC_ASSERT((sign_table< e_2,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table< e_2,  e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_2,  e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table< e_2, e_12, space>::type::value ==  1));
        
        BOOST_STATIC_ASSERT((sign_table<e_12,   _1, space>::type::value ==  1));
        BOOST_STATIC_ASSERT((sign_table<e_12,  e_1, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_12,  e_2, space>::type::value == -1));
        BOOST_STATIC_ASSERT((sign_table<e_12, e_12, space>::type::value ==  1));
    }

    // Test the out of bounds
    {
        typedef algebra<1, 1> space;
        BOOST_STATIC_ASSERT((sign_table<e_123, e_123, space>::type::value == 0));
    }

    */
}
