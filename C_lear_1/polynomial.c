#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "polynomial.h"

#define _USE_ARR_SAVE_POLY_
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
#endif

int main(void)
{

}
