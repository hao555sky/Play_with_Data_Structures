//
// Created by hao on 18-5-23.
//

#include "circular_queue.h"

#include <stdio.h>

/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 将Q清为空队列 */
Status ClearQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front)  // 队列空的标志
        return TRUE;
    return FALSE;
}

/* 返回 Q 的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(SqQueue Q, QElemType *e)
{
    if(Q.front == Q.rear)
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

/* 若队列未满，则插入元素 e 为 Q 新的队尾元素 */
Status EnQueue(SqQueue *Q, QElemType e)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)  // 队列满的判断
        return ERROR;
    Q->data[Q->rear] = e;  // 将元素 e 赋值给队尾
    Q->rear = (Q->rear + 1) % MAXSIZE;  // rear 指针向后移一位置，若到最后则转到数组头部
    return OK;
}

/* 若队列不空，则删除 Q 中队头元素，用 e 返回其值 */
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if(Q->rear == Q->front)  /* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];  // 将队头元素赋值给 e
    Q->front = (Q->front + 1) % MAXSIZE;  // front 指针向后移一位置，若到最后则转到数组头部
    return OK;
}

Status visit(QElemType c)
{
    printf("%d ", c);
    return OK;
}

Status QueueTraverse(SqQueue Q)
{
    int i = Q.front;
    while((i + Q.front) != Q.rear)
    {
        visit(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}