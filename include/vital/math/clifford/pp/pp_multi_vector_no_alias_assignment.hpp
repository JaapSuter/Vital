// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

// Never include this header directly, it is only meant to be included by multi_vector.hpp

private:

    struct no_alias_proxy
    {
        no_alias_proxy(this_type& mv) : _apply_to(mv) {}

        #define local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_IMPL(_operator_name_, _operator_)                     \
            template<class Expr, int Idx> void _operator_name_(const Expr&     , boost::mpl::bool_<false>) {}       \
            template<class Expr, int Idx> void _operator_name_(const Expr& expr, boost::mpl::bool_<true>)           \
            {                                                                                                       \
            _apply_to[Idx] _operator_ expr.get<detail::to_bitwise_repr<grade_list, algebra, Idx>::type::value>();   \
            }

            local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_IMPL(assign,      =)
            local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_IMPL(assign_add, +=)
            local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_IMPL(assign_sub, -=)

        #undef local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_IMPL

        template<int Idx>
        struct deferred_contains
        {
            typedef typename detail::num_bits_set
            <
                typename detail::to_bitwise_repr                                          
                <                                                                
                    grade_list,                                                  
                    algebra,                                                     
                    Idx
                >::type
            >::type grade;

            typedef boost::mpl::bool_<0 != (grade_list & (1 << grade::value))> type;
        };

        #define local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_CALL(_z_, _n_, _operator_name_)   \
            _operator_name_<Expr, _n_>                                                          \
            (                                                                                   \
                expr,                                                                           \
                typename boost::mpl::eval_if_c                                                  \
                <                                                                               \
                    (_n_ < size::value),                                                        \
                    deferred_contains<_n_>,                                                     \
                    boost::mpl::bool_<false>                                                    \
                >::type()                                                                       \
            );

        #define local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_IMPL(_operator_name_, _operator_) \
            template <class Expr>                                                            \
            typename detail::enable_if_for_expression<Expr, this_type&>::type                \
            operator _operator_ (const Expr& expr)                                           \
            {                                                                                \
                BOOST_PP_REPEAT                                                              \
                (                                                                            \
                    VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE,                               \
                    local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_CALL,                      \
                    _operator_name_                                                          \
                )                                                                            \
                                                                                             \
                return _apply_to;                                                            \
            }

        local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_IMPL(assign,      =)
        local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_IMPL(assign_add, +=)
        local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_IMPL(assign_sub, -=)

        #undef local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_IMPL
        #undef local_VITAL_MATH_CLIFFORD_PROXY_ASSIGNMENT_OP_CALL

        this_type& _apply_to;
    };                

public:

    no_alias_proxy operator [] (no_alias_tag) { return no_alias_proxy(*this); }
