// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_SCALAR_MULTIPLICATION_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_SCALAR_MULTIPLICATION_HPP

#ifdef _MSC_VER
    #pragma once
    #pragma warning(push, 4)
    #pragma warning(disable:4512)
#endif

#include <vital/math/clifford/detail/expression.hpp>
#include <vital/math/clifford/detail/enable_if_for_expression.hpp>

// --------------------------------------------------------------------------------------
namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {
            
                // --------------------------------------------------------------------------------------
                #define VITAL_MATH_CLIFFORD_DETAIL_IMPL_SCALAR_MULTIPLICATION(_name_, _operator_)   \
                    template <class Expr>                                                           \
                    struct scalar_ ## _name_ : detail::expression                                   \
                    {                                                                               \
                        typedef typename Expr::scalar_type scalar_type;                             \
                        typedef typename Expr::algebra     algebra;                                 \
                                                                                                    \
                        scalar_ ## _name_(const Expr& expr, const scalar_type& s)                   \
                            : _expr(expr), _s(s) {}                                                 \
                                                                                                    \
                        template <int BitwiseRepr>                                                  \
                        scalar_type get() const { return _expr.get<BitwiseRepr>() _operator_ _s; }  \
                                                                                                    \
                        const Expr&        _expr;                                                   \
                        const scalar_type& _s;                                                      \
                    };

            VITAL_MATH_CLIFFORD_DETAIL_IMPL_SCALAR_MULTIPLICATION(multiplication, *)
            VITAL_MATH_CLIFFORD_DETAIL_IMPL_SCALAR_MULTIPLICATION(division, /)

            #undef VITAL_MATH_CLIFFORD_DETAIL_IMPL_SCALAR_MULTIPLICATION
        }


// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression
<
    Expr,
    detail::scalar_multiplication<Expr> 
>::type operator * (const Expr& expr, const typename Expr::scalar_type& s)
{
    return detail::scalar_multiplication<Expr>(expr, s);
}

// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression
<
    Expr,
    detail::scalar_multiplication<Expr> 
>::type operator * (const typename Expr::scalar_type& s, const Expr& expr)
{
    return detail::scalar_multiplication<Expr>(expr, s);
}

// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression
<
    Expr,
    detail::scalar_division<Expr> 
>::type operator / (const Expr& expr, const typename Expr::scalar_type& s)
{
    return detail::scalar_division<Expr>(expr, s);
}

}}}

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif
