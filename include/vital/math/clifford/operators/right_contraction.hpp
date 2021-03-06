// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_RIGHT_CONTRACTION_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_RIGHT_CONTRACTION_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/operators/detail/product_impl.hpp>

#include <boost/mpl/bool.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

                struct right_contraction_predicate
                {
                    template <int ResultGrade, int LhsGrade, int RhsGrade>
                    struct apply : boost::mpl::bool_<ResultGrade == (LhsGrade - RhsGrade)> {};
                };
            }

VITAL_MATH_CLIFFORD_PRODUCT_IMPL(right_contraction, detail::right_contraction_predicate)

}}}

#endif
