// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/grade_list/grade_list_product.hpp"
#include "vital/math/clifford/operators/outer_product.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>

using namespace vital::math::clifford::detail;
using namespace vital::math::clifford;
using namespace vital::math;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_compile_time_grade_list_outer_product)
{

    #define VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(_lhs_, _rhs_, _dim_) \
        const int result = grade_list_product                           \
        <                                                               \
            _lhs_,                                                      \
            _rhs_,                                                      \
            outer_product_predicate,                                    \
            _dim_                                                       \
        >::value;
    
    const int scalar_grades      = make_grade_list<0>::value;
    const int vector_grades      = make_grade_list<1>::value;
    const int bi_vector_grades   = make_grade_list<2>::value;
    const int tri_vector_grades  = make_grade_list<3>::value;
    
    {
        VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(scalar_grades, scalar_grades, 2);
        BOOST_STATIC_ASSERT(result == scalar_grades);
    }

    {
        VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(vector_grades, vector_grades, 2);
        BOOST_STATIC_ASSERT(result == bi_vector_grades);
    }

    {
        VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(vector_grades, vector_grades, 3);
        BOOST_STATIC_ASSERT(result == bi_vector_grades);
    }

    {
        VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(bi_vector_grades, vector_grades, 3);
        BOOST_STATIC_ASSERT(result == tri_vector_grades);
    }

    {
        VITAL_MATH_CLIFFORD_TEST_OUTER_PRODUCT(vector_grades, bi_vector_grades, 3);
        BOOST_STATIC_ASSERT(result == tri_vector_grades);
    }
}

