// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_NEXT_NUMBER_WITH_SAME_NUM_BITS_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_NEXT_NUMBER_WITH_SAME_NUM_BITS_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/int.hpp>
#include <vital/math/clifford/detail/count_leading_zeroes.hpp>

namespace vital {
    namespace math {
        namespace clifford {
             namespace detail {

// --------------------------------------------------------------------------------------
template<class T>
struct next_number_with_same_num_bits
{
private:
    enum
    {
        // lowest_bit_set = T::value & (-T::value),
        // lowest_bit_set_index = count_leading_zeroes<T>::type::value,
        // next_t = T::value + lowest_bit_set,
        // next_lowest_set_bit = next_t & (-next_t),
        // mask = next_lowest_set_bit - lowest_bit_set,
        // result_t = next_t | (mask >> (lowest_bit_set_index + 1))
        // 
        // Reduced into:        
        
        result_t = (T::value + (T::value & (-T::value))) | ((((T::value + (T::value & (-T::value))) & (-T::value - (T::value & (-T::value)))) - (T::value & (-T::value))) >> (count_leading_zeroes<T>::type::value + 1))
    };

public:
    typedef boost::mpl::int_<result_t> type;
};

}}}}

#endif
