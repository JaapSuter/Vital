// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_FAT_DOT_PRODUCT_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_FAT_DOT_PRODUCT_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/not_equal_to.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/if.hpp>

#include <vital/math/clifford/operators/detail/product_impl.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

                struct fat_dot_product_predicate
                {
                    template <int ResultGrade, int LhsGrade, int RhsGrade>
                    struct apply : boost::mpl::bool_
                    <
                        (ResultGrade ==  (LhsGrade - RhsGrade))
                     || (ResultGrade == -(LhsGrade - RhsGrade))
                    >
                    {};                    
                };
            }

VITAL_MATH_CLIFFORD_PRODUCT_IMPL(fat_dot_product, detail::fat_dot_product_predicate)

}}}

#endif
