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
#include "vital/math/clifford/sign_table/sign_table_2_0.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <boost/mpl/list_c.hpp>
#include <boost/static_assert.hpp>

namespace cl = vital::math::clifford;

#include <complex>

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_2d_euclidian)
{
    typedef cl::algebra<2, 0> space;

    typedef cl::multi_vector<float, cl::make_grade_list<0      >::value, space> scalar;
    typedef cl::multi_vector<float, cl::make_grade_list<1      >::value, space> vector;
    typedef cl::multi_vector<float, cl::make_grade_list<2      >::value, space> bi_vector;
    typedef cl::multi_vector<float, cl::make_grade_list<0, 2   >::value, space> complex_number;
    typedef cl::multi_vector<float, cl::make_grade_list<0, 1, 2>::value, space> multi_vector;

    scalar    one(1.0f);
    vector    e_1(1.0f, 0.0f);
    vector    e_2(0.0f, 1.0f);
    bi_vector e_12(1.0f);

    scalar s;
    vector v;
    bi_vector b;

    complex_number c;

    
    // Test the left contraction;
    {
        s [cl::no_alias] = left_contraction(one, one);
            BOOST_CHECK(s == one);
        v [cl::no_alias] = left_contraction(one, e_1);
            BOOST_CHECK(v == e_1);         
        s [cl::no_alias] = left_contraction(e_1, e_1);
            BOOST_CHECK_CLOSE(s[0], 1.0f, 1e-6f); 
        s [cl::no_alias] = left_contraction(e_1, e_2);
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f); 
        v [cl::no_alias] = left_contraction(e_2, e_12);
            BOOST_CHECK(v == -e_1);
        s [cl::no_alias] = left_contraction(e_1, one);
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f);
    }

    // Test the right contraction;
    {
        s = right_contraction(one, one); 
            BOOST_CHECK(s == one);           
        v = right_contraction(e_1, one); 
            BOOST_CHECK(v == e_1);              
        s = right_contraction(e_1, e_1); 
            BOOST_CHECK_CLOSE(s[0], 1.0f, 1e-6f); 
        s = right_contraction(e_2, e_1); 
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f);
        v = right_contraction(e_12, e_2); 
            BOOST_CHECK(v == e_1);
        s = right_contraction(one, e_1);
            BOOST_CHECK_CLOSE(s[0], 0.0f, 1e-6f);
    }

    // Test the outer product;
    {
        bi_vector b = outer_product(e_1, e_2);
        BOOST_CHECK(e_12 == b);
    
        // The outer product is anticommutative;
        b = outer_product(e_2, e_1);    
        BOOST_CHECK(e_12 == -b); 
    
        // Outer product with self is zero;
        b = outer_product(e_1, e_1);
        BOOST_CHECK_CLOSE(b[0], 0.0f, 1e-6f);
    }

    {
        // Define a few multivectors;
        multi_vector mv_0;
        multi_vector mv_1;
        multi_vector mv_2;

        // Give them some values;
        mv_0[0] = 1.0f;
        mv_0[1] = 2.0f;
        mv_0[2] = 3.0f;
        mv_0[3] = 4.0f;

        mv_1[0] = 4.0f;
        mv_1[1] = 3.0f;
        mv_1[2] = 2.0f;
        mv_1[3] = 1.0f;

        // Do a full geometric product between two multivectors;
        mv_2 = mv_0 * mv_1;
    }

    // Try some different operators, just making sure it compiles;
    {
        bi_vector b = e_12;
        b [cl::no_alias] = b + e_12;
        v *= 2.0f;
        v [cl::no_alias] = e_1 * 2.0f;
        s -= one;
        s [cl::no_alias] = s - one;
        e_12 != b;
        multi_vector mv_0;
        multi_vector mv_1;
        multi_vector mv_2 = mv_0 - mv_1 * 0.5f;
    }

    // Do a comparison with complex numbers;
    // Answer should be; real      part: (1 * 2) - (3 * 5) = -13;
    //                   imaginary part: (1 * 5) + (3 * 2) =  11;
    {
        complex_number clifford_complex_0(1.0f, 3.0f);
        complex_number clifford_complex_1(2.0f, 5.0f);
        
        complex_number clifford_complex_2 = clifford_complex_0 * clifford_complex_1;
        
        std::complex<float> std_complex_0(1, 3);
        std::complex<float> std_complex_1(2, 5);
        
        std::complex<float> std_complex_2 = std_complex_0 * std_complex_1;

        BOOST_CHECK_CLOSE(std_complex_2.real(), clifford_complex_2[0], 1e-6f);
        BOOST_CHECK_CLOSE(std_complex_2.imag(), clifford_complex_2[1], 1e-6f);
    }

    // Rotation test;
    {
        multi_vector mv_0;
        multi_vector mv_1;
        multi_vector mv_2;
    
        mv_0[1] = 1.0f;
    
        const float pi = 3.1415926535897932384626433832795f;
        mv_1[0] = cosf(pi);
        mv_1[3] = sinf(pi);

        mv_2 = mv_1 * mv_0;
    }

    // Test a bunch of random products, to see if they compile fine;
    {
        multi_vector mv_scalar_1_1;
        multi_vector mv_scalar_1_2;
        multi_vector mv_fat_dot_1_1;
        multi_vector mv_fat_dot_1_2;
        multi_vector mv_inner_1_1;
        multi_vector mv_inner_1_2;
            
        mv_scalar_1_1 = scalar_product(e_1, e_1);
        mv_scalar_1_2 = scalar_product(e_1, e_2);

        mv_fat_dot_1_1 = fat_dot_product(e_1, e_1);
        mv_fat_dot_1_2 = fat_dot_product(e_1, e_2);

        mv_inner_1_1 = inner_product(e_1, e_1);
        mv_inner_1_2 = inner_product(e_1, e_2);
    }

    // Test equation (2.11) from http://carol.wins.uva.nl/~leo/clifford/inner.ps where
    // A and B have the same grades;
    {
        multi_vector mv_a;
        multi_vector mv_b;
        multi_vector mv_2;
        multi_vector mv_3;
        multi_vector mv_result_0;
        multi_vector mv_result_1;

        mv_a[0] = 1.0f;
        mv_a[1] = 2.0f;
        mv_a[2] = 3.0f;
        mv_a[3] = 4.0f;
        mv_b[0] = 5.0f;
        mv_b[1] = 6.0f;
        mv_b[2] = 7.0f;
        mv_b[3] = 8.0f;

        mv_2 [cl::no_alias] = left_contraction(mv_b, mv_a);
        mv_3 [cl::no_alias] = right_contraction(mv_b, mv_a);
        mv_result_0 [cl::no_alias] = mv_2 + mv_3;
        
        mv_2 [cl::no_alias] = scalar_product(mv_b, mv_a);
        mv_3 [cl::no_alias] = fat_dot_product(mv_b, mv_a);
        mv_result_1 [cl::no_alias] = mv_2 + mv_3;

        BOOST_CHECK(mv_result_0 == mv_result_1);
    }

    // Test equation (2.11) from http://carol.wins.uva.nl/~leo/clifford/inner.ps where
    // A and B have different grades;
    {
        multi_vector mv_a;
        multi_vector mv_b;
        multi_vector mv_2;
        multi_vector mv_3;
        multi_vector mv_result_0;
        multi_vector mv_result_1;

        mv_a[0] = 1.0f;
        mv_a[1] = 2.0f;
        mv_b[0] = 3.0f;
        mv_b[1] = 4.0f;
        mv_b[2] = 5.0f;
        mv_b[3] = 6.0f;

        mv_2 = left_contraction(mv_b, mv_a);
        mv_3 = right_contraction(mv_b, mv_a);
        mv_result_0 = mv_2 + mv_3;
        
        mv_2 = scalar_product(mv_b, mv_a);
        mv_3 = fat_dot_product(mv_b, mv_a);
        mv_result_1 = mv_2 + mv_3;

        BOOST_CHECK(mv_result_0 == mv_result_1);
    }

    // Test different element assignment
    {
        scalar a;
        vector b;
        bi_vector c;
        multi_vector d;
        complex_number e;

        d[0] = 1.0f;
        d[1] = 2.0f;
        d[2] = 3.0f;
        d[3] = 4.0f;

        a = a;
        a = b;
        a = c;
        a = d; BOOST_CHECK_CLOSE(a[0], 1.0f, 1e-6f); 
        a = e;

        b = a;
        b = b;
        b = c;
        b = d; BOOST_CHECK_CLOSE(b[0], 2.0f, 1e-6f); BOOST_CHECK_CLOSE(b[1], 3.0f, 1e-6f); 
        b = e;

        c = a;
        c = b;
        c = c; 
        c = d; BOOST_CHECK_CLOSE(c[0], 4.0f, 1e-6f); 
        c = e;

        d = a;
        d = b;
        d = c;
        d = d;
        d = e;

        e = a;
        e = b;
        e = c;
        e = d;
        e = e;
    }
}
