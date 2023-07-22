#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef struct Node *PtrtoNode;
typedef PtrtoNode Position;
typedef PtrtoNode List;

List CreatHeadNode(void); // 创建头结点
void InsertForHead(int x, List L); // 在头结点插入数据
void InsertForLast(int x, List L); // 在头结点插入数据
void PrintfForList(List L); // 在头结点插入数据
void PrintKthForList(List L, int x); // 打印第x个元素

//
List MakeEmpty(List L);                 // 清空链表
bool IsEmpty(List L);                    // 当前列表是否为空
bool IsLast(Position P, List L);         // 判断是否是最后一个元素
Position Find(int x, List L);           // 判断元素是否在列表中
Position FindKth(int pos, List L);        // 查找该位置上的元素
void Delete(int x, List L);             // 删除某元素
Position FindPrevious(int x, List L);   // 找到元素的前一个地址
void Insert(int x, List L, Position P); // 插入元素
void DeleteList(List L);                // 删除表
Position Header(List L);                // 头结点
Position Frist(List L);                 //

#endif
