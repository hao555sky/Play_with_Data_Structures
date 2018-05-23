//
// Created by hao on 18-5-23.
//

#ifndef LINEARLIST_LINEAR_LIST_H
#define LINEARLIST_LINEAR_LIST_H

#include <stdio.h>

#define MAXSIZE 20  // 存储空间初始分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;  // ElemType 类型根据实际情况而定， 这是设为 int
typedef int Status;  // Status 是函数的类型，其值是函数结果状态带啊，如OK等

typedef struct
{
    ElemType data[MAXSIZE];  // 数组存储数据元素， 最大值为 MAXSIZE
    int length;  // 线性表当前长度
} SqList;

// 初始化顺序线性表
Status InitList(SqList *L);

// 初始条件：顺序表 L 已存在。 操作结果：若 L 为空表，则返回 TRUE， 否则返回 FALSE
Status ListEmpty(SqList L);

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L);

// 初始条件：顺序表 L 已存在。 操作结果：返回 L 中数据元素个数
int ListLength(SqList L);

// 初始条件：顺序表 L 已存在， 且 1 <= i <= L.length
// 操作结果： 返回 L 中第 i 个数据元素的值，保存在 e 中， i 表示位置，第 i 个数据元素下标为 i - 1
Status GetElem(SqList L, int i, ElemType *e);

// 初始条件： 顺序表 L 已存在
// 操作结果： 返回 L 中第 1 个与 e 满足关系的数据元素的位序
// 若这样的数据元素不存在，则返回值为 0
Status LocateElem(SqList L, ElemType e);

// 初始条件： 顺序表 L 已存在, 1 <= i <= ListLength(L)
// 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e ， L 的长度加 1
Status ListInsert(SqList *L, int i, ElemType e);

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i, ElemType *e);

/* 输出顺序表元素 */
Status visit(ElemType e);

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L);

/* 合并线性表 */
void unionL(SqList *La, SqList Lb);

#endif //LINEARLIST_LINEAR_LIST_H
