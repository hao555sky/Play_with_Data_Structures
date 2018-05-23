//
// Created by hao on 18-5-23.
//

#include "link_queue.h"

/* 构造一个空队列Q */
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

/* 销毁队列Q */
Status DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

/* 将Q清为空队列 */
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

/* 若Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    return FALSE;
}

/* 求队列的长度 */
int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p = Q.front;
    while(p != Q.rear)
    {
        p = p->next;
        ++i;
    }
    return i;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(LinkQueue Q, QElemType *e)
{
    if(Q.front == Q.rear)
        return ERROR;
    *e = Q.front->next->data;
    return OK;
}

/* 插入元素 e 为 Q 的新的队尾元素 */
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s)                     /* 存储分配失败 */
        return ERROR;
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;         /* 把拥有元素 e 新节点 s 赋值给原队尾结点的后继 */
    Q->rear = s;               /* 把当前的 s 设置为队尾节点， rear 指向 s */
    return OK;
}

/* 若队列不空，删除 Q 的队头元素， 用 e 返回其值，并返回OK  否则返回 ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    if(Q->front == Q->rear)
        return ERROR;
    QueuePtr q = Q->front->next;  /* 将欲删除的队头结点暂存给 q */
    *e = q->data;                 /* 将欲删除结点的队头结点的值赋给 e */
    Q->front->next = q->next;     /* 将原队头结点后继 q->next 赋值给头结点后继 */

    if(Q->rear == q)              /* 若队头是队尾，则删除后将 rear 指向头结点 */
        Q->rear = Q->front;
    free(q);
    return OK;
}

Status visit(QElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 从队头到队尾依次对队列Q中每个元素输出 */
Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p = Q.front->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}