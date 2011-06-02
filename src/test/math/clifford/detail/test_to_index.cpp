// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/to_index.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"
#include "vital/math/clifford/algebra.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

using namespace vital::math::clifford::detail;
using namespace vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_to_index)
{
    typedef algebra<1, 0> _1_0_d;
    typedef algebra<4, 1> _4_1_d;

    const int _0_grade = make_grade_list<0>::value;
    const int _1_grade = make_grade_list<1>::value;
    const int _2_grade = make_grade_list<2>::value;
    
    BOOST_STATIC_ASSERT((to_index<_0_grade, _1_0_d,  0>::type::value == 0));
    BOOST_STATIC_ASSERT((to_index<_1_grade, _1_0_d,  1>::type::value == 0));
                                                                        
    BOOST_STATIC_ASSERT((to_index<_0_grade, _4_1_d,  0>::type::value == 0));
                                                                        
    BOOST_STATIC_ASSERT((to_index<_1_grade, _4_1_d,  1>::type::value == 0));
    BOOST_STATIC_ASSERT((to_index<_1_grade, _4_1_d,  2>::type::value == 1));
    BOOST_STATIC_ASSERT((to_index<_1_grade, _4_1_d,  4>::type::value == 2));
    BOOST_STATIC_ASSERT((to_index<_1_grade, _4_1_d,  8>::type::value == 3));
    BOOST_STATIC_ASSERT((to_index<_1_grade, _4_1_d, 16>::type::value == 4));
                                                                        
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d,  3>::type::value == 0));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d,  5>::type::value == 1));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d,  6>::type::value == 2));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d,  9>::type::value == 3));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 10>::type::value == 4));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 12>::type::value == 5));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 17>::type::value == 6));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 18>::type::value == 7));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 20>::type::value == 8));
    BOOST_STATIC_ASSERT((to_index<_2_grade, _4_1_d, 24>::type::value == 9));

    const int full_multi_vector = make_grade_list<0, 1, 2, 3, 4, 5>::value;

    // scalar
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  0>::type::value ==  0));

    // vectors                                                                   
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  1>::type::value ==  1));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  2>::type::value ==  2));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  4>::type::value ==  3));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  8>::type::value ==  4));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 16>::type::value ==  5));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  3>::type::value ==  6));
                                                                                 
    // bivectors                                                                 
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  5>::type::value ==  7));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  6>::type::value ==  8));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  9>::type::value ==  9));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 10>::type::value == 10));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 12>::type::value == 11));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 17>::type::value == 12));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 18>::type::value == 13));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 20>::type::value == 14));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 24>::type::value == 15));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d,  7>::type::value == 16));
                                                                                 
    // trivectors                                                                
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 11>::type::value == 17));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 13>::type::value == 18));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 14>::type::value == 19));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 19>::type::value == 20));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 21>::type::value == 21));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 22>::type::value == 22));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 25>::type::value == 23));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 26>::type::value == 24));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 28>::type::value == 25));
                                                                                 
    // quad-vectors                                                              
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 15>::type::value == 26));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 23>::type::value == 27));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 27>::type::value == 28));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 29>::type::value == 29));
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 30>::type::value == 30));
                                                                                 
    // pseudo-scalar                                                             
    BOOST_STATIC_ASSERT((to_index<full_multi_vector, _4_1_d, 31>::type::value == 31));
}
