// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_OPERATORS_DETAIL_PRODUCT_IMPL_HPP
#define VITAL_MATH_CLIFFORD_OPERATORS_DETAIL_PRODUCT_IMPL_HPP

#ifdef _MSC_VER
    #pragma once
    #pragma warning(push, 4)
    #pragma warning(disable:4127) // integral expression is constant, todo
    #pragma warning(disable:4512) // assignment operator could not be generated
    #pragma warning(disable:4100) // todo, remove, unreferenced paramater
#endif

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/preprocessor/repetition/repeat.hpp> 

#include <vital/math/clifford/detail/enable_if_for_expression_pair.hpp>
#include <vital/math/clifford/detail/expression.hpp>
#include <vital/math/clifford/sign_table/sign_table.hpp>
#include <vital/math/clifford/limits.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

// --------------------------------------------------------------------------------------
template<class Lhs, class Rhs, class Predicate>
struct product_expr : expression
{
    typedef typename Lhs::scalar_type scalar_type;
    typedef typename Lhs::algebra     algebra;

    product_expr(const Lhs& lhs, const Rhs& rhs) : _lhs(lhs), _rhs(rhs) {}

    template<int LhsBitwiseRepr, int RhsBitwiseRepr, int ResultBitwiseRepr>
    void result_appears(scalar_type& s) const
    {
        const bool appears_value = (LhsBitwiseRepr ^ RhsBitwiseRepr) == ResultBitwiseRepr;
        typedef boost::mpl::bool_<appears_value> appears;
        add_term<LhsBitwiseRepr, RhsBitwiseRepr>(s, appears()); 
    }

    template<int LhsBitwiseRepr, int RhsBitwiseRpr>
    void add_term(scalar_type& s, boost::mpl::true_) const
    {
        // sign table;
        s += _lhs.get<LhsBitwiseRepr>() * _rhs.get<RhsBitwiseRpr>();
    }

    template<int LhsBitwiseRepr, int RhsBitwiseRpr>
    void add_term(scalar_type&, boost::mpl::false_) const {}

    template<int ResultBitwiseRepr>
    scalar_type get() const
    {
        scalar_type s = scalar_type();

        #define VITAL_MATH_CLIFFORD_body(_z_, _rhs_bitwise_repr_, _lhs_bitwise_repr_)       \
            result_appears<_lhs_bitwise_repr_, _rhs_bitwise_repr_, ResultBitwiseRepr>(s);

        #define VITAL_MATH_CLIFFORD_over_rhs(_z_, _lhs_bitwise_repr_, _ignored_) \
            BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE, VITAL_MATH_CLIFFORD_body, _lhs_bitwise_repr_)

        BOOST_PP_REPEAT(VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE, VITAL_MATH_CLIFFORD_over_rhs, ignored)
        
        #undef VITAL_MATH_CLIFFORD_body       
        #undef VITAL_MATH_CLIFFORD_over_rhs

        return s;
    }
    
private:
    const Lhs& _lhs;
    const Rhs& _rhs;
};

    } // namespace detail

// --------------------------------------------------------------------------------------
#define VITAL_MATH_CLIFFORD_PRODUCT_IMPL(_function_name_, _predicate_)                      \
    template<class Lhs, class Rhs>                                                          \
    typename detail::enable_if_for_expression_pair                                          \
    <                                                                                       \
        Lhs,                                                                                \
        Rhs,                                                                                \
        detail::product_expr<Lhs, Rhs, _predicate_>                                         \
    >::type _function_name_ (const Lhs& lhs, const Rhs& rhs)                                \
    {                                                                                       \
        return detail::product_expr<Lhs, Rhs, _predicate_>(lhs, rhs);                       \
    }

}}}

#ifdef _MSC_VER
    #pragma once
    #pragma warning(pop)
#endif

#endif
