#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"           // Windows API の機能定義

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
    int val_array4[4] = {val1,val2,val3,val4};
    return calc_combinations(sum,val_array4,4);
}

#include <stdlib.h>
#include <stdio.h>

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
    int count = 0;
	
    for (int bits = 1; bits < (1 << array_size); bits++) 
    {
        int sum_ = 0;
        for (int i = 0; i < array_size; i++) 
        {
            int mask = 1 << i;
            if (bits & mask) 
            { 
                sum_ += val_array[i];
            }
        }

        if (sum_ == sum) 
        {
            count++;
        }
    }

    return count;
}
