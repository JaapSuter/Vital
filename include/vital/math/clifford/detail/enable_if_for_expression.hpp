// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_DETAIL_ENABLE_IF_FOR_EXPRESSION_HPP
#define VITAL_MATH_CLIFFORD_DETAIL_ENABLE_IF_FOR_EXPRESSION_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <vital/math/clifford/detail/expression.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

template <class Expr, class R = void>
struct enable_if_for_expression : boost::enable_if
<
    typename boost::is_convertible<Expr, detail::expression>::type, 
    R
>  {};


}}}}

#endif
