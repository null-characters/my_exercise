#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

struct Node
{
	int element;   // 成员
	Position Next; // 指向下一节点的指针  等价 struct Node* Next;
};

bool IsEmpty(List L)
{
	return L->Next == NULL;
}

bool IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(int x, List L)
{
	Position P;

	P = L->Next; // 这是一个带表头的链表，所以直接将表头后的地址赋值给P
	while (P != NULL && P->element != x)
	{ // 如果链表不是空并且元素不等于要找的元素，则将位置指向下一个结点
		P = P->Next;
	}

	return P; // 要么找到元素，P指向找到元素时的位置；要么没找到P指向NULL
}

void Delete(int x, List L)
{
	Position P, Temp;
	if (L == NULL)
		return;
	// 删除操作首先需要找到需要删除元素的前一个地址
	P = FindPrevious(x, L);
	if (!IsLast(P, L))		  // 此时P已经是要删除元素的前一个地址了，\
                                所以如果P是最后一个元素，则表明并没有找到要删除的元素
	{						  // 然后判断要删除的元素是不是最后一个
		Temp = P->Next;		  // 将P的下一个元素（要删除的元素）地址赋值给临时量
		P->Next = Temp->Next; // 将下下个元素的地址赋值到下个元素的地方（跳过下个元素的地址）
		free(Temp);
	}
}

Position FindPrevious(int x, List L)
{
	Position P;
	if (L == NULL)
		return L;
	P = L;
	while (P->Next != NULL && P->Next->element != x)
	{
		P = P->Next;
	}
	return P;

	/*
		Position P, Q;
		P = L;                               // P初始指向表头或者哑结点
		Q = L->Next;                         // Q初始指向第一个真正存储数据的节点
		while (Q != NULL && Q->element != x) // 循环判断Q是否为空或者是否等于x
		{
			P = Q;       // P指向Q
			Q = Q->Next; // Q指向下一个节点
		}
		return P; // 返回P，如果链表为空或者元素x不存在，则P指向最后一个节点；如果元素x存在，则P指向元素x的前一个节点
	*/
}

void Insert(int x, List L, Position P)
{
	Position Temp;
	Temp = calloc(1, sizeof(struct Node));
	if (Temp == NULL)
		return;
	Temp->element = x;
	Temp->Next = P->Next; // 把原本P指向的位置赋值给插入的值
	P->Next = Temp;		  // 把插入的值的位置赋值给P，也就是在P的后面插入x
}

List MakeEmpty(List L) // 清空链表
{
	Position P;
	P = L; // 使用临时指针p指向头结点
	while (P != NULL)
	{
		L = L->Next;
		free(P);
		P = L;
	}
	///////////////////////////////////////////////////////////////
	// while (P != NULL)
	// {
	// 	free(P);
	// 	P = L->Next;
	// }
	 // 它在释放P之后还试图访问P->Next。因为free(P)会使得P指向的内存不再有效，\
	所以P->Next也不再有效。这样就可能导致程序崩溃或者未定义行为。
	///////////////////////////////////////////////////////////////
}

void DeleteList(List L)
{
}

List CreatHeadNode(void)
{
	List L;

	L = calloc(1, sizeof(struct Node));
	if (L == NULL)
	{
		printf_s("error!\n");
		exit(1);
		// return L;
	}

	//	L->element = 0;
	L->Next = NULL;

	return L;
}

void InsertForHead(int x, List L)
{
	List temp;

	temp = calloc(1, sizeof(struct Node));
	if (temp == NULL)
		printf_s("error!\n"); // 分配内存失败

	temp->element = x;
	temp->Next = L->Next; // 将头结点指向赋值给新的结点
	L->Next = temp;		  // 新结点作为头节点的后继结点
}

// 在链表的尾结点插入数据
void InsertForLast(int x, List L)
{
	List temp, p;

	temp = calloc(1, sizeof(struct Node));
	if (temp == NULL)
	{
		printf_s("error!\n"); // 分配内存失败
		return;
	}

	temp->element = x;
	temp->Next = NULL; // 尾结点直接赋NULL

	p = L;
	while (p->Next != NULL)
	{ // 将指针指向尾结点的位置
		p = p->Next;
	}
	p->Next = temp; // 新结点加入到尾结点后成为新的尾结点
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
	List temp;
	temp = L->Next; // 把第一个真正的元素传入
	while (temp != NULL)
	{
		printf_s("node element is %d\n", temp->element);
		temp = temp->Next;
	}
	free(temp);
}

int FindKthForList(List L, int pos)
{
	List temp;
	int result;									  // 返回值
	if (L == NULL || L->Next == NULL || pos <= 0) // 如果是空列表或者找的位置不合理则直接返回
	{
		printf_s("input is error!\n");
		return -1;
	}

	temp = L;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
		if (temp == NULL)
		{
			printf_s("no x element\n"); // 没有x个元素
			return -2;
		}
	}

	result = temp->element;
	printf_s("element is = %d\n", result);
	//	free(temp);
	return result;
}

void DeleteKthForList(List L, int pos)
{
	List temp, p;
	if (L == NULL || pos <= 0)
	{
		return;
	}

	temp = L;
	for (int i = 0; i < pos - 1; i++)
	{ // 找到pos的前驱
		temp = temp->Next;
		if (temp == NULL)
		{
			printf_s("no x element\n"); // 没有第x个元素
			return;
		}
	}

	p = temp->Next;
	temp->Next = p->Next;
	free(p);
}

void DeleteEleForList(List L, int x)
{
	List p_prious, p;
	p_prious = L; // 存储前驱
	p = L->Next;  // 指向第一个真正的元素
	while (p != NULL)
	{
		if (p->element == x)
		{
			p_prious->Next = p->Next;
			free(p);
			return;
		}
		else
		{
			p_prious = p;
			p = p->Next;
		}
	}
}

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

	p = Find(50, Node);
	if (p != NULL)
	{
		printf_s("find node element = %d\n", p);
	}
	else
	{
		printf_s("not find!\n");
	}

	// printf_s("x element numble is = %d\n", p->element);
	// printf_s("x element numble is = %d\n", p);

	PrintfForList(Node);

	FindKthForList(Node, 2); // 找到第x个元素

	DeleteKthForList(Node, 2);
	DeleteEleForList(Node, 50);

	FindKthForList(Node, 2); // 找到第x个元素

	return true;
}
