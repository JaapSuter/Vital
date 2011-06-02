// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/grade_list/grade_list_product.hpp"

#include "vital/math/clifford/grade_list/make_grade_list.hpp"
#include "vital/math/clifford/limits.hpp"
#include "vital/math/count_bits_set.hpp"

#include <boost/test/auto_unit_test.hpp>
#include <algorithm>

#ifdef _MSC_VER
    #pragma warning(disable:4512)
    #pragma warning(disable:4100)
#endif

using namespace vital::math;
using namespace vital::math::clifford;
using namespace vital::math::clifford::detail;

// --------------------------------------------------------------------------------------
struct true_predicate
{
    template <int ResultGrade, int LhsGrade, int RhsGrade>
    struct apply : boost::mpl::true_ {};
};

// --------------------------------------------------------------------------------------
int runtime_grade_list_geometric_product(int lhs, int rhs, int space_dim)
{
    int ret_slow = 0;
    int ret_fast = 0;

    // slow naive implementation
    {
        const int algebra_dim = 1 << space_dim;

        for (int i = 0; i < algebra_dim; ++i)
            for (int j = 0; j < algebra_dim; ++j)
                if ((lhs & (1 << count_bits_set(i)))
                 && (rhs & (1 << count_bits_set(j))))
                {
                    ret_slow |= 1 << count_bits_set(i ^ j);
                }
    }

    // faster implementation
    {
        for (int i = 0; i <= space_dim; ++i)
            for (int j = 0; j <= space_dim; ++j)
                if ((lhs & (1<<i)) && (rhs & (1<<j)))
                {
                    int min_grade = std::min(i, j);
                    int max_grade = std::max(i, j);

                    int begin = max_grade - min_grade;
                    int end   = 1 + std::min(space_dim - (min_grade + max_grade - space_dim), max_grade + min_grade);

                    for (int k = begin; k < end; k += 2)
                    {
                        ret_fast |= 1 << k;
                    }
                }
    }

    if (ret_slow != ret_fast)
    {
        BOOST_CHECK(0 == static_cast<const char*>("fast runtime grade list product != slow runtime grade list product"));
    }
    
    return ret_fast;
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_runtime_grade_list_product)
{
    const int scalar_grades     = make_grade_list<0>::value;
    const int bi_vector_grades  = make_grade_list<1>::value;
    const int vector_grades     = make_grade_list<2>::value;
    const int rotor_grades      = make_grade_list<0, 2>::value;

    const int dim_2 = 2;
    const int dim_3 = 3;

    int result_grade_list = 0;
    
    result_grade_list = runtime_grade_list_geometric_product(scalar_grades, scalar_grades, dim_3);
    BOOST_CHECK(result_grade_list == scalar_grades);

    result_grade_list = runtime_grade_list_geometric_product(vector_grades, vector_grades, dim_3);
    BOOST_CHECK(result_grade_list == rotor_grades);

    result_grade_list = runtime_grade_list_geometric_product(bi_vector_grades, bi_vector_grades, dim_3);
    BOOST_CHECK(result_grade_list == rotor_grades);
    
    result_grade_list = runtime_grade_list_geometric_product(bi_vector_grades, bi_vector_grades, dim_2);
    BOOST_CHECK(result_grade_list == rotor_grades);

    result_grade_list = runtime_grade_list_geometric_product(scalar_grades, vector_grades, dim_3);
    BOOST_CHECK(result_grade_list == vector_grades);

    result_grade_list = runtime_grade_list_geometric_product(scalar_grades, bi_vector_grades, dim_3);
    BOOST_CHECK(result_grade_list == bi_vector_grades);

    std::srand(4563);
    const int try_many_random = 256;
    for (int i = 0; i < try_many_random; ++i)
    {
        const int max_dim = VITAL_MATH_CLIFFORD_MAX_DIMENSION;
        const int dim = 1 + std::rand() % max_dim;
        const int num_lhs = std::rand() % (dim + 1);
        const int num_rhs = std::rand() % (dim + 1);
        int lhs = 0;
        int rhs = 1;

        for (int i = 0; i < num_lhs; ++i)
            lhs |= 1 << (std::rand() % (dim + 1));
        
        for (int i = 0; i < num_rhs; ++i)
            rhs |= 1 << (std::rand() % (dim + 1));

        runtime_grade_list_geometric_product(lhs, rhs, dim);
    }
}

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_compile_time_grade_list_product)
{
    const int scalar_grades     = make_grade_list<0>::value;
    const int vector_grades     = make_grade_list<1>::value;
    const int bi_vector_grades  = make_grade_list<2>::value;
    
    #define VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(_lhs_, _rhs_, _dim_)    \
    {                                                                           \
        const int c_list = grade_list_product                                   \
        <                                                                       \
            _lhs_,                                                              \
            _rhs_,                                                              \
            true_predicate,                                                     \
            _dim_                                                               \
        >::value;                                                               \
                                                                                \
        BOOST_CHECK(c_list == runtime_grade_list_geometric_product(_lhs_, _rhs_, _dim_)); \
    }

    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(scalar_grades, scalar_grades, 1)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(scalar_grades, scalar_grades, 2)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(scalar_grades, scalar_grades, 3)

    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(vector_grades, vector_grades, 1)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(vector_grades, vector_grades, 2)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(vector_grades, vector_grades, 3)

    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(bi_vector_grades, bi_vector_grades, 2)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(bi_vector_grades, bi_vector_grades, 3)

    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(scalar_grades, vector_grades, 2)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(vector_grades, vector_grades, 3)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(scalar_grades, bi_vector_grades, 2)
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(vector_grades, bi_vector_grades, 3)
    
    const int all_5d_grades = make_grade_list<0, 1, 2, 3, 4, 5>::value;
    
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(all_5d_grades, all_5d_grades, 5)

    const int random_multi_vector_lhs = make_grade_list<0, 2, 3   >::value;
    const int random_multi_vector_rhs = make_grade_list<1, 3, 4, 5>::value;
    VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT(random_multi_vector_lhs, random_multi_vector_rhs, 5)

    #undef VITAL_MATH_CLIFFORD_TEST_GRADE_LIST_PRODUCT
}
