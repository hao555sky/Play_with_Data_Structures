//
// Created by hao on 18-5-23.
//

#ifndef LINKED_LIST_LINK_LIST_H
#define LINKED_LIST_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node * LinkList;

// 初始化顺序链表, 带有头结点的链表
Status InitList(LinkList *L);

// 初始条件：顺序线性表 L 已存在。 操作结果：若 L 为空表，则返回 TRUE， 否则返回 FALSE
Status ListEmpty(LinkList L);

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L);

// 初始条件：顺序线性表 L 已存在， 1 <= i <= ListLength(L)
// 操作结果：用 e 返回 L 中第 i 个数据元素的值
Status GetElem(LinkList L, int i, ElemType *e);

// 初始条件：顺序线性表 L 已存在。 操作结果：返回 L 中第1个与 e 满足关系的数据元素的位序
// 若这样的数据元素不存在，则返回值为 0
int LocateElem(LinkList L, ElemType e);

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
// 为什么要使用LinkList *L, 而不是 LinkList L
Status ListInsert(LinkList *L, int i, ElemType e);

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n);

// 初始条件： 顺序线性表 L 已存在。 操作结果：返回 L 中数据元素个数
Status ClearList(LinkList *L);

/* 输出链表元素 */
Status visit(ElemType e);

/* 遍历链表 */
Status ListTraverse(LinkList L);

#endif //LINKED_LIST_LINK_LIST_H
