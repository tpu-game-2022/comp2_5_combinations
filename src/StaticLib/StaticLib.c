#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdbool.h>

#include "../include/lib_func.h"

// 2つの数字が等しいですか？
bool is_same(int val1, int val2)
{
	return val1 == val2;
}

// val1 から val3 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_3(int sum, int val1, int val2, int val3)
{
	int num = 0;
	
	if(sum == val1) num++;
	if(sum == val2) num++;
	if(sum == val3) num++;
	if(sum == val1 + val2) num++;
	if(sum == val1 + val3) num++;
	if(sum == val2 + val3) num++;
	if(sum == val1 + val2 + val3) num++;
	
	return num;
}

// val1 から val4 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_4(int sum, int val1, int val2, int val3, int val4)
{
	int num = 0;
	if (sum == val1)num++;
	if (sum == val2)num++;
	if (sum == val3)num++;
	if (sum == val4)num++;
	if (sum == val1+val2)num++;
	if (sum == val1+val3)num++;
	if (sum == val1+val4)num++;
	if (sum == val2+val3)num++;
	if (sum == val2+val4)num++;
	if (sum == val3+val4)num++;
	if (sum == val1+val2+val3)num++;
	if (sum == val1+val2+val4)num++;
	if (sum == val1+val3+val4)num++;
	if (sum == val2+val3+val4)num++;
	if (sum == val1+val2+val3+val4)num++;

	return num;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int num = 1;
	int num2 = 0;
	int a=sum;
	//for (int i = 0; i < array_size; i++)
	//{
		//if (sum == val_array[i])
		//	num++;
	//}
	for (int i = 0; i < array_size; i++)
	{
		num2 = num2 + val_array[i];
	}
	if (array_size == 1) {
		if (sum == val_array[0])
			num = 1;
		else
			num = 0;
	}
	else if (sum == num2)
	{
		num = 1;
	}

	else {
		for (int i = 0; i < sum; i++)
		{
			num = num * (array_size - i);
			num = num / a;
			a--;
		}

	}
	return num;
}
