#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "polynomial.h"

// #define _USE_ARR_SAVE_POLY_
#ifdef _USE_ARR_SAVE_POLY_

#define MaxDeoree 100

typedef struct 
{
	int coefarr[MaxDeoree + 1]; // 存储各次幂的值
	int HighPower; // 存储最高次幂
}* polynomial;

void zeroPolynomial(polynomial P)
{
	for (int i = 0; i <= MaxDeoree; i++)
	{
		P->coefarr[i] = 0;
	}
	P->HighPower = 0;
}

void AddPolynomial(const polynomial P1, const polynomial P2, polynomial sum)
{
	zeroPolynomial(sum);
	for (int i = 0; i <= ((P1->HighPower > P2->HighPower) ? P1->HighPower : P2->HighPower); i++)
	{
		printf_s("%d = %d\t", i, sum->coefarr[i] = P1->coefarr[i] + P2->coefarr[i]);
	}
}

void MultPolynomial(const polynomial P1, const polynomial P2, polynomial mult)
{
	zeroPolynomial(mult);

	if ((P1->HighPower + P2->HighPower) > MaxDeoree)
	{
		printf_s("exceeded arr size!\n");
		return ;
	}

	for (int i = 0; i <= P1->HighPower; i++)
	{
		for (int j = 0; j < + P2->HighPower; j++)
		{
			mult->coefarr[i + j] += P1->coefarr[i] * P2->coefarr[j];
		}
	}
	for (int z = 0; z < (P1->HighPower + P2->HighPower); z++)
	{
		printf_s("%d = %d\t", z, mult->coefarr[z]);
	}
}

#else
// 链表形式

// 定义链表多项式的三种方式 
/////////////////////////////////////////////
// 第一种方式不好理解
struct polynomial;
typedef struct polynomial *PtrNode;
typedef struct polynomial
{
	int coefarr;  // 系数
	int exponnet; // 指数
	PtrNode Next;
} PolyNode; // 结构体类型的名字
///////////////////////////////////////////////
// 第二种方式struct Node是未完全定义的类型，只能用来声明指针变量
typedef struct Node *PtrNode;
struct Node
{
	int coefarr;  // 系数
	int exponnet; // 指数
	PtrNode Next;
};
typedef PtrNode poly;
///////////////////////////////////////////////
// 第三种方式有更好可读性和扩展性，建议第三种
typedef struct polynomial
{
	int coefarr; // 系数 
	int exponnet; // 指数 
	PtrNode Next; 
} PolyNode; // 结构体类型的名字
typedef PolyNode *PtrNode; // 指针类型的名字
///////////////////////////////////////////////////

#endif

int main(void)
{

}
