// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_ADDITION_HPP
#define VITAL_MATH_CLIFFORD_ADDITION_HPP

#ifdef _MSC_VER
    #pragma once
    #pragma warning(push, 4)
    #pragma warning(disable:4512)
#endif

#include <vital/math/clifford/detail/expression.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <vital/math/clifford/detail/enable_if_for_expression_pair.hpp>

namespace vital {
    namespace math {
        namespace clifford {

// --------------------------------------------------------------------------------------
#define VITAL_MATH_CLIFFORD_EXPR_ADDITION_IMPL(_name_, _operator_)                                      \
    template<class Lhs, class Rhs>                                                                      \
    struct expr_addition_ ## _name_ : detail::expression                                                \
    {                                                                                                   \
        typedef typename Lhs::scalar_type scalar_type;                                                  \
        typedef typename Lhs::algebra     algebra;                                                      \
                                                                                                        \
        expr_addition_ ## _name_(const Lhs& lhs, const Rhs& rhs) : _lhs(lhs), _rhs(rhs) {}              \
                                                                                                        \
        template<int BitwiseRepr>                                                                       \
        scalar_type get() const { return _lhs.get<BitwiseRepr>() _operator_ _rhs.get<BitwiseRepr>(); }  \
                                                                                                        \
    private:                                                                                            \
        const Lhs& _lhs;                                                                                \
        const Rhs& _rhs;                                                                                \
    };                                                                                                  \
                                                                                                        \
    template<class Lhs, class Rhs>                                                                      \
    typename detail::enable_if_for_expression_pair                                                      \
    <                                                                                                   \
        Lhs,                                                                                            \
        Rhs,                                                                                            \
        expr_addition_ ## _name_<Lhs, Rhs>                                                              \
    >::type                                                                                             \
    operator _operator_ (const Lhs& lhs, const Rhs& rhs)                                                \
    {                                                                                                   \
        return expr_addition_ ## _name_<Lhs, Rhs>(lhs, rhs);                                            \
    }

VITAL_MATH_CLIFFORD_EXPR_ADDITION_IMPL(addition,    +)
VITAL_MATH_CLIFFORD_EXPR_ADDITION_IMPL(subtraction, -)

#undef VITAL_MATH_CLIFFORD_EXPR_ADDITION_IMPL
    
}}}

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif
