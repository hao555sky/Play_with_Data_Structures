#include "circular_queue.h"
#include <stdio.h>

int main() {
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

    printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ",MAXSIZE-1);
    for(int i = 1; i <= 10; i++)
        EnQueue(&Q, i);

    printf("队列长度为: %d\n",QueueLength(Q));
    printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);

    for(int l=1;l<=MAXSIZE;l++)
    {
        DeQueue(&Q,&d);
        printf("删除的元素是%d,插入的元素:%d \n",d,l+1000);
        /* scanf("%d",&d); */
        d=l+1000;
        EnQueue(&Q,d);
    }
    printf("队列长度为: %d\n",QueueLength(Q));

    printf("现在队列中的元素为: \n");
    QueueTraverse(Q);

    while(QueueLength(Q)>2)
    {
        DeQueue(&Q,&d);
        printf("删除的元素值为%d\n",d);
    }

    if(GetHead(Q, &d))
        printf("现在队头元素为: %d\n",d);

    ClearQueue(&Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

    return 0;
}