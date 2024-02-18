#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 题目一, 验证异或的用法 验证一个数组中有一种数是奇数个数,找出这个数
// 题目二, 是验证一个数组中有两种数是奇数个数,找出这两个数

// 知识点1: 做好边界处理, 整数需检测INT_MIN 和 INT_MAX这两个数, 其他数据类型类推
// 知识点2: 寻找最右侧的1的两种方法: (eor & (~eor + 1))   和    (eor : eor & (-eor))
// 知识点3: 使用time.h的函数来测量运行时间

int arr_test[] = {0, 0, 1, 6, 6, 8, 1, 8, 8, 0, 0, 9};
int arr_test_return[] = {};
// int arr_test[] = {};
// 定义一个函数，参数是一个整型数组和它的长度
void xor_array_4_one(int arr[], int len)
{
    int i = 0; // 循环用来异或的数
    if (len == 0)
    {
        printf_s("no charter\n");
        return; // 如果数组为空，直接返回
    }

    if (len == 1)
    {
        printf_s("%d\n", arr[0]);
        return; // 如果数组只有一个元素，直接返回
    }

    for (int cur_i = 0; cur_i < len; cur_i++)
    {
        i ^= arr[cur_i]; // 对数组中的每个元素进行异或操作
    }

    printf_s("%d\n", i); // 打印异或的结果
}

void xor_array_4_two(int arr[], int len)
{
    int eor = 0; // 循环用来异或的数
    if (len == 0)
    {
        printf_s("no charter\n");
        return; // 如果数组为空，直接返回
    }

    if (len == 1)
    {
        printf_s("%d\n", arr[0]);
        return; // 如果数组只有一个元素，直接返回
    }

    for (int cur_i = 0; cur_i < len; cur_i++)
    {
        eor ^= arr[cur_i]; // 对数组中的每个元素进行异或操作
    }

    int rightOne = eor & (~eor + 1); // 找出eor中最右侧一个1的位置
    // 如果eor = 00001100,   ~eor = 11110011  ~eor+1 = 11110100   11110100 & 00001100 = 00001000 

    int onlyOne = 0; // 存储其中一个奇数个数的数
    int onlyTwo = 0; // 存储另外一个奇数个数的数
    for (int cur_i = 0; cur_i < len; cur_i++)
    {
        if ((arr[cur_i] & rightOne) != 0) {
            // 因为其已经保证了a和b在这个位上的不同, 所以只会在a和b之间选择出一个
            onlyOne ^= arr[cur_i];
        }
    }
    
    onlyTwo = eor ^ onlyOne;
}

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (numsSize == 0)
    {
        return result;
    }

    if (numsSize == 1)
    {
        result[0] = nums[0];
        result[1] = 0;
        return result;
    }

    int eor = 0;
    for (int cur_i = 0; cur_i < numsSize; cur_i++)
    {
        eor ^= nums[cur_i];
    }

    // 以下两句都是寻找最右的1，如果eor是最小边界值，第一句代码会返回 INT_MIN，而第二句代码会返回 0。
    int right_one = (eor == INT_MIN ? eor : (eor & (~eor + 1)));
    // int right_one = (eor == INT_MIN ? eor : eor & (-eor)); 

    int eor_0 = 0;
    for (int cur_i = 0; cur_i < numsSize; cur_i++)
    {
        if (right_one & nums[cur_i])
        {   // 这里把数分成了两组，一组是右侧第一个1位置上有1的数， 另一组是该位置上没有1的数
            // 如果该位置上有1，则将那个数异或进来，轮询完后会消掉所有偶数项，留下的就是分组位置有1的那个数
            eor_0 ^= nums[cur_i]; 
        }
    }
    result[0] = eor_0;
    result[1] = eor_0 ^ eor;
    return result;
}

int main(void)
{
    struct timeval start, end; // 定义两个变量，用来记录开始和结束的时间
    mingw_gettimeofday(&start, NULL); // 记录程序开始的时间

    int len = sizeof(arr_test) / sizeof(arr_test[0]);
    // xor_array_4_one(arr_test, len); // 调用函数

    singleNumber(arr_test, len, arr_test_return);
    printf("%d, %d\n", arr_test_return[0], arr_test_return[1]); // 输出结果

    mingw_gettimeofday(&end, NULL);                                                    // 记录程序结束的时间
    long time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); // 计算程序的运行时间
    printf("\n程序运行了%ld微秒\n", time); // 输出结果
    return 0;
}
