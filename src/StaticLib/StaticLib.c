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

	if (sum == val1) num++;
	if (sum == val2) num++;
	if (sum == val3) num++;
	if (sum == val1 + val2) num++;
	if (sum == val1 + val3) num++;
	if (sum == val2 + val3) num++;
	if (sum == val1 + val2 + val3) num++;

	return num;
}

// val1 から val4 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_4(int sum, int val1, int val2, int val3, int val4)
{
	int num = 0;

	if (sum == val1) num++;
	if (sum == val2) num++;
	if (sum == val3) num++;
	if (sum == val4) num++;

	if (sum == val1 + val2) num++;
	if (sum == val1 + val3) num++;
	if (sum == val1 + val4) num++;
	if (sum == val2 + val3) num++;
	if (sum == val2 + val4) num++;
	if (sum == val3 + val4) num++;

	if (sum == val1 + val2 + val3) num++;
	if (sum == val1 + val3 + val4) num++;
	if (sum == val1 + val2 + val4) num++;
	if (sum == val2 + val3 + val4) num++;

	if (sum == val1 + val2 + val3 + val4) num++;

	return num;
}

void comb(int tmp_sum, int set_count, const int* val_array, int array_size, int sum, int* result)
{
	if (set_count == array_size) //array_size回加算し終わったら
	{
		if (tmp_sum == sum) *result += 1;
		return;
	}

	if (tmp_sum > sum) return; //計算途中でsumを超えたら確定オーバーなので終了

	comb(tmp_sum + val_array[set_count], set_count + 1, val_array, array_size, sum, result);
	comb(tmp_sum, set_count + 1, val_array, array_size, sum, result);
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int result = 0;

	comb(0, 0, val_array, array_size, sum, &result);

	return result;
}





