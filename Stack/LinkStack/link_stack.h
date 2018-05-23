//
// Created by hao on 18-5-23.
//

#ifndef LINKSTACK_LINK_STACK_H
#define LINKSTACK_LINK_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

/*  构造一个空栈S */
Status InitStack(LinkStack *S);

/* 把S置为空栈 */
Status ClearStack(LinkStack *S);

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S);

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S);

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S, SElemType *e);

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, SElemType e);

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S, SElemType *e);

/* 输出栈元素 */
Status visit(SElemType c);

/* 遍历栈 */
Status StackTraverse(LinkStack S);


#endif //LINKSTACK_LINK_STACK_H
