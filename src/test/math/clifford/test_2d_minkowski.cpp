// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/algebra.hpp"
#include "vital/math/clifford/multi_vector.hpp"
#include "vital/math/clifford/grade_list/make_grade_list.hpp"
#include "vital/math/clifford/operators/scalar_multiplication.hpp"
#include "vital/math/clifford/operators/geometric_product.hpp"
#include "vital/math/clifford/operators/outer_product.hpp"
#include "vital/math/clifford/operators/inner_product.hpp"
#include "vital/math/clifford/operators/fat_dot_product.hpp"
#include "vital/math/clifford/operators/scalar_product.hpp"
#include "vital/math/clifford/operators/left_contraction.hpp"
#include "vital/math/clifford/operators/right_contraction.hpp"
#include "vital/math/clifford/operators/addition.hpp"
#include "vital/math/clifford/operators/negation.hpp"
#include "vital/math/clifford/operators/equality.hpp"
#include "vital/math/clifford/sign_table/sign_table_1_1.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/static_assert.hpp>

namespace cl = vital::math::clifford;

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_2d_minkowski)
{
    // this test the equations of chapter two in David
    // Hestenes' paper: Old Wine in New Bottles (http://modelingnts.la.asu.edu/pdf/OldWine.pdf);

    typedef cl::algebra<1, 1> minkowski_space;
    typedef cl::multi_vector<double, cl::make_grade_list<0      >::value, minkowski_space> scalar;
    typedef cl::multi_vector<double, cl::make_grade_list<1      >::value, minkowski_space> vector;
    typedef cl::multi_vector<double, cl::make_grade_list<2      >::value, minkowski_space> bi_vector;
    typedef cl::multi_vector<double, cl::make_grade_list<0, 1, 2>::value, minkowski_space> multi_vector;
                                     
    scalar one(1.0);

    vector e_plus(1.0, 0.0);

    vector e_min(0.0, 1.0);

    double sqrt2 = std::sqrt(2.0);

    vector e_star = -sqrt2 * (e_min - e_plus) / 2.0;
    vector e = e_plus * sqrt2 - e_star;
    
    scalar d;
    d [cl::no_alias] = e_star * e_star; // BOOST_CHECK_CLOSE(d[0], 0.0, 1e-4);
    d [cl::no_alias] = e      * e;      // BOOST_CHECK_CLOSE(d[0], 0.0, 1e-4);
    d [cl::no_alias] = e_star * e;      // BOOST_CHECK_CLOSE(d[0], 1.0, 1e-4);
                                
    bi_vector E = outer_product(e, e_star);

    d = E * E; BOOST_CHECK_CLOSE(d[0], 1.0, 1e-4);

    multi_vector a = one + E;
    multi_vector b = e * e_star;
    for (int i = 0; i < multi_vector::size::value; ++i)
    {
        BOOST_CHECK_CLOSE(a[i], b[i], 1e-4);
    }

    a = one - E;
    b = e_star * e;
    for (int i = 0; i < multi_vector::size::value; ++i)
    {
        BOOST_CHECK_CLOSE(a[i], b[i], 1e-4);
    }

    vector v = E * e;
    for (int i = 0; i < vector::size::value; ++i)
    {
        BOOST_CHECK_CLOSE(e[i], v[i], 1e-4);
    }

    v = -e * E;
    for (int i = 0; i < vector::size::value; ++i)
    {
        BOOST_CHECK_CLOSE(e[i], v[i], 1e-4);
    }
}
