//
// Created by hao on 18-5-23.
//

#include "static_link_list.h"

// 将一维数组space中各分量链成一个备用链表, space[0].cur 为头指针, 0 表示空指针
Status InitList(StaticLinkList space)
{
    for(int i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;  // 目前静态链表为空，最后一个元素的 cur 为 0
    return OK;
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while(i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if(i < 1 || i > ListLength(L) + 1)
        return ERROR;
    j = Malloc_SLL(L);
    if(j)
    {
        L[j].data = e;
        for(l = 1; l <= i - 1; l++)
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if(i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for(j = 1; j <= i - 1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

/* 输出静态链表元素 */
Status visit(ElemType c)
{
    printf("%c ", c);
    return OK;
}

/* 遍历静态链表 */
Status ListTraverse(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while(i)
    {
        visit(L[i].data);
        i = L[i].cur;
        j++;
    }
    return OK;
}