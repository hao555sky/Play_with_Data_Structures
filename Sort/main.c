#include <stdio.h>

#define MAXSIZE 10   // 用于待排序数组个数的最大值, 可根据需要修改
#define MAX_LENGTH_INSERT_SORT 7

typedef struct
{
    int r[MAXSIZE + 1];  // 用于存储待排序数组, r[0] 用作哨兵或临时变量
    int length;          // 用于记录顺序表的长度
}SqList;

/*
 * 交换 L 中数组 r 的下标为 i 和 j 的值
 */
void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void print(SqList L)
{
    int i;
    for(i=1;i<L.length;i++)
        printf("%d,",L.r[i]);
    printf("%d",L.r[i]);
    printf("\n");
}

/*
 * 冒泡排序
 */
void BubbleSort(SqList *L)
{
    for(int i = 1; i < L->length; i++)
    {
        // 注意 j 是从前往后循环, 也可以从后往前循环, 此处的 -i + 1 是为了每次减少比较的次数，因为每次循环都会把当前的最大数放置在其位置
        for(int j = 1; j < L->length - i + 1; j++)
            if(L->r[j] > L->r[j + 1])  // 若前者大于后者
                swap(L, j, j + 1);     // 交换元素值
    }
}

/*
 * 简单选择排序
 */
void SelectSort(SqList *L)
{
    for(int i = 1; i < L->length; i++)
    {
        int min = i;
        for(int j = i + 1; j <= L->length; j++)  // 每次从身后的元素中选择出最小值
            if(L->r[j] < L->r[min])
                min = j;
        if(i != min)
            swap(L, i, min);  // 交换最小值到当前坐标
    }
}

/*
 * 直接插入排序
 */
void InsertSort(SqList *L)
{
    for(int i = 2; i <= L->length; i++)
    {
        if(L->r[i] < L->r[i - 1])  // 需将 L->r[i] 插入到有序子表中
        {
            L->r[0] = L->r[i];  // 设置哨兵
            int j;
            for(j = i - 1; L->r[j] > L->r[0]; j--)
                L->r[j + 1] = L->r[j];  // 记录后移
            L->r[j + 1] = L->r[0];  // 插入到正确位置
        }
    }
}

/**
 * 希尔排序
 * @param L
 * @param s
 * @param m
 */
void ShellSort(SqList *L)
{
    int increment = L->length;
    do
    {
        increment = increment / 3 + 1;  // 增量序列
        for(int i = increment + 1; i <= L->length; i++)
        {
            if(L->r[i] < L->r[i - increment])
            {
                // 需将 L->r[i] 插入有序增量子表
                int j;
                L->r[0] = L->r[i];  // 暂存在 L->r[0]
                for(j = i - increment; j > 0 && L->r[j] > L->r[0]; j -= increment)
                    L->r[j + increment] = L->r[j];  // 记录后移, 查找插入位置
                L->r[j + increment] = L->r[0];  // 插入
            }
        }
    }
    while(increment > 1);
}

/* 堆排序********************************** */
/*
 * 构建大顶堆: 已知 L->r[s ... m]中记录的关键字除 L->r[s] 之外均满足堆的定义
 * 本函数挑中 L->r[s] 的关键字, 使 L->r[s ... m]称为一个大顶堆
 */
void HeapAdjust(SqList *L, int s, int m)
{
    int temp = L->r[s];
    for(int j = s * 2; j <= m; j *= 2)  // 沿关键字较大的孩子节点向下筛选
    {
        if(j < m && L->r[j] < L->r[j + 1])
            ++j;  // j 为关键字中较大的记录下标
        if(temp >= L->r[j])
            break;   // 表示父节点比孩子节点大
        L->r[s] = L->r[j];  // 将孩子节点中最大值插入其父节点
        s = j;
    }
    L->r[s] = temp;  // 插入孩子节点或子孙结点
}
/*
 * 堆排序
 */
