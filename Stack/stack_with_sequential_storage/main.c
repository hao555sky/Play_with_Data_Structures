#include "sequential_stack.h"
#include <stdio.h>

int main() {
    SqStack s;
    SElemType e;
    if(InitStack(&s) == OK)
        for(int i = 1; i <= 10; i++)
            Push(&s, i);
    printf("栈中元素依次为：");
    StackTraverse(s);

    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n",e);

    printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));

    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    return 0;
}