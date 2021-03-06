// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_SCALAR_PRODUCT_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_SCALAR_PRODUCT_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/bool.hpp>

#include <vital/math/clifford/operators/detail/product_impl.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

                struct scalar_product_predicate
                {
                    template <int ResultGrade, int LhsGrade, int RhsGrade>
                    struct apply : boost::mpl::bool_<ResultGrade == 0> {};
                };
            }

VITAL_MATH_CLIFFORD_PRODUCT_IMPL(scalar_product, detail::scalar_product_predicate)

}}}

#endif