void HeapSort(SqList *L)
{
    for(int i = L->length / 2; i >= 1; i--)  // 把 L 中的 r 构建成一个大顶堆
        HeapAdjust(L, i, L->length);
    for(int i = L->length; i > 1; i--)
    {
        swap(L, 1, i);  // 将对顶记录和当前未经排序子序列的最后一个记录交换
        HeapAdjust(L, 1, i - 1);  // 将 L->r[1 ...  i - 1] 重新调整为大顶堆
    }
}
/* **************************************** */

int max(int a, int b)
{
    return a >= b ? a : b;
}

/* 归并排序********************************** */
/**
 * 归并操作, 将 arr[left ... mid] 和 arr[mid + 1 ... right] 归并
 * 该方法先将所有元素复制到辅助数组 temp 中, 然后再归并到 arr[] 中
 * @param arr 待归并数组
 * @param left 起始位置
 * @param mid 中间位置
 * @param right 结束位置
 */
void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0, temp[right - left + 1];
    while(i <= mid && j <= right)  // 将左半边和右半边按大小依次放入 temp 中
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)  // 若左半边留有元素, 则将剩余元素全部放入 temp 中
        temp[k++] = arr[i++];
    while(j <= right)  // 若右半边留有元素, 则将剩余元素全部放入 temp 中
        temp[k++] = arr[j++];
    for(int p = 0; p < k; p++)  // 将排序好的所有元素放回 arr数组, left + p 表示 arr[left, right] 区域
        arr[left + p] = temp[p];
}
/**
 * 归并排序 排序操作
 * @param arr 待排序数组
 * @param left 起始位置
 * @param right 结束位置
 */
void mSort(int arr[], int left, int right)
{
    if(right <= left) return;
    int mid = left + (right - left) / 2;
    mSort(arr, left, mid);  // 递归排序左半边
    mSort(arr, mid + 1, right);  // 递归排序右半边
    merge(arr, left, mid, right);  // 归并
}
/**
 * 归并排序
 * @param L
 */
void MergeSort(SqList *L)
{
    // 将 L 中的数组 r 归并排序, 范围是 [1, L->length]
    mSort(L->r, 1, L->length);
}
/* **************************************** */

/* 快速排序******************************** */
/**
 * 交换顺序表 L 中子表的记录, 使得枢轴确定其位置, 并返回坐标
 * 此时在枢轴左边的元素都不大于它, 在其右边的都不小于它
 * @param L 包含子表的顺序表 L
 * @param low 起始位置
 * @param high 结束位置
 * @return 枢轴位置
 */
int Partition(SqList *L, int low, int high)
{
    int pivotkey = L->r[low];  // 用待排序序列的第一个记录做枢轴记录
    while(low < high)  // 从序列的两端交替的向中间扫描
    {
        while(low < high && L->r[high] > pivotkey)  // 从后向前, 获取小于枢轴记录的记录位置
            --high;
        swap(L, low, high);  // 将比枢轴记录小的记录交换到首端
        while(low < high && L->r[low] < pivotkey)  // 从前向后, 获取大于枢轴记录的记录位置
            ++low;
        swap(L, low, high);  // 将比枢轴记录大的记录交换到尾端
    }
    return low;  // 返回枢轴所在位置
}

/**
 * 快速排序
 * @param L 包含子表的顺序表 L
 * @param low  起始位置下标
 * @param high  结束位置下标
 */
void QSort(SqList *L, int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(L, low, high);  // 将 L->r[low ... high] 一分为二, 算出枢轴记录下标 pivot
        QSort(L, low, pivot - 1);  // 对首端子表递归排序
        QSort(L, pivot + 1, high);  // 对尾端子表递归排序
    }
}

/**
 * 快速排序驱动程序
 * @param L 包含子表的顺序表 L
 */
void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}
/* **************************************** */

