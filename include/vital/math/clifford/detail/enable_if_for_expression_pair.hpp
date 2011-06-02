// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_ENABLE_IF_FOR_EXPRESSION_PAIR_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_ENABLE_IF_FOR_EXPRESSION_PAIR_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_same.hpp>
#include <vital/math/clifford/detail/expression.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

template <class Lhs, class Rhs, class R = void>
struct enable_if_for_expression_pair : boost::enable_if_c
<
    // todo
    // boost::is_same<typename Lhs::scalar_type, typename Rhs::scalar_type>::value
    boost::is_convertible<Lhs, detail::expression>::value
 && boost::is_convertible<Rhs, detail::expression>::value,
    R
>  {};


}}}}

#endif
