// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_EQUALITY_HPP
#define VITAL_MATH_CLIFFORD_EQUALITY_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/eval_if.hpp>

#include <vital/math/clifford/detail/to_bitwise_repr.hpp>
#include <vital/math/clifford/detail/enable_if_for_expression_pair.hpp>

namespace vital {
    namespace math {
        namespace clifford {
            namespace detail {

                template<class Lhs, class Rhs, class Idx>
                bool equality_impl(const Lhs&, const Rhs&, boost::mpl::false_) { return true; }

                template<class Lhs, class Rhs, class BitwiseRepr>
                bool equality_impl(const Lhs& lhs, const Rhs& rhs, boost::mpl::true_) 
                { 
                    return lhs.template get<BitwiseRepr>() == rhs.template get<BitwiseRepr>();
                }
            }

template<class Lhs, class Rhs>
typename detail::enable_if_for_expression_pair
<
    Lhs,
    Rhs,
    bool
>::type operator == (const Lhs& lhs, const Rhs& rhs)
{
    // todo
    (void)rhs;
    (void)lhs;
    return true;
}
    
template<class Lhs, class Rhs>
typename detail::enable_if_for_expression_pair
<
    Lhs,
    Rhs,
    bool
>::type operator != (const Lhs& lhs, const Rhs& rhs)
{
    return !(lhs == rhs);
}

}}}

#endif
