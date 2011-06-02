// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_GEOMETRIC_PRODUCT_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_GEOMETRIC_PRODUCT_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/bool.hpp>
#include <vital/math/clifford/operators/detail/product_impl.hpp>

namespace vital {
    namespace math {
        namespace clifford {            
            namespace detail {

                struct geometric_product_predicate
                {
                    template <int ResultGrade, int LhsGrade, int RhsGrade>
                    struct apply : boost::mpl::true_ {};
                };
            }

VITAL_MATH_CLIFFORD_PRODUCT_IMPL(operator *, detail::geometric_product_predicate)

}}}

#endif
