// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

// Never include this header directly, it is only meant to be included by multi_vector.hpp

private:

    template<class S, int Nary>
    struct enable_nary_ctor
        : boost::mpl::and_
        <
            typename boost::is_convertible<S, scalar_type>::type,
            boost::mpl::bool_<Nary == size::value>
        >::type {};

    #define local_VITAL_MATH_CLIFFORD_NARY_CTOR_IMPL_ASSIGNMENT(_z_, _n_, _ignored_) _m[_n_] = BOOST_PP_CAT(s, _n_);
    #define local_VITAL_MATH_CLIFFORD_NARY_CTOR(_z_, _n_, _ignored_)        \
        template<BOOST_PP_ENUM_PARAMS(_n_, class S)>                        \
        explicit multi_vector                                               \
        (                                                                   \
            BOOST_PP_ENUM_BINARY_PARAMS(_n_, const S, &s)                   \
            ,typename boost::enable_if<typename enable_nary_ctor<S0, _n_>::type>::type* = 0 \
        )                                                                   \
        {                                                                   \
            BOOST_PP_REPEAT(_n_, local_VITAL_MATH_CLIFFORD_NARY_CTOR_IMPL_ASSIGNMENT, ignored) \
        }

public:

    BOOST_PP_REPEAT_FROM_TO
    (
        1,
        BOOST_PP_INC(VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE),
        local_VITAL_MATH_CLIFFORD_NARY_CTOR, 
        ignored
    )

    #undef local_VITAL_MATH_CLIFFORD_NARY_CTOR
    #undef local_VITAL_MATH_CLIFFORD_NARY_CTOR_IMPL_ASSIGNMENT
