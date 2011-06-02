// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_NEGATION_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_NEGATION_HPP

#ifdef _MSC_VER
    #pragma once
    #pragma warning(push, 4)
    #pragma warning(disable:4512)
#endif

#include <vital/math/clifford/detail/expression.hpp>
#include <vital/math/clifford/detail/enable_if_for_expression.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

                template<class Expr>
                struct negation_expr : expression
                {
                    typedef typename Expr::scalar_type scalar_type;
                    typedef typename Expr::algebra     algebra;

                    negation_expr(const Expr& expr)
                        : _expr(expr) {}

                    template<int BitwiseRepr>
                    typename Expr::scalar_type get() const
                    {
                        return -_expr.get<BitwiseRepr>();
                    }

                    const Expr& _expr;
                };
            
            } // namespace detail;

// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression
<                                  
    Expr,
    detail::negation_expr<Expr>
>::type operator - (const Expr& e)
{
    return detail::negation_expr<Expr>(e);
}

}}}

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif
