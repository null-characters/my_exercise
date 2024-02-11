#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARR_LEN_DEF 10000

int arr_test[] = {2, 7, 1, 9, 6};

/// @brief 选择排序方法
/// @param arr 输入的数组
/// @param Size 输入数组的长度
/// @param arr_return 输出数组
void select_sortint_func(int Size, int *arr_return)
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
/// @brief 生成随机数数组, 数组长度是len
/// @param arr_return 
/// @param len 
int generate_rand_nums(int* arr_return, int len)
{
    time_t t;
    srand((unsigned) time(&t)); // 初始化随机数生成器
    for (int i = 0; i < len; i++)
    {
        arr_return[i] = ((rand() - rand()));
        // printf_s("%d\t", arr_return[i]);
    }
    // printf_s("\n");
}

void bubble_sort_func(int Size, int *arr_return)
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = i + 1; j < Size; j++)
        {
            if (arr_return[i] > arr_return[j])
            {
                int temp;
                temp = arr_return[i];
                arr_return[i] = arr_return[j];
                arr_return[j] = temp;
            }
        }
    }
}

/// @brief 对数器,对比前后数组数据是否一致
/// @param  新算法的数据集
/// @param  简单实现的算法数据集
/// @return 1:错误  0:正确
int comp_date(int* dest, int* src, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (dest[i] != src[i])
        {
            return 1;
        }
    }

    return 0;    
}

int main(void)
{
    // 现在用选择排序的方法来对数组进行排序
    int arr_rand[ARR_LEN_DEF];
    int arr_rand_cpy[ARR_LEN_DEF];

    generate_rand_nums(arr_rand, ARR_LEN_DEF);

    memcpy_s(arr_rand_cpy, sizeof(arr_rand_cpy), arr_rand , sizeof(arr_rand));
    
    select_sortint_func(ARR_LEN_DEF, arr_rand);
    
    bubble_sort_func(ARR_LEN_DEF, arr_rand_cpy); // 冒泡排序

    // 实现对数器
    if (comp_date(arr_rand, arr_rand_cpy, ARR_LEN_DEF))
    {
        printf_s("It's wrong!");
    }
    else
    {
        printf_s("It's right!");
    }

    printf_s("\n");
}
