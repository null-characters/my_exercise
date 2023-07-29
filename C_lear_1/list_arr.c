#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list_arr.h"

#define SIZE 100
struct Node
{
	int element[SIZE]; // 表的元素都存在数组中
	int length; // 表中元素的个数，实际存储的有效元素个数
};

bool IsEmpty(List L)
{
	return L->length == 0;
}

// bool IsLast(Position P, List L)
// {
// 	return P->Next == NULL;
// }

// 查找值位x的元素的数组下标
int Find(int x, List L)
{
	if (L->length == 0)
	{ // 空表
		return -1;
	}
	for (int i = 0; i < L->length; i++)
	{
		if (L->element[i] == x)
		{
			return i;
		}
	}
	return -1;	
}

// 找到第pos位置上的元素
int FindKthForList(List L, int pos)
{
	if (pos > L->length || pos < 0)
	{
		printf_s("error enter! please enter numble to 1 - %d\n", L->length);
		exit(1);
	}

	return L->element[pos - 1];
}

// 删除值为x的元素
void Delete(int x, List L)
{
	int pos;
	if ((pos = Find(x, L)) == -1)
	{
		printf_s("not find x!\n");
	}
	for (int i = pos; i < L->length; i++)
	{
		L->element[i] = L->element[i + 1];
	}
	L->length--;
}
// 删除第pos位置的元素
void DeleteKthForList(List L, int pos)
{
	if (pos > L->length || pos <= 0)
	{
		printf_s("not find x!\n");
		return ;
	}
	
	for (int i = pos - 1; i < L->length; i++)
	{
		L->element[i] = L->element[i + 1];
	}
	L->length--;
}

// int FindPrevious(int x, List L)
// {
// 	Position P;
// 	if (L == NULL)
// 		return L;
// 	P = L;
// 	while (P->Next != NULL && P->Next->element != x)
// 	{
// 		P = P->Next;
// 	}
// 	return P;
// }

// void Insert(int x, List L, Position P)
// {
// 	Position Temp;
// 	Temp = calloc(1, sizeof(struct Node));
// 	if (Temp == NULL)
// 		return;
// 	Temp->element = x;
// 	Temp->Next = P->Next; // 把原本P指向的位置赋值给插入的值
// 	P->Next = Temp;		  // 把插入的值的位置赋值给P，也就是在P的后面插入x
// }

// int MakeEmpty(List L) // 清空链表
// {
// 	Position P;
// 	P = L; // 使用临时指针p指向头结点
// 	while (P != NULL)
// 	{
// 		L = L->Next;
// 		free(P);
// 		P = L;
// 	}
	///////////////////////////////////////////////////////////////
	// while (P != NULL)
	// {
	// 	free(P);
	// 	P = L->Next;
	// }
	 // 它在释放P之后还试图访问P->Next。因为free(P)会使得P指向的内存不再有效，\
	所以P->Next也不再有效。这样就可能导致程序崩溃或者未定义行为。
	///////////////////////////////////////////////////////////////
// }

void DeleteList(List L)
{
}

List CreatHeadNode(void)
{
	List L;

	L = calloc(1, sizeof(struct Node));
	L->length = 0;

	return L;
}

void InsertForHead(int x, List L)
{
	int i;
	if (L->length >= SIZE)
	{ // 判断表是不是满了
		printf_s("list is full!\n");
		return ;
	}

	for (i = L->length; i > 0; i--)
	{
		L->element[i] = L->element[i-1];
	}
	L->element[0] = x;
	L->length++;	
}

// 在链表的尾结点插入数据
void InsertForLast(int x, List L)
{
	if (L->length >= SIZE)
	{
		return;
	}
	L->element[L->length] = x;
	L->length++;
}

// 这种做法直接操作修改了L，将L的指针指向链表的尾结点，不建议使用这种方法
// void PrintfForList(List L)
// {
// 	if (L == NULL)
// 		return ;
// 	L = L->Next; // 跳过头结点
// 	while (L != NULL)
// 	{
// 		printf_s("element = %d\n", L->element);
// 		L = L->Next;
// 	}
// }

void PrintfForList(List L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf_s("%d\t", L->element[i]);
	}
	printf_s("\n");
}

// void DeleteKthForList(List L, int pos)
// {
// 	List temp, p;
// 	if (L == NULL || pos <= 0)
// 	{
// 		return;
// 	}

// 	temp = L;
// 	for (int i = 0; i < pos - 1; i++)
// 	{ // 找到pos的前驱
// 		temp = temp->Next;
// 		if (temp == NULL)
// 		{
// 			printf_s("no x element\n"); // 没有第x个元素
// 			return;
// 		}
// 	}

// 	p = temp->Next;
// 	temp->Next = p->Next;
// 	free(p);
// }

// void DeleteEleForList(List L, int x)
// {
// 	List p_prious, p;
// 	p_prious = L; // 存储前驱
// 	p = L->Next;  // 指向第一个真正的元素
// 	while (p != NULL)
// 	{
// 		if (p->element == x)
// 		{
// 			p_prious->Next = p->Next;
// 			free(p);
// 			return;
// 		}
// 		else
// 		{
// 			p_prious = p;
// 			p = p->Next;
// 		}
// 	}
// }

int main(void)
{
	List Node;
	Position p;
	Node = CreatHeadNode();

	printf_s("creat a empty? = %d\n", IsEmpty(Node));

	InsertForHead(20, Node);
	InsertForHead(50, Node);
	InsertForLast(60, Node);
	InsertForLast(80, Node);

	printf_s("Find date 50 in : %d\n", Find(50, Node));
	printf_s("Find date 60 in : %d\n", Find(60, Node));

	printf_s("Find pos 2 date is : %d\n", FindKthForList(Node, 2));
//	printf_s("Find pos -1 date is : %d\n", FindKthForList(Node, -1));

	PrintfForList(Node);

//	Delete(50, Node);
	DeleteKthForList(Node, 3);

	PrintfForList(Node);
	// FindKthForList(Node, 2); // 找到第x个元素

	// DeleteKthForList(Node, 2);
	// DeleteEleForList(Node, 50);

	// FindKthForList(Node, 2); // 找到第x个元素

	return true;
}
