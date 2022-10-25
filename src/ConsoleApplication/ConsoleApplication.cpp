
#include "Windows.h"                    // Windows API の機能定義

#include <stdio.h>   // printf
#include <stdlib.h>   // malloc
#include <stdbool.h> // bool
#include <malloc.h>
#include "../include/lib_func.h"


int main()
{
	int val1, val2, val3, val4, sum;
	int* val_array, array_size;

	val1 = 1;
	val2 = 2;
	printf("%dと%dは%s\n", val1, val2, is_same(val1, val2) ? "等しい" : "等しくない");

	val1 = 0;
	val2 = 0;
	printf("%dと%dは%s\n", val1, val2, is_same(val1, val2) ? "等しい" : "等しくない");

	sum = 2;
	val1 = 1;
	val2 = 1;
	val3 = 1;
	printf("%dと%dと%dの任意の数の和が%dになる組み合わせは%d通りです\n", val1, val2, val3, sum, calc_combinations_3(sum, val1, val2, val3));

	sum = 3;
	val1 = 1;
	val2 = 2;
	val3 = 3;
	printf("%dと%dと%dの任意の数の和が%dになる組み合わせは%d通りです\n", val1, val2, val3, sum, calc_combinations_3(sum, val1, val2, val3));

	sum = 2;
	val1 = 1;
	val2 = 1;
	val3 = 1;
	val4 = 1;
	printf("%dと%dと%dと%dの任意の数の和が%dになる組み合わせは%d通りです\n", val1, val2, val3, val4, sum, calc_combinations_4(sum, val1, val2, val3, val4));

	sum = 4;
	val1 = 1;
	val2 = 2;
	val3 = 3;
	val4 = 4;
	printf("%dと%dと%dと%dの任意の数の和が%dになる組み合わせは%d通りです\n", val1, val2, val3, val4, sum, calc_combinations_4(sum, val1, val2, val3, val4));

	sum = 10;
	array_size = 100000;
	val_array = (int*)malloc(array_size * sizeof(int));
	if (val_array) {// nullチェック
		for (int i = 0; i < array_size; i++) {
			val_array[i] = 1;
		}
		// 表示
		for (int i = 0; i < array_size; i++) {
			printf("%d", val_array[i]);
			if (i != array_size - 1) {
				printf("と");
			}
		}
		printf("の任意の数の和が%dになる組み合わせは%d通りです\n", sum, calc_combinations(sum, val_array, array_size));

		free(val_array);
	}
}
