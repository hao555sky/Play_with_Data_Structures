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
Status InitStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqDoubleStack S)
{
    if(S.top1 == -1 && S.top2 == MAXSIZE)
        return TRUE;
    return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

// 插入元素 e 为新的栈顶元素
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1 + 1 == S->top2)  // 栈满
        return ERROR;
    if(stackNumber == 1)  // 栈1 进栈
        S->data[++S->top1] = e;  // 先更新栈顶指针 top1 + 1，再赋值
    else if(stackNumber == 2)  // 栈2 进栈
        S->data[--S->top2] = e;  // 先更新栈顶指针 top2 - 1， 再赋值
    return OK;
}

// 若栈不空，则删除 S 的栈顶元素，用 e 返回其值， 并返回 OK； 否则返回 ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(S->top1 == -1)  // 栈1 为空栈
            return ERROR;
        *e = S->data[S->top1--];  // 将栈1栈顶元素赋值给 e， 出栈
    }
    else if(stackNumber == 2)
    {
        if(S->top2 == MAXSIZE)  // 栈2 为空栈
            return ERROR;
        *e = S->data[S->top2++];  // // 将栈2栈顶元素赋值给 e， 出栈
    }
    return OK;
}

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

Status StackTraverse(SqDoubleStack S)
{
    int i = 0;
    while(i <= S.top1)
        visit(S.data[i++]);
    i = MAXSIZE - 1;
    while(i >= S.top2)
        visit(S.data[i--]);
    printf("\n");
    return OK;
}

int main() {
    SqDoubleStack s;
    SElemType e;
    if(InitStack(&s) == OK)
    {
        for(int j = 1; j <= 5; j++)
            Push(&s, j, 1);
        for(int j = MAXSIZE; j >= MAXSIZE - 2; j--)
            Push(&s, j, 2);
    }

    printf("栈中元素依次为：");
    StackTraverse(s);

    printf("当前栈中元素有：%d \n",StackLength(s));

    Pop(&s, &e, 2);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    for(int j = 6; j <= MAXSIZE - 2; j++)
        Push(&s, j, 1);

    printf("栈中元素依次为：");
    StackTraverse(s);

    printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));

    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    return 0;
}