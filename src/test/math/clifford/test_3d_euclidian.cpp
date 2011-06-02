// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)


#include "src/test/pch.hpp"
#include "vital/math/clifford/algebra.hpp"
#include "vital/math/clifford/multi_vector.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"
#include "vital/math/clifford/operators/scalar_multiplication.hpp"
#include "vital/math/clifford/operators/geometric_product.hpp"
#include "vital/math/clifford/operators/outer_product.hpp"
#include "vital/math/clifford/operators/inner_product.hpp"
#include "vital/math/clifford/operators/fat_dot_product.hpp"
#include "vital/math/clifford/operators/scalar_product.hpp"
#include "vital/math/clifford/operators/left_contraction.hpp"
#include "vital/math/clifford/operators/right_contraction.hpp"
#include "vital/math/clifford/operators/addition.hpp"
#include "vital/math/clifford/operators/negation.hpp"
#include "vital/math/clifford/operators/equality.hpp"
#include "vital/math/clifford/sign_table/sign_table_3_0.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <boost/mpl/list_c.hpp>
#include <boost/static_assert.hpp>

namespace cl = vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_3d_euclidian)
{
    typedef cl::algebra<3, 0> space;

    typedef cl::multi_vector<float, cl::make_grade_list<0         >::value, space> scalar;
    typedef cl::multi_vector<float, cl::make_grade_list<1         >::value, space> vector;
    typedef cl::multi_vector<float, cl::make_grade_list<2         >::value, space> bi_vector;
    typedef cl::multi_vector<float, cl::make_grade_list<3         >::value, space> pseudo_scalar;
    typedef cl::multi_vector<float, cl::make_grade_list<0, 2      >::value, space> spinor;
    typedef cl::multi_vector<float, cl::make_grade_list<0, 1, 2, 3>::value, space> multi_vector;
    
    scalar one(1.0f);
    vector e_1(1.0f, 0.0f, 0.0f);
    vector e_2(0.0f, 1.0f, 0.0f);
    vector e_3(0.0f, 0.0f, 1.0f);
    bi_vector e_12(1.0f, 0.0f, 0.0f);
    bi_vector e_13(0.0f, 1.0f, 0.0f);
    bi_vector e_23(0.0f, 0.0f, 1.0f);
    pseudo_scalar e_123(1.0f);

    scalar s;
    vector v;    
    bi_vector b;
    pseudo_scalar t;

    b [cl::no_alias] = outer_product(e_1, e_2); BOOST_CHECK(e_12 ==  b);
    b [cl::no_alias] = outer_product(e_1, e_3); BOOST_CHECK(e_13 ==  b);
    b [cl::no_alias] = outer_product(e_2, e_3); BOOST_CHECK(e_23 ==  b);
    b [cl::no_alias] = outer_product(e_2, e_1); BOOST_CHECK(e_12 == -b);
    b [cl::no_alias] = outer_product(e_3, e_1); BOOST_CHECK(e_13 == -b);
    b [cl::no_alias] = outer_product(e_3, e_2); BOOST_CHECK(e_23 == -b);
    
    t [cl::no_alias] = outer_product(e_12, e_3); BOOST_CHECK(e_123 ==  t);
    t [cl::no_alias] = outer_product(e_13, e_2); BOOST_CHECK(e_123 == -t);

    b [cl::no_alias] = e_1 * e_1; 
    BOOST_CHECK_CLOSE(b[0], 0.0f, 1e-6f); 

    t [cl::no_alias] = outer_product(e_12, e_3);
    BOOST_CHECK(e_123 == t);
    t [cl::no_alias] = outer_product(e_3, -e_12);    
    BOOST_CHECK(e_123 == -t); 

    // Test the left contraction;
    {
        s [cl::no_alias] = left_contraction(one, one); 
            BOOST_CHECK(s == one);           
        s [cl::no_alias] = left_contraction(e_1, one); 
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f); 
        v [cl::no_alias] = left_contraction(one, e_1); 
            BOOST_CHECK(v == e_1);              
        s [cl::no_alias] = left_contraction(e_1, e_1); 
            BOOST_CHECK_CLOSE(s[0], 1.0f, 1e-6f); 
        s [cl::no_alias] = left_contraction(e_1, e_2); 
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f); 
        v [cl::no_alias] = left_contraction(e_2, e_12); 
            BOOST_CHECK(v == -e_1);              
        v [cl::no_alias] = left_contraction(e_3, e_12);
            BOOST_CHECK_CLOSE(v[0], 0.0f, 1e-6f); 
            BOOST_CHECK_CLOSE(v[1], 0.0f, 1e-6f); 
            BOOST_CHECK_CLOSE(v[2], 0.0f, 1e-6f); 
    }


    // Try to compile a total geometric product
    {        
        multi_vector mv_0;
        multi_vector mv_1;
        multi_vector mv_2;

        mv_2 [cl::no_alias] = mv_0 * mv_1;
    }

    {
        vector v0(2.0f, 3.0f, 4.0f);
        vector v1(2.0f, 3.0f, 4.0f);
        
        scalar s = inner_product(v0, v1);
        BOOST_CHECK_CLOSE(s[0], static_cast<float>(2*2 + 3*3 + 4*4), 1e-6f); 
    }
    
    { 
        vector v0(1.0f, 0.0f, 0.0f);
        vector v1(0.0f, 1.0f, 0.0f);
        vector v2(1.0f, 1.0f, 1.0f);
       
        bi_vector b0 = v0 * v1;
        vector v3 = b0 * v2;
        
        BOOST_CHECK_CLOSE(v3[0],  1.0f, 1e-6f);
        BOOST_CHECK_CLOSE(v3[1], -1.0f, 1e-6f);
        BOOST_CHECK_CLOSE(v3[2],  0.0f, 1e-6f);
    }
}
