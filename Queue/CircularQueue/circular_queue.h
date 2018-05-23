//
// Created by hao on 18-5-23.
//

#ifndef CIRCULARQUEUE_CIRCULAR_QUEUE_H
#define CIRCULARQUEUE_CIRCULAR_QUEUE_H

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;

/* 循环队列结构 */
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

/* 初始化一个空队列 */
Status InitQueue(SqQueue *Q);

/* 将 Q 清为空队列 */
Status ClearQueue(SqQueue *Q);

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(SqQueue Q);

/* 返回 Q 的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q);

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(SqQueue Q, QElemType *e);

/* 若队列未满，则插入元素 e 为 Q 新的队尾元素 */
Status EnQueue(SqQueue *Q, QElemType e);

/* 若队列不空，则删除 Q 中队头元素，用 e 返回其值 */
Status DeQueue(SqQueue *Q, QElemType *e);

/* 输出队列元素 */
Status visit(QElemType c);

/* 遍历队列 */
Status QueueTraverse(SqQueue Q);

#endif //CIRCULARQUEUE_CIRCURLAR_QUEUE_H
