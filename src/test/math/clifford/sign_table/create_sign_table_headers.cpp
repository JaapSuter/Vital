// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#include "src/test/pch.hpp"
#include "vital/math/clifford/limits.hpp"
#include "vital/math/count_bits_set.hpp"

#ifdef _MSC_VER
    #pragma warning(disable:4127)
    #pragma warning(disable:4511)
    #pragma warning(disable:4512)
#endif

#include <boost/test/auto_unit_test.hpp>
#include <boost/lexical_cast.hpp>

#include <fstream>
#include <string>

// --------------------------------------------------------------------------------------
void create_sign_table_headers();

// --------------------------------------------------------------------------------------
BOOST_AUTO_UNIT_TEST(test_create_sign_table_headers)
{
    // remove comment to recreate sign table headers
    // create_sign_table_headers();
}

// --------------------------------------------------------------------------------------
int runtime_sign_table(int lhs_bitwise_repr, int rhs_bitwise_repr, int algebra_p, int algebra_q)
{
    const int space_dim = algebra_p + algebra_q;
    const int algebra_dim = 1 << space_dim;

    int ret = 1;
    
    for (int i = 0; i < algebra_dim; ++i)
    {
        const int bit_mask = 1 << (space_dim - i);
        const int bit_appears_in_lhs = lhs_bitwise_repr & bit_mask;
        const int bit_appears_in_rhs = rhs_bitwise_repr & bit_mask;

        const int next_lhs = lhs_bitwise_repr & ~bit_mask;
        const int next_rhs = (bit_appears_in_rhs != 0)
                           ? (rhs_bitwise_repr & ~bit_mask)
                           : (rhs_bitwise_repr |  bit_mask);
        
        const int num_swaps_in_lhs = vital::math::count_bits_set(lhs_bitwise_repr & ~((bit_mask << 1)-1));
        const int num_swaps_in_rhs = vital::math::count_bits_set(rhs_bitwise_repr & (bit_mask-1));

        const int odd_num_swaps = (num_swaps_in_lhs + num_swaps_in_rhs) & 1;

        const int next_ret = (bit_appears_in_lhs && bit_appears_in_rhs)
                           ? ((bit_mask >= (1 << algebra_p)) ? (ret * -1) : (ret))
                           : (ret);
        
        const int next_next_ret = bit_appears_in_lhs
                                ? (odd_num_swaps ? (next_ret * -1) : next_ret)
                                : next_ret;

        ret = next_next_ret;
        lhs_bitwise_repr = next_lhs;
        rhs_bitwise_repr = next_rhs;
    }

    return ret;
}

// --------------------------------------------------------------------------------------
void create_sign_table_headers()
{
    for (int i = 0; i < (VITAL_MATH_CLIFFORD_MAX_DIMENSION + 1); ++i)
    {
        for (int j = 0; ((j+i) < (VITAL_MATH_CLIFFORD_MAX_DIMENSION + 1)); ++j)
        {
            std::string file_name("../../include/vital/math/clifford/sign_table/sign_table_");
            file_name += boost::lexical_cast<std::string>(i);
            file_name += "_";
            file_name += boost::lexical_cast<std::string>(j);
            file_name += ".hpp";
    
            std::ofstream hpp_file(file_name.c_str(), std::ios_base::trunc);
            
            hpp_file << "// Copyright 2004 Jaap Suter. Distributed under the Vital\n"
                        "// Software License, Version 1.0. (See accompanying file\n"
                        "// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)\n\n";

            std::string include_guard("VITAL_MATH_CLIFFORD_SIGN_TABLE_SIGN_TABLE_");
            include_guard += boost::lexical_cast<std::string>(i);
            include_guard += "_";
            include_guard += boost::lexical_cast<std::string>(j);
            include_guard += "_HPP";

            hpp_file << "#ifndef " << include_guard << "\n";
            hpp_file << "#define " << include_guard << "\n\n";

            hpp_file << "#include <vital/math/clifford/sign_table/sign_table.hpp>\n\n";

            hpp_file << "namespace vital {\n";
            hpp_file << "\tnamespace math {\n";
            hpp_file << "\t\tnamespace clifford {\n";
            hpp_file << "\t\t\tnamespace detail {\n\n";

            hpp_file << "template <> struct sign_table< algebra<" << i << ", " << j << "> >\n{\n\n";
            hpp_file << "\tenum result\n\t{\n";
   
            for (int lhs = 0; lhs <= VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE; ++lhs)
            {
                for (int rhs = 0; rhs <= VITAL_MATH_CLIFFORD_MAX_MULTI_VECTOR_SIZE; ++rhs)
                {
                    int result = (lhs < (1<<(i+j)) && rhs < (1<<(i+j))) ? runtime_sign_table(lhs, rhs, i, j) : 0;

                    hpp_file << "\t\tvalue_" << lhs << "_" << rhs << " = " << result << ",\n";
                }
            }

            hpp_file << "\t};\n};\n\n";

            hpp_file << "\n}}}}\n";
            hpp_file << "\n#endif\n";
        }
    }
}
