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
Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

// 初始条件：顺序表 L 已存在。 操作结果：若 L 为空表，则返回 TRUE， 否则返回 FALSE
Status ListEmpty(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

// 初始条件：顺序表 L 已存在。 操作结果：返回 L 中数据元素个数
int ListLength(SqList L)
{
    return L.length;
}

// 初始条件：顺序表 L 已存在， 且 1 <= i <= L.length
// 操作结果： 返回 L 中第 i 个数据元素的值，保存在 e 中， i 表示位置，第 i 个数据元素下标为 i - 1
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

// 初始条件： 顺序表 L 已存在
// 操作结果： 返回 L 中第 1 个与 e 满足关系的数据元素的位序
// 若这样的数据元素不存在，则返回值为 0
Status LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
        return 0;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            break;
    if (i >= L.length)
        return 0;
    return i + 1;
}

// 初始条件： 顺序表 L 已存在, 1 <= i <= ListLength(L)
// 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e ， L 的长度加 1
Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE)  // 顺序表已满
        return ERROR;
    if (i < 1 || i > L->length + 1)  // 当 i 比第一位置小或比最后一个位置后一位置还要大时
        return ERROR;
    if (i <= L->length)  // 若插入位置不在表尾
    {
        for(int x = L->length - 1; x >= i - 1; x--)  // 将要插入位置之后的数据元素向后移动一位
            L->data[x + 1] = L->data[x];
    }
    L->data[i - 1] = e;  // 将新元素插入
    L->length++;
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)  /* 线性表为空 */
        return ERROR;
    if(i < 1 || i > L->length)  /* 删除位置不正确 */
        return ERROR;
    *e = L->data[i - 1];
    if(i < L->length)    /* 如果删除不是最后位置 */
    {
        for(int k = i - 1; k < L->length - 1; k++)  /* 将删除位置后继元素前移 */
            L->data[k] = L->data[k + 1];
    }
    L->length--;
    return OK;
}

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
    int i;
    for(i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}

void unionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for(i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);
        if(!LocateElem(*La, e))
            ListInsert(La, ++La_len, e);
    }
}

int main() {
    SqList L;
    ElemType e;
    Status i;
    int j, k;

    i = InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n", L.length);
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n",e);

    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j);
        if(k)
            printf("第%d个元素的值为%d\n",k,j);
        else
            printf("没有值为%d的元素\n",j);
    }

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e); /* 删除第j个数据 */
        if(i==ERROR)
            printf("删除第%d个数据失败\n",j);
        else
            printf("删除第%d个的元素值为：%d\n",j,e);
    }

    printf("依次输出L的元素：");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    SqList Lb;
    i = InitList(&Lb);
    for(j = 6; j <= 15; j++)
        i = ListInsert(&Lb, 1, j);
    unionL(&L, Lb);
    printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L);

    return 0;
}