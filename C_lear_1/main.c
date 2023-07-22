#include <stdio.h>

#define _US_TEST_
// #define _S_TEST_

#ifdef _S_TEST_
#include <time.h>
#endif
#ifdef _US_TEST_
#include <sys/time.h> // 微秒的计时
#endif

// #define _FUNC_1 // N^3和N^2解法
// #define _FUNC_2 // 分治算法
// #define _FUNC_2_SEARCH_ // 二分查找
#define _SEA_USE_ERFEN_ // 如果没有定义，则执行for循环

#define _FUNC_LIST_ // 链表
 
int ar[7] = {7, -2, 5, 3, -8, 6};

#define MAX3(a,b,c) ((a)>(b)?((a)>(c)?(a):(c)):((b)>(c))?(b):(c))

static int Maxsum(const int ar[], int left, int right)
{
    int leftmaxsum, rightmaxsum = 0; // 用于存储两边的最大和
    int maxleftboardsum, maxrightboardsum = 0; // 用于存储从中间到两边的最大和
    int leftboardsum, rightboardsum = 0; // 用于临时存储两边的最大和
    int center, i = 0;

    if (left == right)
    { // base case
        if (ar[left] > 0)
        {
            return ar[left];
        }else{
            return 0;
        }
    }

    center = (left + right) / 2;
    leftmaxsum = Maxsum(ar, left, center);
    rightmaxsum = Maxsum(ar, center + 1, right);

    maxleftboardsum = 0;
    leftboardsum = 0;
    for (i = center; i >= left; i--)
    { // 计算从中间向左边的最大值
        leftboardsum += ar[i];
        if (leftboardsum > maxleftboardsum)
        {
            maxleftboardsum = leftboardsum; 
        }
    }

    maxrightboardsum = 0;
    rightboardsum = 0;
    for (i = center; i >= right; i--)
    { // 计算从中间向右边的最大值
        rightboardsum += ar[i];
        if (rightboardsum > maxrightboardsum)
        {
            maxrightboardsum = rightboardsum; 
        }
    }

    int max = MAX3(leftmaxsum, rightmaxsum, maxleftboardsum + maxrightboardsum);

    printf("now maxsum = %d\n", max);
    
    return max;
//    return MAX3(leftmaxsum, rightmaxsum, maxleftboardsum + maxrightboardsum);
}

#define N_NUM 300000
long int search_num(const long int sea_a[], long int x, long int N)
{
#ifdef _SEA_USE_ERFEN_
    int low, high, mid;
    low = 0;
    high = N - 1;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (x > sea_a[mid])
            low = mid + 1;
        else if (x < sea_a[mid])
            high = mid - 1;
        else
            return mid;
    }

#else
    for (long int i = 0; i < N_NUM; i++)
    {
        if (sea_a[i] == x)
        {
            return i;
        }
    }
#endif

    return -1; // 没找到
}

int main(void)
{
    int N = 7;
    int thissum, maxsum = 0;
#ifdef _FUNC_2_SEARCH_
    long int sea_a[N_NUM];
    for (long int i = 0; i < N_NUM; i++)
    {
        sea_a[i] = i + 1;
    }
#endif

#ifdef _US_TEST_
    struct timeval start, end; // 定义两个timeval结构体
    gettimeofday(&start, NULL); // 获取开始时间
#endif
#ifdef _S_TEST_
  clock_t start = clock (); // 开始计时
#endif
#ifdef _FUNC_1
    for (int i = 0; i < N; i++)
    { // 一共要计算N轮
////////////////////////////////////////////////////////////////
        thissum = 0;
        for (int j = i; j < N; j++)
        { // 在当前轮次里需要计算j-i次
            thissum += ar[j];

            if (thissum > maxsum)
                maxsum = thissum;
            printf(" now maxsum = %d\n", maxsum);
       }
////////////////////////////////////////////////////////////////
       // 方法一
        // for (int j = i; j < N; j++)
        // { // 在当前轮次里需要计算j-i次
        //     thissum = 0;

        //     for (int k = i; k < j; k++)
        //     {
        //         thissum +=ar[k];
        //     }
            
        //     if (thissum > maxsum)
        //         maxsum = thissum;
        //     printf(" now maxsum = %d\n", maxsum);
        // }
////////////////////////////////////////////////////////////////

    }

#endif

#ifdef _FUNC_2
    maxsum = Maxsum(ar, 0, 6);
#endif

#ifdef _FUNC_2_SEARCH_
    
    printf("find a add = %ld\n", (search_num(sea_a, 235232, N_NUM)));
#endif


#ifdef _US_TEST_
    gettimeofday(&end, NULL); // 获取结束时间
    long seconds = end.tv_sec - start.tv_sec; // 计算秒数差
    long micros = (seconds * 1000000) + end.tv_usec - start.tv_usec; // 计算微秒数差
    printf("Time elpased is %ld seconds and %ld micros\n", seconds, micros); // 打印结果
#endif
#ifdef _S_TEST_
    clock_t end = clock (); // 结束计时
    double seconds = (double) (end - start)/* / CLOCKS_PER_SEC*/; // 计算秒数
    printf("Time taken: %.6f\n", seconds); // 打印毫秒结果
#endif
    printf("maxsum = %d\n", maxsum);

    getchar();
}
