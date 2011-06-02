// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_AUTO_HPP
#define VITAL_MATH_CLIFFORD_AUTO_HPP

#include <vital/math/clifford/multi_vector.hpp>
#include <vital/math/clifford/grade_list/grade_list_from_encoding.hpp>
#include <boost/mpl/int.hpp>

#ifdef _MSC_VER
    #pragma once
#endif


// --------------------------------------------------------------------------------------
#define VITAL_MATH_CLIFFORD_AUTO_ELEMENT(_scalar_, _algebra_, _name_, _expression_) \
        ::vital::math::clifford::multi_vector                                       \
        <                                                                           \
            _scalar_,                                                               \
            ::vital::math::clifford::detail::grade_list_from_encoding               \
            <                                                                       \
                ::boost::mpl::int_                                                  \
                <                                                                   \
                    sizeof(_expression_ ^ ::vital::math::clifford::detail::obtain_grade_list_encoding()) \
                >                                                                   \
            >::type,                                                                \
                                                                                    \
            _algebra_                                                               \
                                                                                    \
        > _name_ = _expression_


#endif
