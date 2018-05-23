//
// Created by hao on 18-5-23.
//

#include "sequential_stack.h"

// 构造一个空栈 S
Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{
    if(S.top == -1)
        return TRUE;
    else
        return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{
    return S.top+1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S, SElemType *e)
{
    if(S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
    return OK;
}


/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE - 1)  /* 栈满 */
        return ERROR;
    S->top++;   /* 栈顶指针增加一 */
    S->data[S->top] = e;     /* 将新插入元素赋值给栈顶空间 */
    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];   /* 将要删除的栈顶元素赋值给e */
    S->top--;               /* 栈顶指针减一 */
    return OK;
}

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

Status StackTraverse(SqStack S)
{
    int i = 0;
    while(i <= S.top)
        visit(S.data[i++]);
    printf("\n");
    return OK;
}