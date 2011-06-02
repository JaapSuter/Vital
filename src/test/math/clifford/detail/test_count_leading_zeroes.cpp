// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/count_leading_zeroes.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>
#include <cstddef>

#ifdef _MSC_VER
    #pragma warning(disable: 4127)
#endif

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
int runtime_count_leading_zeroes(int n)
{
    const int num_bits_in_zero_on_this_platform = 31;

    if (n == 0)
        return num_bits_in_zero_on_this_platform;

    int num = 0;
    
    while ((n & 1) == 0)
    {
        n >>= 1;
        ++num;
    }

    return num;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_count_leading_zeroes)
{
    #define test_n(_z_, _n_, _ignore_)                      \
        BOOST_CHECK                                         \
        ((                                                  \
            runtime_count_leading_zeroes((_n_))   \
        ==                                                  \
            count_leading_zeroes<boost::mpl::int_<(_n_)> >::type::value  \
        ));

    #define test_up_til 31

    BOOST_PP_REPEAT(test_up_til, test_n, ignored)

    #undef test_up_til
    #undef test_n
}
