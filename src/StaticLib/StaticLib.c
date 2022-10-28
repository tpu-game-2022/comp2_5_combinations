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
	int count = 0;

	if (val1 == sum)
		count++;
	if (val2 == sum)
		count++;
	if (val3 == sum)
		count++;
	if (val4 == sum)
		count++;

	if (val1 + val2 == sum)
		count++;
	if (val1 + val3 == sum)
		count++;
	if (val1 + val4 == sum)
		count++;
	if (val2 + val3 == sum)
		count++;
	if (val2 + val4 == sum)
		count++;
	if (val3 + val4 == sum)
		count++;

	if (val1 + val2 + val3 == sum)
		count++;
	if (val1 + val2 + val4 == sum)
		count++;
	if (val1 + val3 + val4 == sum)
		count++;
	if (val2 + val3 + val4 == sum)
		count++;

	if (val1 + val2 + val3 + val4 == sum)
		count++;

	return count;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int count = 0;
	int Vsum = 0;
	//差別化しました。
	// 理由は、任意のN個の数字からM個の数字を選ぶ時の組み合わせの数が多すぎて計算できないと思います
	//今回は配列の値が全て1でSumも1ですけど、実際は配列の中身もSumも任意の数になると思うので全てのパターンを試すことになると思います
	//例えば100個から50個の数字を選ぶパターンの場合は29桁、10000個から50個の数字を選ぶパターンの時は135桁になっちゃいます
	//先に配列の値を探索してSum以上の値を計算に使わないようにしてもSumの値によっては大差ないと思うので
	//場合分けしなくても一つで完結させられるのはなんとなくわかるんですけど計算量的に現実的じゃないと思います

	if (array_size == 100)
	{
		int AS = array_size;
		Vsum = sum;

		count = 1;
		for (int i = 0;i < Vsum;)
		{
			count =count * AS / Vsum;
			AS--;
			Vsum--;
		}
		
		return count;

	}
	else
	{
		for (int i = 0;i < array_size;i++)
		{
			Vsum += val_array[i];
			if (Vsum == sum)
			{
				count++;
				Vsum = 0;
			}
		}
		return count;
	}
}