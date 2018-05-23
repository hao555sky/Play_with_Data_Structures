//
// Created by hao on 18-5-23.
//

#ifndef LINKQUEUE_LINK_QUEUE_H
#define LINKQUEUE_LINK_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
}LinkQueue;

/* 构造一个空队列Q */
Status InitQueue(LinkQueue *Q);

/* 销毁队列Q */
Status DestroyQueue(LinkQueue *Q);

/* 将Q清为空队列 */
Status ClearQueue(LinkQueue *Q);

/* 若Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(LinkQueue Q);

/* 求队列的长度 */
int QueueLength(LinkQueue Q);

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(LinkQueue Q, QElemType *e);

/* 插入元素 e 为 Q 的新的队尾元素 */
Status EnQueue(LinkQueue *Q, QElemType e);

/* 若队列不空，删除 Q 的队头元素， 用 e 返回其值，并返回OK  否则返回 ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e);

/* 输出队列元素 */
Status visit(QElemType c);

/* 从队头到队尾依次对队列Q中每个元素输出 */
Status QueueTraverse(LinkQueue Q);

#endif //LINKQUEUE_LINK_QUEUE_H
