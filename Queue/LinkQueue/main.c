#include "link_queue.h"

int main() {

    LinkQueue q;
    QElemType e;
    if(InitQueue(&q))
        printf("成功地构造了一个空队列!\n");

    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
    printf("队列的长度为%d\n",QueueLength(q));

    EnQueue(&q, -5);
    EnQueue(&q, 5);
    EnQueue(&q, 10);

    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",QueueLength(q));
    printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
    printf("队列的元素依次为：");
    QueueTraverse(q);

    if(GetHead(q, &e) == OK)
        printf("队头元素是：%d\n", e);

    DeQueue(&q, &e);
    printf("删除了队头元素%d\n", e);

    if(GetHead(q, &e) == OK)
        printf("新的队头元素是：%d\n", e);

    ClearQueue(&q);
    printf("清空队列后,q.front=%p q.rear=%p q.front->next=%p\n", q.front, q.rear, q.front->next);

    DestroyQueue(&q);
    printf("销毁队列后,q.front=%p q.rear=%p\n",q.front, q.rear);

    return 0;
}