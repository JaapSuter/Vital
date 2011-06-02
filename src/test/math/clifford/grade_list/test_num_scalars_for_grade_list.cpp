// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/grade_list/num_scalars_for_grade_list.hpp"
#include <vital/math/clifford/grade_list/make_grade_list.hpp>
#include "vital/math/clifford/algebra.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>


using namespace vital::math::clifford::detail;
using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_num_scalars_for_grade_list)
{
    typedef algebra<1, 0> _1_0_d;
    typedef algebra<2, 0> _2_0_d;
    typedef algebra<3, 0> _3_0_d;
    typedef algebra<3, 1> _4_0_d;
    typedef algebra<4, 1> _4_1_d;

    const int _0_grade = make_grade_list<0>::value;
    const int _1_grade = make_grade_list<1>::value;
    const int _2_grade = make_grade_list<2>::value;
    const int _3_grade = make_grade_list<3>::value;
    const int _4_grade = make_grade_list<4>::value;
    const int _5_grade = make_grade_list<5>::value;

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_grade, _4_1_d>::type::value == 1));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_1_grade, _4_1_d>::type::value == 5));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_2_grade, _4_1_d>::type::value == 10));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_3_grade, _4_1_d>::type::value == 10));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_4_grade, _4_1_d>::type::value == 5));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_5_grade, _4_1_d>::type::value == 1));

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_grade, _4_0_d>::type::value == 1));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_1_grade, _4_0_d>::type::value == 4));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_2_grade, _4_0_d>::type::value == 6));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_3_grade, _4_0_d>::type::value == 4));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_4_grade, _4_0_d>::type::value == 1));

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_grade, _3_0_d>::type::value == 1));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_1_grade, _3_0_d>::type::value == 3));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_2_grade, _3_0_d>::type::value == 3));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_3_grade, _3_0_d>::type::value == 1));

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_grade, _2_0_d>::type::value == 1));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_1_grade, _2_0_d>::type::value == 2));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_2_grade, _2_0_d>::type::value == 1));

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_grade, _1_0_d>::type::value == 1));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_1_grade, _1_0_d>::type::value == 1));

    const int _0_1_grade = make_grade_list<0, 1>::value;
    const int _0_2_grade = make_grade_list<0, 2>::value;
    const int _0_3_grade = make_grade_list<0, 3>::value;
    const int _0_4_grade = make_grade_list<0, 4>::value;
    const int _0_5_grade = make_grade_list<0, 5>::value;

    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_1_grade, _4_1_d>::type::value == 6));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_2_grade, _4_1_d>::type::value == 11));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_3_grade, _4_1_d>::type::value == 11));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_4_grade, _4_1_d>::type::value == 6));
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<_0_5_grade, _4_1_d>::type::value == 2));

    const int all_grades = make_grade_list<0, 1, 2, 3, 4, 5>::value;
    BOOST_STATIC_ASSERT((num_scalars_for_grade_list<all_grades, _4_1_d>::type::value == 32));
}
