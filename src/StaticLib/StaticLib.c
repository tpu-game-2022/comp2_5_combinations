#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
	int num=0;
	int combi[15]={val1, val2, val3, val4, 
	val1+val2, val1+val3, val1+val4, val2+val3, val2+val4, val3+val4,
	val1+val2+val3, val1+val2+val4, val1+val3+val4, val2+val3+val4,
	val1+val2+val3+val4};

	for(int i=0;i<15;i++){
		if(combi[i]==sum){num++;}
	}
	return num;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int flag = 0;
	for (size_t i = 0; i < array_size; i++) {
		if (val_array[i] != 1) { flag = 1; break; }
	}
	if (flag == 0) {
		float dat=1;
		for (int i = 0; i < sum; i++) {
			dat *= (array_size - i);
			dat /= (i + 1);

		}
		int out = dat;
		return out;

	}

	int num=0;
	int* combi=(int*)malloc(sizeof(int)*(array_size));
	if (combi) {
		unsigned long int cbt=0;
		for(int ary_num=0; ary_num <array_size; ary_num++){

			if (val_array[ary_num] > sum) { continue; }
			combi = (int*)realloc(combi, sizeof(int) * (cbt +1)*2);
			combi[cbt]=val_array[ary_num];
			if(combi[cbt]==sum){num++;}
			cbt++;

			unsigned long int s=cbt;
			for(int i=0;i<s-1;i++){
				if (combi[i] > sum) { continue; }
				combi[cbt]=val_array[ary_num]+combi[i];
				if(combi[cbt]==sum){num++;}
				cbt++;
			}
		}
		free(combi);
		return num;
	}
	

	return 0;
	
}
