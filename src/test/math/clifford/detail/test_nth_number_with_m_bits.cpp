// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/detail/nth_number_with_m_bits.hpp"
#include <boost/test/auto_unit_test.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

#ifdef _MSC_VER
    #pragma warning(disable: 4127)
#endif

using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
int runtime_nth_number_with_m_bits(int n, int m)
{
    int ret = 0;
    while (true)
    {
        int num_bits = 0;
        int ret_tmp = ret;
        while (ret_tmp)
        {
            if (ret_tmp & 1)
            {
                ++num_bits;
            }
            
            ret_tmp >>= 1;
        }

        if (num_bits == m)
        {
            if (n == 0)
                break;
            --n;           
        }
        
        ++ret;        
    }
    
    return ret;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_nth_number_with_m_bits)
{
    #define test_n_m(_n_, _m_)                              \
        BOOST_CHECK                                         \
        ((                                                  \
            runtime_nth_number_with_m_bits((_n_), (_m_))    \
        ==                                                  \
            nth_number_with_m_bits<boost::mpl::int_<(_n_)>, boost::mpl::int_<(_m_)> >::type::value  \
        ));

    test_n_m(0, 0);
    test_n_m(0, 1);    
    test_n_m(0, 2);
    test_n_m(0, 3);
    test_n_m(0, 4);
    test_n_m(0, 5);
    test_n_m(0, 6);
    test_n_m(0, 7);

    test_n_m(1, 1);
    test_n_m(1, 2);
    test_n_m(1, 3);
    test_n_m(1, 4);
    test_n_m(1, 5);
    test_n_m(1, 6);
    test_n_m(1, 7);

    test_n_m(2, 1);
    test_n_m(2, 2);
    test_n_m(2, 3);
    test_n_m(2, 4);
    test_n_m(2, 5);
    test_n_m(2, 6);
    test_n_m(2, 7);

    test_n_m(3, 1);
    test_n_m(3, 2);
    test_n_m(3, 3);
    test_n_m(3, 4);
    test_n_m(3, 5);
    test_n_m(3, 6);
    test_n_m(3, 7);

    test_n_m(4, 1);
    test_n_m(4, 2);
    test_n_m(4, 3);
    test_n_m(4, 4);
    test_n_m(4, 5);
    test_n_m(4, 6);
    test_n_m(4, 7);

    test_n_m(6, 1);
    test_n_m(6, 2);
    test_n_m(6, 3);
    test_n_m(6, 4);
    test_n_m(6, 5);
    test_n_m(6, 6);
    test_n_m(6, 7);

    test_n_m(7, 1);
    test_n_m(7, 2);
    test_n_m(7, 3);
    test_n_m(7, 4);
    test_n_m(7, 5);
    test_n_m(7, 6);
    test_n_m(7, 7);
    
    #undef test_n_m
}
