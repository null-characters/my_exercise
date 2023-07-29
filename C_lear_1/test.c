#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"


struct _drv_ drv;

/// @brief 测试结构体内变量是随机值还是0
/// @param  
/// @return 全局变量的值默认是0，分配在数据段；局部变量是随机的，分配在栈区
int main(void)
{
	struct _drv_ d;

	printf_s("%d\n", drv.i);
	printf_s("%.8f\n", drv.f);
	printf_s("%.16lf\n", drv.d);
	printf_s("%d\n", drv.c);
	printf_s("%d\n", drv.s.j);

	printf_s("%d\n", d.i);
	printf_s("%.8f\n", d.f);
	printf_s("%.16lf\n", d.d);
	printf_s("%d\n", d.c);
	printf_s("%d\n", d.s.j);
	return 1;
}


