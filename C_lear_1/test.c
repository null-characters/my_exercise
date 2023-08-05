#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"

int main(void)
{
    // 定义一个数组，元素个数为50
    float arr[50];

    // 定义一个变量，用于存储数组元素的值
    float value = 0.0054;

    // 定义一个变量，用于存储数组元素之间的差值
    float diff = (0.0074 - 0.0054) / 49;

    // 用循环给数组元素赋值
    for (int i = 0; i < 50; i++)
    {
        // 将value赋值给当前元素
        arr[i] = value;

        // 将value加上diff，得到下一个元素的值
        value = value + diff;
    }

	// 用循环打印数组元素
	for (int i = 0; i < 50; i++)
	{
		printf("%.5f,  ", arr[i]);
		if (i % 10 == 0 )
		{
			printf("\n");
		}
	}

	return 0;
}
