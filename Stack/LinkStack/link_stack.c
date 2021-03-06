//
// Created by hao on 18-5-23.
//

#include "link_stack.h"

/*  构造一个空栈S */
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack *S)
{
    LinkStackPtr p, q;
    p = S->top;
    while(p)
    {
        q = p;
        p = q->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{
    if(S.count == 0)
        return TRUE;
    return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{
    return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S, SElemType *e)
{
    if(S.top == NULL)
        return ERROR;
    *e = S.top->data;
    return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->next = S->top;  // 把当前的栈顶元素地址赋给新节点的后继指针
    s->data = e;
    S->top = s;  // 将新结点 s 赋值给栈顶指针
    S->count++;
    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr q;
    if(StackEmpty(*S))
        return ERROR;
    *e = S->top->data;
    q = S->top;  // 将栈顶结点赋给 q
    S->top = q->next;  // 栈顶指针后移一位，指向下一结点
    free(q);  // 释放结点
    S->count--;
    return OK;
}

Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

Status StackTraverse(LinkStack S)
{
    LinkStackPtr p = S.top;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}