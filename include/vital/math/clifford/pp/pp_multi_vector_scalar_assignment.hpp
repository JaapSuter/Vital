// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

// Never include this header directly, it is only meant to be included by multi_vector.hpp

private:

    template<class S>
    struct enable_scalar_assignment
        : boost::mpl::and_
        <
            typename boost::is_convertible<S, scalar_type>::type,
            boost::mpl::bool_<1 == size::value>
        >::type {};

public:

    template<class S>
    typename boost::enable_if
    <
        typename enable_scalar_assignment<S>::type, 
        this_type&
    >::type
    operator = (const S& s) { _m[0] = s; return *this; }

