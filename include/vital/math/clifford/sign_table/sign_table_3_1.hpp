// Copyright 2004 Jaap Suter. Distributed under the Vital
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.jaapsuter.com/LICENSE_1_0.txt)

#ifndef VITAL_MATH_CLIFFORD_SIGN_TABLE_SIGN_TABLE_3_1_HPP
#define VITAL_MATH_CLIFFORD_SIGN_TABLE_SIGN_TABLE_3_1_HPP

#include <vital/math/clifford/sign_table/sign_table.hpp>

namespace vital {
	namespace math {
		namespace clifford {
			namespace detail {

template <> struct sign_table< algebra<3, 1> >
{

	enum result
	{
		value_0_0 = 1,
		value_0_1 = 1,
		value_0_2 = 1,
		value_0_3 = 1,
		value_0_4 = 1,
		value_0_5 = 1,
		value_0_6 = 1,
		value_0_7 = 1,
		value_0_8 = 1,
		value_0_9 = 1,
		value_0_10 = 1,
		value_0_11 = 1,
		value_0_12 = 1,
		value_0_13 = 1,
		value_0_14 = 1,
		value_0_15 = 1,
		value_0_16 = 0,
		value_0_17 = 0,
		value_0_18 = 0,
		value_0_19 = 0,
		value_0_20 = 0,
		value_0_21 = 0,
		value_0_22 = 0,
		value_0_23 = 0,
		value_0_24 = 0,
		value_0_25 = 0,
		value_0_26 = 0,
		value_0_27 = 0,
		value_0_28 = 0,
		value_0_29 = 0,
		value_0_30 = 0,
		value_0_31 = 0,
		value_0_32 = 0,
		value_1_0 = 1,
		value_1_1 = 1,
		value_1_2 = 1,
		value_1_3 = 1,
		value_1_4 = 1,
		value_1_5 = 1,
		value_1_6 = 1,
		value_1_7 = 1,
		value_1_8 = 1,
		value_1_9 = 1,
		value_1_10 = 1,
		value_1_11 = 1,
		value_1_12 = 1,
		value_1_13 = 1,
		value_1_14 = 1,
		value_1_15 = 1,
		value_1_16 = 0,
		value_1_17 = 0,
		value_1_18 = 0,
		value_1_19 = 0,
		value_1_20 = 0,
		value_1_21 = 0,
		value_1_22 = 0,
		value_1_23 = 0,
		value_1_24 = 0,
		value_1_25 = 0,
		value_1_26 = 0,
		value_1_27 = 0,
		value_1_28 = 0,
		value_1_29 = 0,
		value_1_30 = 0,
		value_1_31 = 0,
		value_1_32 = 0,
		value_2_0 = 1,
		value_2_1 = -1,
		value_2_2 = 1,
		value_2_3 = -1,
		value_2_4 = 1,
		value_2_5 = -1,
		value_2_6 = 1,
		value_2_7 = -1,
		value_2_8 = 1,
		value_2_9 = -1,
		value_2_10 = 1,
		value_2_11 = -1,
		value_2_12 = 1,
		value_2_13 = -1,
		value_2_14 = 1,
		value_2_15 = -1,
		value_2_16 = 0,
		value_2_17 = 0,
		value_2_18 = 0,
		value_2_19 = 0,
		value_2_20 = 0,
		value_2_21 = 0,
		value_2_22 = 0,
		value_2_23 = 0,
		value_2_24 = 0,
		value_2_25 = 0,
		value_2_26 = 0,
		value_2_27 = 0,
		value_2_28 = 0,
		value_2_29 = 0,
		value_2_30 = 0,
		value_2_31 = 0,
		value_2_32 = 0,
		value_3_0 = 1,
		value_3_1 = -1,
		value_3_2 = 1,
		value_3_3 = -1,
		value_3_4 = 1,
		value_3_5 = -1,
		value_3_6 = 1,
		value_3_7 = -1,
		value_3_8 = 1,
		value_3_9 = -1,
		value_3_10 = 1,
		value_3_11 = -1,
		value_3_12 = 1,
		value_3_13 = -1,
		value_3_14 = 1,
		value_3_15 = -1,
		value_3_16 = 0,
		value_3_17 = 0,
		value_3_18 = 0,
		value_3_19 = 0,
		value_3_20 = 0,
		value_3_21 = 0,
		value_3_22 = 0,
		value_3_23 = 0,
		value_3_24 = 0,
		value_3_25 = 0,
		value_3_26 = 0,
		value_3_27 = 0,
		value_3_28 = 0,
		value_3_29 = 0,
		value_3_30 = 0,
		value_3_31 = 0,
		value_3_32 = 0,
		value_4_0 = 1,
		value_4_1 = -1,
		value_4_2 = -1,
		value_4_3 = 1,
		value_4_4 = 1,
		value_4_5 = -1,
		value_4_6 = -1,
		value_4_7 = 1,
		value_4_8 = 1,
		value_4_9 = -1,
		value_4_10 = -1,
		value_4_11 = 1,
		value_4_12 = 1,
		value_4_13 = -1,
		value_4_14 = -1,
		value_4_15 = 1,
		value_4_16 = 0,
		value_4_17 = 0,
		value_4_18 = 0,
		value_4_19 = 0,
		value_4_20 = 0,
		value_4_21 = 0,
		value_4_22 = 0,
		value_4_23 = 0,
		value_4_24 = 0,
		value_4_25 = 0,
		value_4_26 = 0,
		value_4_27 = 0,
		value_4_28 = 0,
		value_4_29 = 0,
		value_4_30 = 0,
		value_4_31 = 0,
		value_4_32 = 0,
		value_5_0 = 1,
		value_5_1 = -1,
		value_5_2 = -1,
		value_5_3 = 1,
		value_5_4 = 1,
		value_5_5 = -1,
		value_5_6 = -1,
		value_5_7 = 1,
		value_5_8 = 1,
		value_5_9 = -1,
		value_5_10 = -1,
		value_5_11 = 1,
		value_5_12 = 1,
		value_5_13 = -1,
		value_5_14 = -1,
		value_5_15 = 1,
		value_5_16 = 0,
		value_5_17 = 0,
		value_5_18 = 0,
		value_5_19 = 0,
		value_5_20 = 0,
		value_5_21 = 0,
		value_5_22 = 0,
		value_5_23 = 0,
		value_5_24 = 0,
		value_5_25 = 0,
		value_5_26 = 0,
		value_5_27 = 0,
		value_5_28 = 0,
		value_5_29 = 0,
		value_5_30 = 0,
		value_5_31 = 0,
		value_5_32 = 0,
		value_6_0 = 1,
		value_6_1 = 1,
		value_6_2 = -1,
		value_6_3 = -1,
		value_6_4 = 1,
		value_6_5 = 1,
		value_6_6 = -1,
		value_6_7 = -1,
		value_6_8 = 1,
		value_6_9 = 1,
		value_6_10 = -1,
		value_6_11 = -1,
		value_6_12 = 1,
		value_6_13 = 1,
		value_6_14 = -1,
		value_6_15 = -1,
		value_6_16 = 0,
		value_6_17 = 0,
		value_6_18 = 0,
		value_6_19 = 0,
		value_6_20 = 0,
		value_6_21 = 0,
		value_6_22 = 0,
		value_6_23 = 0,
		value_6_24 = 0,
		value_6_25 = 0,
		value_6_26 = 0,
		value_6_27 = 0,
		value_6_28 = 0,
		value_6_29 = 0,
		value_6_30 = 0,
		value_6_31 = 0,
		value_6_32 = 0,
		value_7_0 = 1,
		value_7_1 = 1,
		value_7_2 = -1,
		value_7_3 = -1,
		value_7_4 = 1,
		value_7_5 = 1,
		value_7_6 = -1,
		value_7_7 = -1,
		value_7_8 = 1,
		value_7_9 = 1,
		value_7_10 = -1,
		value_7_11 = -1,
		value_7_12 = 1,
		value_7_13 = 1,
		value_7_14 = -1,
		value_7_15 = -1,
		value_7_16 = 0,
		value_7_17 = 0,
		value_7_18 = 0,
		value_7_19 = 0,
		value_7_20 = 0,
		value_7_21 = 0,
		value_7_22 = 0,
		value_7_23 = 0,
		value_7_24 = 0,
		value_7_25 = 0,
		value_7_26 = 0,
		value_7_27 = 0,
		value_7_28 = 0,
		value_7_29 = 0,
		value_7_30 = 0,
		value_7_31 = 0,
		value_7_32 = 0,
		value_8_0 = 1,
		value_8_1 = -1,
		value_8_2 = -1,
		value_8_3 = 1,
		value_8_4 = -1,
		value_8_5 = 1,
		value_8_6 = 1,
		value_8_7 = -1,
		value_8_8 = -1,
		value_8_9 = 1,
		value_8_10 = 1,
		value_8_11 = -1,
		value_8_12 = 1,
		value_8_13 = -1,
		value_8_14 = -1,
		value_8_15 = 1,
		value_8_16 = 0,
		value_8_17 = 0,
		value_8_18 = 0,
		value_8_19 = 0,
		value_8_20 = 0,
		value_8_21 = 0,
		value_8_22 = 0,
		value_8_23 = 0,
		value_8_24 = 0,
		value_8_25 = 0,
		value_8_26 = 0,
		value_8_27 = 0,
		value_8_28 = 0,
		value_8_29 = 0,
		value_8_30 = 0,
		value_8_31 = 0,
		value_8_32 = 0,
		value_9_0 = 1,
		value_9_1 = -1,
		value_9_2 = -1,
		value_9_3 = 1,
		value_9_4 = -1,
		value_9_5 = 1,
		value_9_6 = 1,
		value_9_7 = -1,
		value_9_8 = -1,
		value_9_9 = 1,
		value_9_10 = 1,
		value_9_11 = -1,
		value_9_12 = 1,
		value_9_13 = -1,
		value_9_14 = -1,
		value_9_15 = 1,
		value_9_16 = 0,
		value_9_17 = 0,
		value_9_18 = 0,
		value_9_19 = 0,
		value_9_20 = 0,
		value_9_21 = 0,
		value_9_22 = 0,
		value_9_23 = 0,
		value_9_24 = 0,
		value_9_25 = 0,
		value_9_26 = 0,
		value_9_27 = 0,
		value_9_28 = 0,
		value_9_29 = 0,
		value_9_30 = 0,
		value_9_31 = 0,
		value_9_32 = 0,
		value_10_0 = 1,
		value_10_1 = 1,
		value_10_2 = -1,
		value_10_3 = -1,
		value_10_4 = -1,
		value_10_5 = -1,
		value_10_6 = 1,
		value_10_7 = 1,
		value_10_8 = -1,
		value_10_9 = -1,
		value_10_10 = 1,
		value_10_11 = 1,
		value_10_12 = 1,
		value_10_13 = 1,
		value_10_14 = -1,
		value_10_15 = -1,
		value_10_16 = 0,
		value_10_17 = 0,
		value_10_18 = 0,
		value_10_19 = 0,
		value_10_20 = 0,
		value_10_21 = 0,
		value_10_22 = 0,
		value_10_23 = 0,
		value_10_24 = 0,
		value_10_25 = 0,
		value_10_26 = 0,
		value_10_27 = 0,
		value_10_28 = 0,
		value_10_29 = 0,
		value_10_30 = 0,
		value_10_31 = 0,
		value_10_32 = 0,
		value_11_0 = 1,
		value_11_1 = 1,
		value_11_2 = -1,
		value_11_3 = -1,
		value_11_4 = -1,
		value_11_5 = -1,
		value_11_6 = 1,
		value_11_7 = 1,
		value_11_8 = -1,
		value_11_9 = -1,
		value_11_10 = 1,
		value_11_11 = 1,
		value_11_12 = 1,
		value_11_13 = 1,
		value_11_14 = -1,
		value_11_15 = -1,
		value_11_16 = 0,
		value_11_17 = 0,
		value_11_18 = 0,
		value_11_19 = 0,
		value_11_20 = 0,
		value_11_21 = 0,
		value_11_22 = 0,
		value_11_23 = 0,
		value_11_24 = 0,
		value_11_25 = 0,
		value_11_26 = 0,
		value_11_27 = 0,
		value_11_28 = 0,
		value_11_29 = 0,
		value_11_30 = 0,
		value_11_31 = 0,
		value_11_32 = 0,
		value_12_0 = 1,
		value_12_1 = 1,
		value_12_2 = 1,
		value_12_3 = 1,
		value_12_4 = -1,
		value_12_5 = -1,
		value_12_6 = -1,
		value_12_7 = -1,
		value_12_8 = -1,
		value_12_9 = -1,
		value_12_10 = -1,
		value_12_11 = -1,
		value_12_12 = 1,
		value_12_13 = 1,
		value_12_14 = 1,
		value_12_15 = 1,
		value_12_16 = 0,
		value_12_17 = 0,
		value_12_18 = 0,
		value_12_19 = 0,
		value_12_20 = 0,
		value_12_21 = 0,
		value_12_22 = 0,
		value_12_23 = 0,
		value_12_24 = 0,
		value_12_25 = 0,
		value_12_26 = 0,
		value_12_27 = 0,
		value_12_28 = 0,
		value_12_29 = 0,
		value_12_30 = 0,
		value_12_31 = 0,
		value_12_32 = 0,
		value_13_0 = 1,
		value_13_1 = 1,
		value_13_2 = 1,
		value_13_3 = 1,
		value_13_4 = -1,
		value_13_5 = -1,
		value_13_6 = -1,
		value_13_7 = -1,
		value_13_8 = -1,
		value_13_9 = -1,
		value_13_10 = -1,
		value_13_11 = -1,
		value_13_12 = 1,
		value_13_13 = 1,
		value_13_14 = 1,
		value_13_15 = 1,
		value_13_16 = 0,
		value_13_17 = 0,
		value_13_18 = 0,
		value_13_19 = 0,
		value_13_20 = 0,
		value_13_21 = 0,
		value_13_22 = 0,
		value_13_23 = 0,
		value_13_24 = 0,
		value_13_25 = 0,
		value_13_26 = 0,
		value_13_27 = 0,
		value_13_28 = 0,
		value_13_29 = 0,
		value_13_30 = 0,
		value_13_31 = 0,
		value_13_32 = 0,
		value_14_0 = 1,
		value_14_1 = -1,
		value_14_2 = 1,
		value_14_3 = -1,
		value_14_4 = -1,
		value_14_5 = 1,
		value_14_6 = -1,
		value_14_7 = 1,
		value_14_8 = -1,
		value_14_9 = 1,
		value_14_10 = -1,
		value_14_11 = 1,
		value_14_12 = 1,
		value_14_13 = -1,
		value_14_14 = 1,
		value_14_15 = -1,
		value_14_16 = 0,
		value_14_17 = 0,
		value_14_18 = 0,
		value_14_19 = 0,
		value_14_20 = 0,
		value_14_21 = 0,
		value_14_22 = 0,
		value_14_23 = 0,
		value_14_24 = 0,
		value_14_25 = 0,
		value_14_26 = 0,
		value_14_27 = 0,
		value_14_28 = 0,
		value_14_29 = 0,
		value_14_30 = 0,
		value_14_31 = 0,
		value_14_32 = 0,
		value_15_0 = 1,
		value_15_1 = -1,
		value_15_2 = 1,
		value_15_3 = -1,
		value_15_4 = -1,
		value_15_5 = 1,
		value_15_6 = -1,
		value_15_7 = 1,
		value_15_8 = -1,
		value_15_9 = 1,
		value_15_10 = -1,
		value_15_11 = 1,
		value_15_12 = 1,
		value_15_13 = -1,
		value_15_14 = 1,
		value_15_15 = -1,
		value_15_16 = 0,
		value_15_17 = 0,
		value_15_18 = 0,
		value_15_19 = 0,
		value_15_20 = 0,
		value_15_21 = 0,
		value_15_22 = 0,
		value_15_23 = 0,
		value_15_24 = 0,
		value_15_25 = 0,
		value_15_26 = 0,
		value_15_27 = 0,
		value_15_28 = 0,
		value_15_29 = 0,
		value_15_30 = 0,
		value_15_31 = 0,
		value_15_32 = 0,
		value_16_0 = 0,
		value_16_1 = 0,
		value_16_2 = 0,
		value_16_3 = 0,
		value_16_4 = 0,
		value_16_5 = 0,
		value_16_6 = 0,
		value_16_7 = 0,
		value_16_8 = 0,
		value_16_9 = 0,
		value_16_10 = 0,
		value_16_11 = 0,
		value_16_12 = 0,
		value_16_13 = 0,
		value_16_14 = 0,
		value_16_15 = 0,
		value_16_16 = 0,
		value_16_17 = 0,
		value_16_18 = 0,
		value_16_19 = 0,
		value_16_20 = 0,
		value_16_21 = 0,
		value_16_22 = 0,
		value_16_23 = 0,
		value_16_24 = 0,
		value_16_25 = 0,
		value_16_26 = 0,
		value_16_27 = 0,
		value_16_28 = 0,
		value_16_29 = 0,
		value_16_30 = 0,
		value_16_31 = 0,
		value_16_32 = 0,
		value_17_0 = 0,
		value_17_1 = 0,
		value_17_2 = 0,
		value_17_3 = 0,
		value_17_4 = 0,
		value_17_5 = 0,
		value_17_6 = 0,
		value_17_7 = 0,
		value_17_8 = 0,
		value_17_9 = 0,
		value_17_10 = 0,
		value_17_11 = 0,
		value_17_12 = 0,
		value_17_13 = 0,
		value_17_14 = 0,
		value_17_15 = 0,
		value_17_16 = 0,
		value_17_17 = 0,
		value_17_18 = 0,
		value_17_19 = 0,
		value_17_20 = 0,
		value_17_21 = 0,
		value_17_22 = 0,
		value_17_23 = 0,
		value_17_24 = 0,
		value_17_25 = 0,
		value_17_26 = 0,
		value_17_27 = 0,
		value_17_28 = 0,
		value_17_29 = 0,
		value_17_30 = 0,
		value_17_31 = 0,
		value_17_32 = 0,
		value_18_0 = 0,
		value_18_1 = 0,
		value_18_2 = 0,
		value_18_3 = 0,
		value_18_4 = 0,
		value_18_5 = 0,
		value_18_6 = 0,
		value_18_7 = 0,
		value_18_8 = 0,
		value_18_9 = 0,
		value_18_10 = 0,
		value_18_11 = 0,
		value_18_12 = 0,
		value_18_13 = 0,
		value_18_14 = 0,
		value_18_15 = 0,
		value_18_16 = 0,
		value_18_17 = 0,
		value_18_18 = 0,
		value_18_19 = 0,
		value_18_20 = 0,
		value_18_21 = 0,
		value_18_22 = 0,
		value_18_23 = 0,
		value_18_24 = 0,
		value_18_25 = 0,
		value_18_26 = 0,
		value_18_27 = 0,
		value_18_28 = 0,
		value_18_29 = 0,
		value_18_30 = 0,
		value_18_31 = 0,
		value_18_32 = 0,
		value_19_0 = 0,
		value_19_1 = 0,
		value_19_2 = 0,
		value_19_3 = 0,
		value_19_4 = 0,
		value_19_5 = 0,
		value_19_6 = 0,
		value_19_7 = 0,
		value_19_8 = 0,
		value_19_9 = 0,
		value_19_10 = 0,
		value_19_11 = 0,
		value_19_12 = 0,
		value_19_13 = 0,
		value_19_14 = 0,
		value_19_15 = 0,
		value_19_16 = 0,
		value_19_17 = 0,
		value_19_18 = 0,
		value_19_19 = 0,
		value_19_20 = 0,
		value_19_21 = 0,
		value_19_22 = 0,
		value_19_23 = 0,
		value_19_24 = 0,
		value_19_25 = 0,
		value_19_26 = 0,
		value_19_27 = 0,
		value_19_28 = 0,
		value_19_29 = 0,
		value_19_30 = 0,
		value_19_31 = 0,
		value_19_32 = 0,
		value_20_0 = 0,
		value_20_1 = 0,
		value_20_2 = 0,
		value_20_3 = 0,
		value_20_4 = 0,
		value_20_5 = 0,
		value_20_6 = 0,
		value_20_7 = 0,
		value_20_8 = 0,
		value_20_9 = 0,
		value_20_10 = 0,
		value_20_11 = 0,
		value_20_12 = 0,
		value_20_13 = 0,
		value_20_14 = 0,
		value_20_15 = 0,
		value_20_16 = 0,
		value_20_17 = 0,
		value_20_18 = 0,
		value_20_19 = 0,
		value_20_20 = 0,
		value_20_21 = 0,
		value_20_22 = 0,
		value_20_23 = 0,
		value_20_24 = 0,
		value_20_25 = 0,
		value_20_26 = 0,
		value_20_27 = 0,
		value_20_28 = 0,
		value_20_29 = 0,
		value_20_30 = 0,
		value_20_31 = 0,
		value_20_32 = 0,
		value_21_0 = 0,
		value_21_1 = 0,
		value_21_2 = 0,
		value_21_3 = 0,
		value_21_4 = 0,
		value_21_5 = 0,
		value_21_6 = 0,
		value_21_7 = 0,
		value_21_8 = 0,
		value_21_9 = 0,
		value_21_10 = 0,
		value_21_11 = 0,
		value_21_12 = 0,
		value_21_13 = 0,
		value_21_14 = 0,
		value_21_15 = 0,
		value_21_16 = 0,
		value_21_17 = 0,
		value_21_18 = 0,
		value_21_19 = 0,
		value_21_20 = 0,
		value_21_21 = 0,
		value_21_22 = 0,
		value_21_23 = 0,
		value_21_24 = 0,
		value_21_25 = 0,
		value_21_26 = 0,
		value_21_27 = 0,
		value_21_28 = 0,
		value_21_29 = 0,
		value_21_30 = 0,
		value_21_31 = 0,
		value_21_32 = 0,
		value_22_0 = 0,
		value_22_1 = 0,
		value_22_2 = 0,
		value_22_3 = 0,
		value_22_4 = 0,
		value_22_5 = 0,
		value_22_6 = 0,
		value_22_7 = 0,
		value_22_8 = 0,
		value_22_9 = 0,
		value_22_10 = 0,
		value_22_11 = 0,
		value_22_12 = 0,
		value_22_13 = 0,
		value_22_14 = 0,
		value_22_15 = 0,
		value_22_16 = 0,
		value_22_17 = 0,
		value_22_18 = 0,
		value_22_19 = 0,
		value_22_20 = 0,
		value_22_21 = 0,
		value_22_22 = 0,
		value_22_23 = 0,
		value_22_24 = 0,
		value_22_25 = 0,
		value_22_26 = 0,
		value_22_27 = 0,
		value_22_28 = 0,
		value_22_29 = 0,
		value_22_30 = 0,
		value_22_31 = 0,
		value_22_32 = 0,
		value_23_0 = 0,
		value_23_1 = 0,
		value_23_2 = 0,
		value_23_3 = 0,
		value_23_4 = 0,
		value_23_5 = 0,
		value_23_6 = 0,
		value_23_7 = 0,
		value_23_8 = 0,
		value_23_9 = 0,
		value_23_10 = 0,
		value_23_11 = 0,
		value_23_12 = 0,
		value_23_13 = 0,
		value_23_14 = 0,
		value_23_15 = 0,
		value_23_16 = 0,
		value_23_17 = 0,
		value_23_18 = 0,
		value_23_19 = 0,
		value_23_20 = 0,
		value_23_21 = 0,
		value_23_22 = 0,
		value_23_23 = 0,
		value_23_24 = 0,
		value_23_25 = 0,
		value_23_26 = 0,
		value_23_27 = 0,
		value_23_28 = 0,
		value_23_29 = 0,
		value_23_30 = 0,
		value_23_31 = 0,
		value_23_32 = 0,
		value_24_0 = 0,
		value_24_1 = 0,
		value_24_2 = 0,
		value_24_3 = 0,
		value_24_4 = 0,
		value_24_5 = 0,
		value_24_6 = 0,
		value_24_7 = 0,
		value_24_8 = 0,
		value_24_9 = 0,
		value_24_10 = 0,
		value_24_11 = 0,
		value_24_12 = 0,
		value_24_13 = 0,
		value_24_14 = 0,
		value_24_15 = 0,
		value_24_16 = 0,
		value_24_17 = 0,
		value_24_18 = 0,
		value_24_19 = 0,
		value_24_20 = 0,
		value_24_21 = 0,
		value_24_22 = 0,
		value_24_23 = 0,
		value_24_24 = 0,
		value_24_25 = 0,
		value_24_26 = 0,
		value_24_27 = 0,
		value_24_28 = 0,
		value_24_29 = 0,
		value_24_30 = 0,
		value_24_31 = 0,
		value_24_32 = 0,
		value_25_0 = 0,
		value_25_1 = 0,
		value_25_2 = 0,
		value_25_3 = 0,
		value_25_4 = 0,
		value_25_5 = 0,
		value_25_6 = 0,
		value_25_7 = 0,
		value_25_8 = 0,
		value_25_9 = 0,
		value_25_10 = 0,
		value_25_11 = 0,
		value_25_12 = 0,
		value_25_13 = 0,
		value_25_14 = 0,
		value_25_15 = 0,
		value_25_16 = 0,
		value_25_17 = 0,
		value_25_18 = 0,
		value_25_19 = 0,
		value_25_20 = 0,
		value_25_21 = 0,
		value_25_22 = 0,
		value_25_23 = 0,
		value_25_24 = 0,
		value_25_25 = 0,
		value_25_26 = 0,
		value_25_27 = 0,
		value_25_28 = 0,
		value_25_29 = 0,
		value_25_30 = 0,
		value_25_31 = 0,
		value_25_32 = 0,
		value_26_0 = 0,
		value_26_1 = 0,
		value_26_2 = 0,
		value_26_3 = 0,
		value_26_4 = 0,
		value_26_5 = 0,
		value_26_6 = 0,
		value_26_7 = 0,
		value_26_8 = 0,
		value_26_9 = 0,
		value_26_10 = 0,
		value_26_11 = 0,
		value_26_12 = 0,
		value_26_13 = 0,
		value_26_14 = 0,
		value_26_15 = 0,
		value_26_16 = 0,
		value_26_17 = 0,
		value_26_18 = 0,
		value_26_19 = 0,
		value_26_20 = 0,
		value_26_21 = 0,
		value_26_22 = 0,
		value_26_23 = 0,
		value_26_24 = 0,
		value_26_25 = 0,
		value_26_26 = 0,
		value_26_27 = 0,
		value_26_28 = 0,
		value_26_29 = 0,
		value_26_30 = 0,
		value_26_31 = 0,
		value_26_32 = 0,
		value_27_0 = 0,
		value_27_1 = 0,
		value_27_2 = 0,
		value_27_3 = 0,
		value_27_4 = 0,
		value_27_5 = 0,
		value_27_6 = 0,
		value_27_7 = 0,
		value_27_8 = 0,
		value_27_9 = 0,
		value_27_10 = 0,
		value_27_11 = 0,
		value_27_12 = 0,
		value_27_13 = 0,
		value_27_14 = 0,
		value_27_15 = 0,
		value_27_16 = 0,
		value_27_17 = 0,
		value_27_18 = 0,
		value_27_19 = 0,
		value_27_20 = 0,
		value_27_21 = 0,
		value_27_22 = 0,
		value_27_23 = 0,
		value_27_24 = 0,
		value_27_25 = 0,
		value_27_26 = 0,
		value_27_27 = 0,
		value_27_28 = 0,
		value_27_29 = 0,
		value_27_30 = 0,
		value_27_31 = 0,
		value_27_32 = 0,
		value_28_0 = 0,
		value_28_1 = 0,
		value_28_2 = 0,
		value_28_3 = 0,
		value_28_4 = 0,
		value_28_5 = 0,
		value_28_6 = 0,
		value_28_7 = 0,
		value_28_8 = 0,
		value_28_9 = 0,
		value_28_10 = 0,
		value_28_11 = 0,
		value_28_12 = 0,
		value_28_13 = 0,
		value_28_14 = 0,
		value_28_15 = 0,
		value_28_16 = 0,
		value_28_17 = 0,
		value_28_18 = 0,
		value_28_19 = 0,
		value_28_20 = 0,
		value_28_21 = 0,
		value_28_22 = 0,
		value_28_23 = 0,
		value_28_24 = 0,
		value_28_25 = 0,
		value_28_26 = 0,
		value_28_27 = 0,
		value_28_28 = 0,
		value_28_29 = 0,
		value_28_30 = 0,
		value_28_31 = 0,
		value_28_32 = 0,
		value_29_0 = 0,
		value_29_1 = 0,
		value_29_2 = 0,
		value_29_3 = 0,
		value_29_4 = 0,
		value_29_5 = 0,
		value_29_6 = 0,
		value_29_7 = 0,
		value_29_8 = 0,
		value_29_9 = 0,
		value_29_10 = 0,
		value_29_11 = 0,
		value_29_12 = 0,
		value_29_13 = 0,
		value_29_14 = 0,
		value_29_15 = 0,
		value_29_16 = 0,
		value_29_17 = 0,
		value_29_18 = 0,
		value_29_19 = 0,
		value_29_20 = 0,
		value_29_21 = 0,
		value_29_22 = 0,
		value_29_23 = 0,
		value_29_24 = 0,
		value_29_25 = 0,
		value_29_26 = 0,
		value_29_27 = 0,
		value_29_28 = 0,
		value_29_29 = 0,
		value_29_30 = 0,
		value_29_31 = 0,
		value_29_32 = 0,
		value_30_0 = 0,
		value_30_1 = 0,
		value_30_2 = 0,
		value_30_3 = 0,
		value_30_4 = 0,
		value_30_5 = 0,
		value_30_6 = 0,
		value_30_7 = 0,
		value_30_8 = 0,
		value_30_9 = 0,
		value_30_10 = 0,
		value_30_11 = 0,
		value_30_12 = 0,
		value_30_13 = 0,
		value_30_14 = 0,
		value_30_15 = 0,
		value_30_16 = 0,
		value_30_17 = 0,
		value_30_18 = 0,
		value_30_19 = 0,
		value_30_20 = 0,
		value_30_21 = 0,
		value_30_22 = 0,
		value_30_23 = 0,
		value_30_24 = 0,
		value_30_25 = 0,
		value_30_26 = 0,
		value_30_27 = 0,
		value_30_28 = 0,
		value_30_29 = 0,
		value_30_30 = 0,
		value_30_31 = 0,
		value_30_32 = 0,
		value_31_0 = 0,
		value_31_1 = 0,
		value_31_2 = 0,
		value_31_3 = 0,
		value_31_4 = 0,
		value_31_5 = 0,
		value_31_6 = 0,
		value_31_7 = 0,
		value_31_8 = 0,
		value_31_9 = 0,
		value_31_10 = 0,
		value_31_11 = 0,
		value_31_12 = 0,
		value_31_13 = 0,
		value_31_14 = 0,
		value_31_15 = 0,
		value_31_16 = 0,
		value_31_17 = 0,
		value_31_18 = 0,
		value_31_19 = 0,
		value_31_20 = 0,
		value_31_21 = 0,
		value_31_22 = 0,
		value_31_23 = 0,
		value_31_24 = 0,
		value_31_25 = 0,
		value_31_26 = 0,
		value_31_27 = 0,
		value_31_28 = 0,
		value_31_29 = 0,
		value_31_30 = 0,
		value_31_31 = 0,
		value_31_32 = 0,
		value_32_0 = 0,
		value_32_1 = 0,
		value_32_2 = 0,
		value_32_3 = 0,
		value_32_4 = 0,
		value_32_5 = 0,
		value_32_6 = 0,
		value_32_7 = 0,
		value_32_8 = 0,
		value_32_9 = 0,
		value_32_10 = 0,
		value_32_11 = 0,
		value_32_12 = 0,
		value_32_13 = 0,
		value_32_14 = 0,
		value_32_15 = 0,
		value_32_16 = 0,
		value_32_17 = 0,
		value_32_18 = 0,
		value_32_19 = 0,
		value_32_20 = 0,
		value_32_21 = 0,
		value_32_22 = 0,
		value_32_23 = 0,
		value_32_24 = 0,
		value_32_25 = 0,
		value_32_26 = 0,
		value_32_27 = 0,
		value_32_28 = 0,
		value_32_29 = 0,
		value_32_30 = 0,
		value_32_31 = 0,
		value_32_32 = 0,
	};
};


}}}}

#endif
