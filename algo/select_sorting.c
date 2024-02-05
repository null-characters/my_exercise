#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int arr_test[] = {2, 7, 1, 9, 6};

/// @brief 选择排序方法
/// @param arr 输入的数组
/// @param Size 输入数组的长度
/// @param arr_return 输出数组
void select_sortint_func(int *arr, int Size, int *arr_return)
{
    for (int i = 0; i < Size; i++)
    {
        // for (int j = i; j > 0; j--)
        // {
        //     if (arr_return[j] >= arr_return[j - 1])
        //     {
        //         break;
        //     }
        // 此处如果条件不成立直接结束循环, 比加break条件好
        for (int j = i; j > 0 && arr_return[j] < arr_return[j - 1]; j--)
        {
            // 如果前面的比后面大，就交换两个的位置 - 从小到大排序
            int temp;
            temp = arr_return[j];
            arr_return[j] = arr_return[j - 1];
            arr_return[j - 1] = temp;
        }
    }
}

int main(void)
{
    // 现在用选择排序的方法来对数组进行排序
    int len = sizeof(arr_test) / sizeof(arr_test[0]);

    int *result = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
    {
        printf_s("%d\t", arr_test[i]);
    }
    printf_s("\n");

    memcpy(result, arr_test, len * sizeof (int));
    select_sortint_func(arr_test, len, result);

    for (int i = 0; i < len; i++)
    {
        printf_s("%d\t", result[i]);
    }
    printf_s("\n");
}