/* 改进后快速排序******************************** */
/**
 * 改进后快速排序：交换顺序表 L 中子表的记录, 使得枢轴确定其位置, 并返回坐标
 *              此时在枢轴左边的元素都不大于它, 在其右边的都不小于它
 * @param L 包含子表的顺序表 L
 * @param low 起始位置
 * @param high 结束位置
 * @return 枢轴位置
 */
int Partition1(SqList *L, int low, int high)
{
    /* 三位取中法, 即取三个关键字先进行排序, 将中间数作为枢轴, 一般是取左端、中间和右端三个数 */
    int middle = low + (high - low) / 2;  // 计算数组中间的元素下标
    if(L->r[low] > L->r[high])
        swap(L, low, high);  // 交换左端与右端数据, 保证左端较小
    if(L->r[middle] > L->r[high])
        swap(L, middle, high);  // 交换中间与右端数据, 保证中间较小
    if(L->r[low] < L->r[middle])
        swap(L, low, middle);  // 交换左端与中间数据, 保证中间最小, 左端居中

    int pivotkey = L->r[low];  // 将三位取中后的中间数作为枢轴记录
    L->r[0] = pivotkey;  // 将枢轴关键字保存在 L->r[0]
    while(low < high)  // 从表的两端交替向中间扫描
    {
        while(low < high && L->r[high] >= pivotkey)
            --high;
        L->r[low] = L->r[high];  // 采用替换而不是交换的方式进行操作
        while(low < high && L->r[low] <= pivotkey)
            ++low;
        L->r[high] = L->r[low];  // 采用替换而不是交换的方式进行操作
    }
    L->r[low] = L->r[0];  // 将枢轴数值替换回 L->r[low]
    return low;  // 返回枢轴下标
}

/**
 * 改进快速排序：大数据使用快速排序, 小数据量使用直接插入排序
 *             使用尾递归即迭代的方式减少递归深度
 * @param L 包含子表的顺序表 L
 * @param low  起始位置下标
 * @param high  结束位置下标
 */
void QSort1(SqList *L, int low, int high)
{
    if((high - low) >= MAX_LENGTH_INSERT_SORT)
    {
        while(low < high)
        {
            int pivot = Partition1(L, low, high);  /*  将L->r[low..high]一分为二，算出枢轴值pivot */
            QSort(L, low, pivot - 1);  /*  对低子表递归排序 */
            low = pivot + 1;  /* 尾递归 */
        }
    }
    else
        InsertSort(L);

}
/**
 * 改进快速排序驱动程序
 * @param L 包含子表的顺序表 L
 */
void QuickSort1(SqList *L)
{
    QSort1(L, 1, L->length);
}
/* **************************************** */


/* **************************************** */
#define N 9
int main()
{
    int i;

    int d[N]={9,1,5,8,3,7,4,6,2};
    /* int d[N]={9,8,7,6,5,4,3,2,1}; */

    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;

    for(i=0;i<N;i++)
        l0.r[i+1]=d[i];
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("排序前:\n");
    print(l0);

    printf("冒泡排序:\n");
    BubbleSort(&l1);
    print(l1);

    printf("选择排序:\n");
    SelectSort(&l3);
    print(l3);

    printf("直接插入排序:\n");
    InsertSort(&l4);
    print(l4);

    printf("希尔排序:\n");
    ShellSort(&l5);
    print(l5);

    printf("堆排序:\n");
    HeapSort(&l6);
    print(l6);

    printf("归并排序（递归）:\n");
    MergeSort(&l7);
    print(l7);

    printf("快速排序:\n");
    QuickSort(&l9);
    print(l9);

    printf("改进快速排序:\n");
    QuickSort1(&l10);
    print(l10);


    /*大数据排序*/
    /*
    srand(time(0));
    int Max=10000;
    int d[10000];
    int i;
    SqList l0;
    for(i=0;i<Max;i++)
        d[i]=rand()%Max+1;
    for(i=0;i<Max;i++)
        l0.r[i+1]=d[i];
    l0.length=Max;
    MergeSort(l0);
    print(l0);
    */
    return 0;
}