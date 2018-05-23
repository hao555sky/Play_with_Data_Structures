//
// Created by hao on 18-5-23.
//

#ifndef DOUBLESTACK_DOUBLE_STACK_H
#define DOUBLESTACK_DOUBLE_STACK_H

#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType data[MAXSIZE];
    int top1;  // 栈1 栈顶指针  top1 == -1 时为空
    int top2;  // 栈2 栈顶指针  top2 == MAXSIZE 时为空
}SqDoubleStack;

/*  构造一个空栈S */
Status InitStack(SqDoubleStack *S);

/* 把S置为空栈 */
Status ClearStack(SqDoubleStack *S);

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqDoubleStack S);

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqDoubleStack S);

// 插入元素 e 为新的栈顶元素
Status Push(SqDoubleStack *S, SElemType e, int stackNumber);

// 若栈不空，则删除 S 的栈顶元素，用 e 返回其值， 并返回 OK； 否则返回 ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber);

/* 输出栈元素 */
Status visit(SElemType c);

/* 遍历栈 */
Status StackTraverse(SqDoubleStack S);

#endif //DOUBLESTACK_DOUBLE_STACK_H
