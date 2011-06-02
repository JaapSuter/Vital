// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/algebra.hpp"
#include "vital/math/clifford/multi_vector.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"
#include <boost/test/auto_unit_test.hpp>

#include <boost/mpl/list_c.hpp>
#include <boost/static_assert.hpp>

using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_multi_vector)
{   
    typedef algebra<3>    e_space; // euclidian
    typedef algebra<4, 1> c_space; // conformal
    
    typedef multi_vector<float, make_grade_list<0>::value,    e_space> e_scalar;
    typedef multi_vector<float, make_grade_list<1>::value,    e_space> e_vector;
    typedef multi_vector<float, make_grade_list<2>::value,    e_space> e_bi_vector;
    typedef multi_vector<float, make_grade_list<3>::value,    e_space> e_pseudo_scalar;
    typedef multi_vector<float, make_grade_list<0, 2>::value, e_space> e_rotor;

    BOOST_STATIC_ASSERT(sizeof(e_scalar)        == 1 * sizeof(float));
    BOOST_STATIC_ASSERT(sizeof(e_vector)        == 3 * sizeof(float));
    BOOST_STATIC_ASSERT(sizeof(e_bi_vector)     == 3 * sizeof(float));
    BOOST_STATIC_ASSERT(sizeof(e_pseudo_scalar) == 1 * sizeof(float));
    BOOST_STATIC_ASSERT(sizeof(e_rotor)         == 4 * sizeof(float));
    
    e_scalar        e_a(1.0f);
    e_vector        e_b(1.0f, 0.0f, 4.0f);
    e_bi_vector     e_d(1.0f, 2.0f, 4.0f);
    e_pseudo_scalar e_c(-4.0f);
    e_rotor         e_r(0.0f, 1.0f, 2.0f, 3.0f);    

    // should compile
    e_a = 3.0f;
    e_c = 1.0f;
    
    // should not compile
    // e_b = 1.0f;

    typedef multi_vector<int, make_grade_list<0>::value,    c_space> c_scalar;
    typedef multi_vector<int, make_grade_list<1>::value,    c_space> c_vector;
    typedef multi_vector<int, make_grade_list<2>::value,    c_space> c_bi_vector;
    typedef multi_vector<int, make_grade_list<3>::value,    c_space> c_tri_vector;
    typedef multi_vector<int, make_grade_list<4>::value,    c_space> c_4_blade;
    typedef multi_vector<int, make_grade_list<5>::value,    c_space> c_pseudo_scalar;
    typedef multi_vector<int, make_grade_list<0, 2>::value, c_space> c_rotor;

    typedef multi_vector<int, make_grade_list<0, 1, 2, 3, 4, 5>::value, c_space> c_multi_vector;

    BOOST_STATIC_ASSERT(sizeof(c_scalar)        ==  1 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_vector)        ==  5 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_bi_vector)     == 10 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_tri_vector)    == 10 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_4_blade)       ==  5 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_pseudo_scalar) ==  1 * sizeof(int));
    BOOST_STATIC_ASSERT(sizeof(c_rotor)         == 11 * sizeof(int));

    c_scalar        c_a(0);
    c_vector        c_b(0, 1, 2, 3, 4);
    c_bi_vector     c_d(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    c_tri_vector    c_e(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    c_4_blade       c_f(0, 1, 2, 3, 4);
    c_pseudo_scalar c_g(0);

    BOOST_CHECK(c_a[0] == 0);
    
    BOOST_CHECK(c_b[0] == 0);
    BOOST_CHECK(c_b[1] == 1);
    BOOST_CHECK(c_b[2] == 2);
    BOOST_CHECK(c_b[3] == 3);
    BOOST_CHECK(c_b[4] == 4);
    
    BOOST_CHECK(c_d[0] == 0);
    BOOST_CHECK(c_d[1] == 1);
    BOOST_CHECK(c_d[2] == 2);
    BOOST_CHECK(c_d[3] == 3);
    BOOST_CHECK(c_d[4] == 4);
    BOOST_CHECK(c_d[5] == 5);
    BOOST_CHECK(c_d[6] == 6);
    BOOST_CHECK(c_d[7] == 7);
    BOOST_CHECK(c_d[8] == 8);
    BOOST_CHECK(c_d[9] == 9);

    c_f *= 4;

    BOOST_CHECK(c_f[0] == 0*4);
    BOOST_CHECK(c_f[1] == 1*4);
    BOOST_CHECK(c_f[2] == 2*4);
    BOOST_CHECK(c_f[3] == 3*4);
    BOOST_CHECK(c_f[4] == 4*4);

    c_f /= 4;    

    c_4_blade c_f_from_assignment;
    c_f_from_assignment [no_alias] = c_f;
    BOOST_CHECK(c_f_from_assignment[0] == 0);
    BOOST_CHECK(c_f_from_assignment[1] == 1);
    BOOST_CHECK(c_f_from_assignment[2] == 2);
    BOOST_CHECK(c_f_from_assignment[3] == 3);
    BOOST_CHECK(c_f_from_assignment[4] == 4);

    e_rotor e_r_from_assignment;
    e_r_from_assignment [no_alias] = e_r;
    BOOST_CHECK(e_r_from_assignment[0] == 0.0f);
    BOOST_CHECK(e_r_from_assignment[1] == 1.0f);
    BOOST_CHECK(e_r_from_assignment[2] == 2.0f);
    BOOST_CHECK(e_r_from_assignment[3] == 3.0f);

    e_rotor e_r_from_copy_ctor(e_r);
    BOOST_CHECK(e_r == e_r_from_copy_ctor);
    
    e_rotor e_r_from_aliased_assignment;
    e_r_from_aliased_assignment = e_r;
    BOOST_CHECK(e_r == e_r_from_aliased_assignment);

    e_rotor e_r_from_addition(e_r);
    e_r_from_addition [no_alias] += e_r;
    BOOST_CHECK(e_r_from_addition[0] == 2.0f * 0.0f);
    BOOST_CHECK(e_r_from_addition[1] == 2.0f * 1.0f);
    BOOST_CHECK(e_r_from_addition[2] == 2.0f * 2.0f);
    BOOST_CHECK(e_r_from_addition[3] == 2.0f * 3.0f);

    e_rotor e_r_from_subtraction(e_r);
    e_r_from_subtraction [no_alias] -= e_r;
    BOOST_CHECK(e_r_from_subtraction[0] == 0.0f);
    BOOST_CHECK(e_r_from_subtraction[1] == 0.0f);
    BOOST_CHECK(e_r_from_subtraction[2] == 0.0f);
    BOOST_CHECK(e_r_from_subtraction[3] == 0.0f);

    c_multi_vector c_mv;
    c_mv [no_alias] = c_e;
    BOOST_CHECK(c_mv[ 0] == 0);
    BOOST_CHECK(c_mv[ 1] == 0);
    BOOST_CHECK(c_mv[ 2] == 0);
    BOOST_CHECK(c_mv[ 3] == 0);
    BOOST_CHECK(c_mv[ 4] == 0);
    BOOST_CHECK(c_mv[ 5] == 0);
    BOOST_CHECK(c_mv[ 7] == 0);
    BOOST_CHECK(c_mv[ 8] == 0);
    BOOST_CHECK(c_mv[ 9] == 0);
    BOOST_CHECK(c_mv[10] == 0);
    BOOST_CHECK(c_mv[11] == 0);
    BOOST_CHECK(c_mv[12] == 0);
    BOOST_CHECK(c_mv[13] == 0);
    BOOST_CHECK(c_mv[14] == 0);
    BOOST_CHECK(c_mv[15] == 0);
    BOOST_CHECK(c_mv[16] == 0);
    BOOST_CHECK(c_mv[17] == 1);
    BOOST_CHECK(c_mv[18] == 2);
    BOOST_CHECK(c_mv[19] == 3);
    BOOST_CHECK(c_mv[20] == 4);
    BOOST_CHECK(c_mv[21] == 5);
    BOOST_CHECK(c_mv[22] == 6);
    BOOST_CHECK(c_mv[23] == 7);
    BOOST_CHECK(c_mv[24] == 8);
    BOOST_CHECK(c_mv[25] == 9);
    BOOST_CHECK(c_mv[26] == 0);
    BOOST_CHECK(c_mv[27] == 0);
    BOOST_CHECK(c_mv[28] == 0);
    BOOST_CHECK(c_mv[29] == 0);
    BOOST_CHECK(c_mv[30] == 0);
    BOOST_CHECK(c_mv[31] == 0);

    c_multi_vector c_mv_aliased;
    c_mv_aliased = c_e;
    BOOST_CHECK(c_mv[ 0] == 0);
    BOOST_CHECK(c_mv[ 1] == 0);
    BOOST_CHECK(c_mv[ 2] == 0);
    BOOST_CHECK(c_mv[ 3] == 0);
    BOOST_CHECK(c_mv[ 4] == 0);
    BOOST_CHECK(c_mv[ 5] == 0);
    BOOST_CHECK(c_mv[ 7] == 0);
    BOOST_CHECK(c_mv[ 8] == 0);
    BOOST_CHECK(c_mv[ 9] == 0);
    BOOST_CHECK(c_mv[10] == 0);
    BOOST_CHECK(c_mv[11] == 0);
    BOOST_CHECK(c_mv[12] == 0);
    BOOST_CHECK(c_mv[13] == 0);
    BOOST_CHECK(c_mv[14] == 0);
    BOOST_CHECK(c_mv[15] == 0);
    BOOST_CHECK(c_mv[16] == 0);
    BOOST_CHECK(c_mv[17] == 1);
    BOOST_CHECK(c_mv[18] == 2);
    BOOST_CHECK(c_mv[19] == 3);
    BOOST_CHECK(c_mv[20] == 4);
    BOOST_CHECK(c_mv[21] == 5);
    BOOST_CHECK(c_mv[22] == 6);
    BOOST_CHECK(c_mv[23] == 7);
    BOOST_CHECK(c_mv[24] == 8);
    BOOST_CHECK(c_mv[25] == 9);
    BOOST_CHECK(c_mv[26] == 0);
    BOOST_CHECK(c_mv[27] == 0);
    BOOST_CHECK(c_mv[28] == 0);
    BOOST_CHECK(c_mv[29] == 0);
    BOOST_CHECK(c_mv[30] == 0);
    BOOST_CHECK(c_mv[31] == 0);

    c_multi_vector c_mv_from_copy_ctor(c_e);
    BOOST_CHECK(c_mv[ 0] == 0);
    BOOST_CHECK(c_mv[ 1] == 0);
    BOOST_CHECK(c_mv[ 2] == 0);
    BOOST_CHECK(c_mv[ 3] == 0);
    BOOST_CHECK(c_mv[ 4] == 0);
    BOOST_CHECK(c_mv[ 5] == 0);
    BOOST_CHECK(c_mv[ 7] == 0);
    BOOST_CHECK(c_mv[ 8] == 0);
    BOOST_CHECK(c_mv[ 9] == 0);
    BOOST_CHECK(c_mv[10] == 0);
    BOOST_CHECK(c_mv[11] == 0);
    BOOST_CHECK(c_mv[12] == 0);
    BOOST_CHECK(c_mv[13] == 0);
    BOOST_CHECK(c_mv[14] == 0);
    BOOST_CHECK(c_mv[15] == 0);
    BOOST_CHECK(c_mv[16] == 0);
    BOOST_CHECK(c_mv[17] == 1);
    BOOST_CHECK(c_mv[18] == 2);
    BOOST_CHECK(c_mv[19] == 3);
    BOOST_CHECK(c_mv[20] == 4);
    BOOST_CHECK(c_mv[21] == 5);
    BOOST_CHECK(c_mv[22] == 6);
    BOOST_CHECK(c_mv[23] == 7);
    BOOST_CHECK(c_mv[24] == 8);
    BOOST_CHECK(c_mv[25] == 9);
    BOOST_CHECK(c_mv[26] == 0);
    BOOST_CHECK(c_mv[27] == 0);
    BOOST_CHECK(c_mv[28] == 0);
    BOOST_CHECK(c_mv[29] == 0);
    BOOST_CHECK(c_mv[30] == 0);
    BOOST_CHECK(c_mv[31] == 0);
}
