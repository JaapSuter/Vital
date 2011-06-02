// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/nth_number_with_m_bits.hpp"
#include "vital/math/count_bits_set.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

#ifdef _MSC_VER
    #pragma warning(disable: 4127)
#endif

using namespace vital::math::clifford::detail;
using namespace vital::math;

int runtime_count_leading_zeroes(int n);

// --------------------------------------------------------------------------------------
int runtime_next_number_with_same_num_bits(const int n)
{
    int obvious_version = 0;
    int runtime_version_of_compile_time_code = 0;

    {
        int x = n;
        int lowest_bit_set = x & (-x);
        int lowest_bit_set_index = runtime_count_leading_zeroes(n);
        x += lowest_bit_set;
        int next_lowest_set_bit = x & (-x);
        int mask = next_lowest_set_bit - lowest_bit_set;
        x |= mask >> (lowest_bit_set_index + 1);
        runtime_version_of_compile_time_code = x;
    }

    const int num_bits_in_n = count_bits_set(n);
    for (int i = n + 1; true; ++i)
    {
        if (count_bits_set(i) == num_bits_in_n)
        {
            obvious_version = i;
            break;
        }
    }

    assert(obvious_version == runtime_version_of_compile_time_code);

    return runtime_version_of_compile_time_code;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_next_number_with_same_num_bits)
{
    #define test_n(_z_, _n_, _ignore_)                      \
        BOOST_CHECK                                         \
        ((                                                  \
            runtime_next_number_with_same_num_bits((_n_))   \
        ==                                                  \
            next_number_with_same_num_bits<boost::mpl::int_<(_n_)> >::type::value  \
        ));

    #define test_up_til 63

    BOOST_PP_REPEAT_FROM_TO(1, test_up_til, test_n, ignored)

    #undef test_up_til
    #undef test_n_m
}
