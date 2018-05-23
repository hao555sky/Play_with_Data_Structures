//
// Created by hao on 18-5-23.
//

#ifndef STACK_WITH_SEQUENTIAL_STORAGE_SEQUENTIAL_STACK_H
#define STACK_WITH_SEQUENTIAL_STORAGE_SEQUENTIAL_STACK_H

#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType data[MAXSIZE];
    int top;  // 用于栈顶指针
}SqStack;

// 构造一个空栈 S
Status InitStack(SqStack *S);

/* 把S置为空栈 */
Status ClearStack(SqStack *S);

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S);

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S);

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S, SElemType *e);

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S, SElemType e);

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S, SElemType *e);

/* 输出栈元素 */
Status visit(SElemType c);

/* 遍历栈 */
Status StackTraverse(SqStack S);

#endif //STACK_WITH_SEQUENTIAL_STORAGE_SEQUENTIAL_STACK_H
