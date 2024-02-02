#include <stdio.h>

/// @brief 使用异或的方法交换两个值
/// @param a
/// @param b
void swap(int* a, int* b)
{
    // 根据异或满足交换律和结合律 -- 交换律: a ^ b = b ^ a  ; 结合律: a ^ b ^ c = a ^ (b ^ c)
    *a = *a ^ *b; // a = a ^ b, b = b;
    *b = *a ^ *b; // b = a ^ b ^ b = a ; a = a ^ b;
    *a = *a ^ *b; // a = a ^ b ^ a = b;
}

void swap_temp(int* a, int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void main(void)
{
    int a, b;
    int *pt_a, *pt_b;
    pt_a = &a;
    pt_b = &b;
    a = 15;
    b = 23;
    printf_s("a=%d, b=%d\n", a, b);
    // swap(pt_a, pt_b);
    swap_temp(pt_a, pt_b);
    printf_s("a=%d, b=%d\n", a, b);

    // printf_s("hello, ");
    getchar();
}
