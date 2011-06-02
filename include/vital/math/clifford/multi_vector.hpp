// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_MULTI_VECTOR_HPP
#define VITAL_MATH_CLIFFORD_MULTI_VECTOR_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <vital/math/clifford/algebra.hpp>
#include <vital/math/clifford/limits.hpp>
#include <vital/math/clifford/detail/to_index.hpp>
#include <vital/math/clifford/detail/to_bitwise_repr.hpp>
#include <vital/math/clifford/detail/num_bits_set.hpp>
#include <vital/math/clifford/detail/expression.hpp>
#include <vital/math/clifford/detail/enable_if_for_expression.hpp>
#include <vital/math/clifford/grade_list/num_scalars_for_grade_list.hpp>


#ifdef _MSC_VER
    #pragma warning(push, 4)
    #pragma warning(disable:4244)    
    #pragma warning(disable:4512)    
#endif

#include <boost/mpl/bool.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            
// --------------------------------------------------------------------------------------
enum no_alias_tag { no_alias };

// --------------------------------------------------------------------------------------
template <class T, int GradeList, class Algebra>
struct multi_vector : detail::expression
{
    typedef T         scalar_type;
    typedef Algebra   algebra;
    static const int grade_list = GradeList;
    

    typedef typename detail::num_scalars_for_grade_list<GradeList, Algebra>::type size;

    typedef multi_vector<T, GradeList, Algebra> this_type;

    multi_vector() { for (int i = 0; i < size::value; ++i) _m[i] = scalar_type(); }

    #include <vital/math/clifford/pp/pp_multi_vector_nary_ctor.hpp>
    #include <vital/math/clifford/pp/pp_multi_vector_scalar_assignment.hpp>
    #include <vital/math/clifford/pp/pp_multi_vector_no_alias_assignment.hpp>
    #include <vital/math/clifford/pp/pp_multi_vector_alias_assignment.hpp>    

    template<class Expr>
    multi_vector(const Expr& expr, typename detail::enable_if_for_expression<Expr>::type* = 0)
    {
        (*this)[no_alias] = expr;
    }

private:

    template <int BitwiseRepr> scalar_type get_impl(boost::mpl::true_ ) const { return _m[detail::to_index<grade_list, algebra, BitwiseRepr>::type::value]; }
    template <int BitwiseRepr> scalar_type get_impl(boost::mpl::false_) const { return scalar_type(); }

public:

    template <int BitwiseRepr>
    scalar_type get() const
    {
        const int grade = detail::num_bits_set_c<BitwiseRepr>::value;
        return get_impl<BitwiseRepr>(boost::mpl::bool_<0 != (GradeList & (1<<grade))>());
    }

    const scalar_type& operator [] (int i) const { return _m[i]; }
          scalar_type& operator [] (int i)       { return _m[i]; }

    this_type& operator *= (const scalar_type& s)
    {
        for (int i = 0; i < size::value; ++i)
            _m[i] *= s;
        return *this;
    }

    this_type& operator /= (const scalar_type& s)
    {
        for (int i = 0; i < size::value; ++i)
            _m[i] /= s;        
        return *this;
    }

private:

    scalar_type _m[size::value];
};

// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression<Expr, bool>::type operator == (const Expr& lhs, const Expr& rhs)
{
    for (int i = 0; i < Expr::size::value; ++i)
        if (lhs[i] != rhs[i])
            return false;
    
    return true;
}

// --------------------------------------------------------------------------------------
template<class Expr>
typename detail::enable_if_for_expression<Expr, bool>::type operator != (const Expr& lhs, const Expr& rhs)
{
    return !(lhs == rhs);
}

}}}

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif
