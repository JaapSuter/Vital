// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

// Never include this header directly, it is only meant to be included by multi_vector.hpp

#define local_VITAL_MATH_CLIFFORD_ALIAS_ASSIGNMENT_OP_IMPL(_operator_)  \
    template<class Expr>                                                \
    typename detail::enable_if_for_expression<Expr, multi_vector&>::type operator _operator_ (Expr& expr) \
    {                                                                   \
        multi_vector tmp(*this);                                        \
        tmp [no_alias] _operator_ expr;                                 \
        for (int i = 0; i < size::value; ++i)                           \
            _m[i] = tmp._m[i];                                          \
        return *this;                                                   \
    }

local_VITAL_MATH_CLIFFORD_ALIAS_ASSIGNMENT_OP_IMPL(=)
local_VITAL_MATH_CLIFFORD_ALIAS_ASSIGNMENT_OP_IMPL(+=)
local_VITAL_MATH_CLIFFORD_ALIAS_ASSIGNMENT_OP_IMPL(-=)

#undef local_VITAL_MATH_CLIFFORD_ALIAS_ASSIGNMENT_OP_IMPL
