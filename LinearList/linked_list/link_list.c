//
// Created by hao on 18-5-23.
//

#include "link_list.h"

// 初始化顺序链表
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));  // 产生投机诶单，并使 L 指向此头结点
    if(!(*L))  // 存储分配失败
        return ERROR;
    (*L)->next = NULL;  // 指针域赋为空
    return OK;
}

// 初始条件：顺序线性表 L 已存在。 操作结果：若 L 为空表，则返回 TRUE， 否则返回 FALSE
Status ListEmpty(LinkList L)
{
    if(L->next)
        return FALSE;
    else
        return TRUE;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        p = p->next;
        ++i;
    }
    return i;
}

// 初始条件：顺序线性表 L 已存在， 1 <= i <= ListLength(L)
// 操作结果：用 e 返回 L 中第 i 个数据元素的值
Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;  // 声明一个结点指针，指向链表 L 的第一个结点
    int j = 1;
    while(p && j < i) // p 不为空或计数器 j 还没有等于 i 时，循环继续
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;  // 第 i 个元素不存在
    *e = p->data;  // 取第 i 个元素的数据
    return OK;
}

// 初始条件：顺序线性表 L 已存在。 操作结果：返回 L 中第1个与 e 满足关系的数据元素的位序
// 若这样的数据元素不存在，则返回值为 0
int LocateElem(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 0;
    while(p)
    {
        ++i;
        if(p->data == e)
            return i;
        p = p->next;
    }
    return 0;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
// 为什么要使用LinkList *L, 而不是 LinkList L
Status ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList p, s;
    p = *L;
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;  /* 将p的后继结点赋值给s的后继  */
    p->next = s;        /* 将s赋值给p的后继 */
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p, q;
    p = *L;
    int j = 1;
    while(p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;
    q = p->next;      /* 将q的后继赋值给p的后继 */
    *e = q->data;     /* 将q结点中的数据给e */
    p->next = q->next;  /* 让系统回收此结点，释放内存 */
    free(q);
    return OK;
}

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;   /*  先建立一个带头结点的单链表 */
    for(int i = 0; i < n; ++i)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;   /*  插入到表头 */
    }
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));  /* L为整个线性表 */
    r = *L;                               /* r为指向尾部的结点 */
    for(int i = 0; i < n; ++i)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;                      /* 将表尾终端结点的指针指向新结点 */
        r = p;                            /* 将当前的新结点定义为表尾终端结点 */
    }
    r->next = NULL;                       /* 表示当前链表结束 */
}

// 初始条件： 顺序线性表 L 已存在。 操作结果：返回 L 中数据元素个数
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;  // p 指向第一个结点
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}