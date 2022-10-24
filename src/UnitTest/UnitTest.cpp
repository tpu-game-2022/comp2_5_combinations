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


	TEST_CLASS(UnitTestCalcCombinations4)
	{
	public:

		TEST_METHOD(TestCalcCombinations4_11111)
		{
			Assert::AreEqual(4, calc_combinations_4(1, 1, 1, 1, 1));// 1 1 1 1
		}

		TEST_METHOD(TestCalcCombinations4_21111)
		{
			Assert::AreEqual(6, calc_combinations_4(2, 1, 1, 1, 1));// 11*6
		}

		TEST_METHOD(TestCalcCombinations4_31111)
		{
			Assert::AreEqual(4, calc_combinations_4(3, 1, 1, 1, 1));// 111*4
		}

		TEST_METHOD(TestCalcCombinations4_41111)
		{
			Assert::AreEqual(1, calc_combinations_4(4, 1, 1, 1, 1));// 1111
		}

		TEST_METHOD(TestCalcCombinations4_3123)
		{
			Assert::AreEqual(2, calc_combinations_4(4, 1, 2, 3, 4));// 4 13
		}

	};

	TEST_CLASS(UnitTestCalcCombinations)
	{
	public:

		TEST_METHOD(TestCalcCombinations_1)
		{
			int ar[1] = { 1 };
			Assert::AreEqual(1, calc_combinations(1, ar, 1));// 1
		}

		TEST_METHOD(TestCalcCombinations_2)
		{
			int ar[1] = { 2 };
			Assert::AreEqual(1, calc_combinations(2, ar, 1));// 1
		}

		TEST_METHOD(TestCalcCombinations_30_30)
		{
			const int num = 30;
			int ar[num];
			for (int i = 0; i < num; i++) { ar[i] = 1; }
			Assert::AreEqual(1, calc_combinations(num, ar, num));//1
		}

		TEST_METHOD(TestCalcCombinations_100_5)
		{
			const int num = 100;
			int ar[num];
			for (int i = 0; i < num; i++) { ar[i] = 1; }
			Assert::AreEqual(100 * 99 * 98 * 97 / 5 / 4 / 3 / 2 * 96, calc_combinations(5, ar, num));//75,287,520
		}

		TEST_METHOD(TestCalcCombinations_10000_1)
		{
			const int num = 10000;
			int* ar = (int*)malloc(num * sizeof(int));
			if (ar) {
				for (int i = 0; i < num; i++) { ar[i] = 1; }
				Assert::AreEqual(num, calc_combinations(1, ar, num));//10000
				free(ar);
			}
		}
	};
}
