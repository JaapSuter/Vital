// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/nth_number_with_m_bits_inverse.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>
#include <iostream>

#ifdef _MSC_VER
    #pragma warning(disable: 4127)
#endif

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
// Defined in nth_number_with_m_bits.cpp
// --------------------------------------------------------------------------------------
int runtime_nth_number_with_m_bits(int n, int m);

// --------------------------------------------------------------------------------------
int runtime_nth_number_with_m_bits_inverse(int bitwise_repr)
{
    int num_bits = 0;
    int bitwise_repr_tmp = bitwise_repr;
    while (bitwise_repr_tmp)
    {
        if (bitwise_repr_tmp & 1)
        {
            ++num_bits;
        }
        
        bitwise_repr_tmp >>= 1;
    }

    int n = 0;
    while (runtime_nth_number_with_m_bits(n, num_bits) != bitwise_repr)
    {
        ++n;
    }

    return n;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_nth_number_with_m_bits_inverse)
{
    // This piece of code can output the list of macros used as a compiler speed-
    // up declared in nth_number_with_m_bits.hpp
    const bool output_table_of_compiler_optimization_specializations = false;
    if (output_table_of_compiler_optimization_specializations)
    {
        const int generate_table_up_to = 256;
        for (int i = 0; i < generate_table_up_to; ++i)
        {
            std::cout << "VITAL_MATH_CLIFFORD_DETAIL_nth_number_with_m_bits_inverse_SPECIALIZATION(";
            std::cout << i << ',';
            std::cout << runtime_nth_number_with_m_bits_inverse(i) << ")\n";
        }
    }

    #define test_n(_bitwise_repr_)                          \
        BOOST_CHECK                                         \
        ((                                                  \
            runtime_nth_number_with_m_bits_inverse((_bitwise_repr_))   \
        ==                                                  \
            nth_number_with_m_bits_inverse<boost::mpl::int_<(_bitwise_repr_)> >::type::value  \
        ));

    test_n(  0);
    test_n(  1);
    test_n(  2);
    test_n(  3);
    test_n(  4);
    test_n(  5);
    test_n(  6);
    test_n(  7);
    test_n(  8);
    test_n(  9);
    test_n( 10);
    test_n( 11);
    test_n( 12);
    test_n( 13);
    test_n( 14);
    test_n( 15);
    test_n( 16);
    test_n( 17);
    test_n( 18);
    test_n( 19);
    test_n( 60);
    test_n( 61);
    test_n( 62);
    test_n( 63);
    test_n( 64);
    test_n( 65);
    test_n( 66);
    test_n( 67);
    test_n( 68);
    test_n( 69);
    test_n(110);
    test_n(111);
    test_n(112);
    test_n(113);
    test_n(114);
    test_n(115);
    test_n(116);
    test_n(117);
    test_n(118);
    test_n(119);
    test_n(250);
    test_n(251);
    test_n(252);
    test_n(253);
    test_n(254);
    test_n(255);
    
    #undef test_n_m
}
