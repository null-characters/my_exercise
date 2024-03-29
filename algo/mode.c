#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 本文档为模板文档. 如需创建新的文件,以此文档做为模板

// 宏定义
#define ARR_LEN_DEF 7
// 全局数据定义

// 函数声明
int generate_rand_nums(int *arr_return, int len); // 生成随机数据
int comp_date(int *dest, int *src, int len);      // 对比数据
void printf_all_data(int *dat, int len);          // 打印数组

/// @brief 生成数
int generate_rand_nums(int *arr_return, int len)
{
    time_t t;
    srand((unsigned)time(&t)); // 初始化随机数生成器
    for (int i = 0; i < len; i++)
    {
        arr_return[i] = ((rand() - rand()));
    }
}

/// @brief 对数器,对比前后数组数据是否一致
/// @param  新算法的数据集
/// @param  简单实现的算法数据集
/// @return 1:错误  0:正确
int comp_date(int *dest, int *src, int len)
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

/// @brief 打印数组的所有数据
/// @param dest
/// @param len
void printf_all_data(int *dat, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf_s("%d\t", dat[i]);
    }
}

/// @brief 方法一: 需要验证的实现
void func1(void)
{
}

/// @brief 方法二: 最易实现
void func2(void)
{
}

int main(void)
{
    struct timeval start, end;        // 定义两个变量，用来记录开始和结束的时间
    mingw_gettimeofday(&start, NULL); // 记录程序开始的时间

    // 现在用选择排序的方法来对数组进行排序
    int arr_rand[ARR_LEN_DEF];
    int arr_rand_cpy[ARR_LEN_DEF];

    generate_rand_nums(arr_rand, ARR_LEN_DEF);

    memcpy_s(arr_rand_cpy, sizeof(arr_rand_cpy), arr_rand, sizeof(arr_rand));

    func1();

    func2();

    // 实现对数器
    if (comp_date(arr_rand, arr_rand_cpy, ARR_LEN_DEF))
    {
        printf_s("It's wrong!");
    }
    else
    {
        printf_s("It's right!");
    }

    mingw_gettimeofday(&end, NULL);                                                    // 记录程序结束的时间
    long time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); // 计算程序的运行时间
    printf("\n程序运行了%ld微秒\n", time); // 输出结果

    printf_s("\n");
}
