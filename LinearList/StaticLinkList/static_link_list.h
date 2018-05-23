//
// Created by hao on 18-5-23.
//

#ifndef STATICLINKLIST_STATIC_LINK_LIST_H
#define STATICLINKLIST_STATIC_LINK_LIST_H

#include <stdio.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data;
    int cur;  // 游标， 为 0 时表示无指向
} Component, StaticLinkList[MAXSIZE];

// 将一维数组space中各分量链成一个备用链表, space[0].cur 为头指针, 0 表示空指针
Status InitList(StaticLinkList space);

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L);

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SLL(StaticLinkList space);

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList L, int i, ElemType e);

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k);

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i);

/* 输出静态链表元素 */
Status visit(ElemType c);

/* 遍历静态链表 */
Status ListTraverse(StaticLinkList L);

#endif //STATICLINKLIST_STATIC_LINK_LIST_H
