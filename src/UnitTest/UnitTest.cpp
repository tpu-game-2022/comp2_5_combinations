#include "CppUnitTest.h"

#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestIsSame)
	{
	public:
		
		TEST_METHOD(TestIsSame0_0)
		{
			int val1 = 0;
			int val2 = 0;
			Assert::AreEqual(true, is_same(val1, val2));
		}

		TEST_METHOD(TestIsSame1_1)
		{
			int val1 = 1;
			int val2 = 1;
			Assert::AreEqual(true, is_same(val1, val2));
		}

		TEST_METHOD(TestIsNotSame0_1)
		{
			int val1 = 0;
			int val2 = 1;
			Assert::AreEqual(false, is_same(val1, val2));
		}
	};

	TEST_CLASS(UnitTestCalcCombinations3)
	{
	public:

		TEST_METHOD(TestCalcCombinations3_1111)
		{
			Assert::AreEqual(3, calc_combinations_3(1, 1, 1, 1));// 1 1 1
		}

		TEST_METHOD(TestCalcCombinations3_2111)
		{
			Assert::AreEqual(3, calc_combinations_3(2, 1, 1, 1));// 11 11 11
		}

		TEST_METHOD(TestCalcCombinations3_3111)
		{
			Assert::AreEqual(1, calc_combinations_3(3, 1, 1, 1));// 111
		}

		TEST_METHOD(TestCalcCombinations3_3123)
		{
			Assert::AreEqual(2, calc_combinations_3(3, 1, 2, 3));// 3, 12
		}
	};


	int UnitTestCalcCombinations4 (int sum,int val1,int val2 ,int val3,int val4)
	{
		int num = 0;

		if (sum == val1) num++;
		if (sum == val2) num++;
		if (sum == val3) num++;
		if (sum == val4) num++;

		if (sum == val1+val2) num++;
		if (sum == val1 + val3) num++;
		if (sum == val1 + val4) num++;
		if (sum == val2 + val3) num++;
		if (sum == val2 + val4) num++;
		if (sum == val3 + val4) num++;


		if (sum == val1 + val2+val3) num++;
		if (sum == val1 + val3 + val4) num++;
		if (sum == val1 + val2 + val4) num++;
		if (sum == val2 + val3+ val4) num++;

		if (sum == val1 + val2 + val3+val4) num++;
		
		return num;
	};

	void comb(int tmp_sum, int set_count, const int* val_array, int array_size, int sum, int* result)
	{
		if (set_count == array_size)
		{
			if (tmp_sum == sum)*result += 1;
			return;

		}

		if (tmp_sum > sum) return;

		comb(tmp_sum + val_array[set_count], set_count + 1, val_array, array_size, sum, result);
		comb(tmp_sum , set_count+1, val_array, array_size, sum, result);

	}

	int calc_combinations(int sum, const int* val_array, int array_size)
	{
		int result = 0;

		comb(0, 0, val_array, array_size, sum, &result);
		return result;
	}



}
