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
#include "vital/math/clifford/sign_table/sign_table_4_1.hpp"
#include "vital/math/clifford/sign_table/sign_table_3_0.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/static_assert.hpp>

namespace cl = vital::math::clifford;

// this test is based on "Circle and sphere blending with 
// conformal geometric algebra" by by Chris Doran from the 
// Astrophysics Group, Cavendish Laboratory, Madingley Road

typedef cl::algebra<4, 1> space;
typedef cl::algebra<3, 0> euclid_space;

typedef cl::multi_vector<double, cl::make_grade_list<0>::value, space> scalar;
typedef cl::multi_vector<double, cl::make_grade_list<1>::value, space> vector;
typedef cl::multi_vector<double, cl::make_grade_list<2>::value, space> bi_vector;
typedef cl::multi_vector<double, cl::make_grade_list<3>::value, space> tri_vector;
typedef cl::multi_vector<double, cl::make_grade_list<4>::value, space> quad_vector;

typedef cl::multi_vector<double, cl::make_grade_list<0>::value, euclid_space> euclid_scalar;
typedef cl::multi_vector<double, cl::make_grade_list<1>::value, euclid_space> euclid_vector;

// conformal space global constants
namespace
{
    vector e_0(0.0, 0.0, 0.0, 0.0, 1.0);
    vector e_4(1.0, 0.0, 0.0, 0.0, 0.0);

    vector n  = e_4 + e_0;
    vector n_ = e_4 - e_0;
}

// utility function to make a conformal vector from a euclidian vector
vector make_conformal(const euclid_vector& x)
{
    // equation 5

    euclid_scalar sqr_x = scalar_product(x, x);

    vector X = 2.0 * vector(0.0, x[0], x[1], x[2], 0.0) + sqr_x[0] * n - n_;

    BOOST_CHECK(X * X == scalar(0.0));

    return X;
}

// from conformal vector to euclidian vector
euclid_vector make_euclid(const vector& x)
{
    // equation 6
    scalar d = -inner_product(x, n);
    return euclid_vector(x[1] / d[0], x[2] / d[0], x[3] / d[0]);
}

// makes a circle (or line if only two points specified)
tri_vector make_circle(const vector& a, const vector& b, const vector& c = n)
{
    bi_vector tmp = outer_product(b, c);
    tri_vector t = outer_product(a, tmp);
    return t;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_5d_conformal)
{
    BOOST_CHECK(e_0 * e_0 == scalar(-1.0)); // equation 1
    BOOST_CHECK(e_4 * e_4 == scalar( 1.0)); 
        
    BOOST_CHECK(inner_product(n, n_) == scalar(2.0)); // equation 2

    // test the invertability of the conformal split
    {
        euclid_vector ev(3.0, 16.0, -8.0);
        vector cv = make_conformal(ev);
        euclid_vector ev_ = make_euclid(cv);
        BOOST_CHECK(ev_ == ev);
    }

    // test the distance between two points
    {
        euclid_vector ea(4.0, -5.0, 13.0);
        euclid_vector eb(-5.0, 18.0, 3.0);

        euclid_scalar euclid_dist = (eb-ea) * (eb-ea);

        vector ca = make_conformal(ea);
        vector cb = make_conformal(eb);

        scalar conformal_dist = inner_product(ca, cb);

        BOOST_CHECK(conformal_dist[0] == -2.0 * euclid_dist[0]); // equation 8
    }

    
    // test the line-detection method for circles
    {
        tri_vector line = make_circle(make_conformal(euclid_vector(3.0, 0.0, -4.0)),
                                      make_conformal(euclid_vector(2.0, 0.0,  4.0)));

        BOOST_CHECK(outer_product(line, n) == scalar(0.0)); // equation 32
    }

    // test the radius of a circle
    {
        tri_vector circle = make_circle(make_conformal(euclid_vector( 2.0, 0.0, 0.0)),
                                        make_conformal(euclid_vector( 0.0, 2.0, 0.0)),
                                        make_conformal(euclid_vector(-2.0, 0.0, 0.0)));

        // equation 34
        quad_vector tmp = outer_product(circle, n);
        scalar denom = scalar_product(circle, circle);
        scalar sqr_radius = -(circle * circle) / denom[0];
        BOOST_CHECK(sqr_radius == scalar(2.0 * 2.0));
    }
}
