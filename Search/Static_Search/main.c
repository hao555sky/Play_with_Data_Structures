#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100  /* 存储空间初始分配量 */

typedef int Status;  /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

int F[100];  // 斐波那契数列

/* 无哨兵顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 */
int Sequential_Search(int *a, int n, int key)
{
    for(int i = 1; i <= n; i++)
        if(a[i] == key)
            return i;
    return 0;
}

/* 有哨兵顺序查找 */
int Sequential_Search2(int *a, int n, int key)
{
    int i = n;  /* 循环从数组尾部开始 */
    a[0] = key;  /* 设置 a[0] 为关键字值，我们称之为 哨兵 */
    while(a[i] != key)
        i--;
    return i;  /* 返回 0 则说明查找失败 */
}

/* 折半查找 */
int Binary_Search(int *a, int n, int key)
{
    int low = 1, high = n, middle;  // 此处元素区间为 [1, n], 也可以使用 [0, n - 1]
    while(low <= high)
    {
        middle = low + (high - low) / 2;  // 寻找中间位置， 不使用 (middle = low + high) / 2 原因是可能溢出
        if(a[middle] < key)   // 若查找值比中位数大
            low = middle + 1;
        else if(a[middle] > key)  // 若查找值比中位数小
            high = middle - 1;
        else
            return middle;  /* 若相等则说明 middle 即为查找到的位置 */
    }
    return 0;
}

/* 插值查找 */
int Interpolation_Search(int *a, int n, int key)
{
    int low = 1, high = n, middle;
    while(a[low] != a[high] && key >= a[low] &&  key <= a[high])  // 此处判断条件是为了防止 key - a[low] 为负值的情况
    {
        middle = low +  (high - low) * (key - a[low]) / (a[high] - a[low]);
        if(key > a[middle])
            low = middle + 1;
        else if(key < a[middle])
            high = middle - 1;
        else
            return middle;
    }
    if(key == a[low]) return low;  // 如果是2, 2, 2, 2这种全部重复元素，就不会上面的循环，为了防止 key - a[low] 为 0 的情况，则此处处理该情况，返回第一个 2
    return 0;
}

/* 斐波那契查找 */
int Fibonacci_Search(int *a, int n, int key)
{
    int low = 1, high = n, k = 0, middle;
    while (n > F[k] - 1)  /* 计算 n 处于斐波那契数列的位置 */
        k++;
    for(int i = n; i < F[k] - 1; i++)  /* 填充数组，使其长度为斐波那契数列的最大值 */
        a[i] = a[n];
    while(low <= high)
    {
        middle = low + F[k - 1] - 1;  /* 计算当前分隔的下标 */
        if(key < a[middle])   /* 若当前查找记录小于当前分隔记录 */
        {
            high = middle - 1;   /* 排除右半边的元素 */
            k = k - 1;   /* F[k - 1] 是左半边的长度 */
        }
        else if(key > a[middle])  /* 若查找记录大于当前分隔记杀 */
        {
            low = middle + 1;   /* 排除左半边的元素 */
            k = k - 2;   /* F[k - 2] 是右半边的长度 */
        }
        else{
            if(middle <= n)  /* 若相等则说明 mid 即为查找到的位置 */
                return middle;
            else
                return n;   /* 若 middle > n 说明是补全数值，返回 n */
        }
    }
    return 0;
}


int main() {

    int a[MAXSIZE + 1], i, result;
    int arr[MAXSIZE] = {0,1,16,24,35,47,59,62,73,88,99};
    int arr2[MAXSIZE] = {0,2,2,2,2,2,2,2,2,2,2};
    for(i=0;i<=MAXSIZE;i++)
    {
        a[i]=i;
    }

    result=Sequential_Search(a,MAXSIZE,MAXSIZE);
    printf("Sequential_Search:%d \n",result);

    result=Sequential_Search2(a,MAXSIZE,1);
    printf("Sequential_Search2:%d \n",result);

    result=Binary_Search(arr,10,62);
    printf("Binary_Search:%d \n",result);

    result=Interpolation_Search(arr,10,-50);
    printf("Interpolation_Search:%d \n",result);

    F[0] = 0;
    F[1] = 1;
    for(i = 2; i < 100; i++)
        F[i] = F[i - 1] + F[i - 2];
    result=Fibonacci_Search(arr,10,62);
    printf("Fibonacci_Search:%d \n",result);


    printf("Hello, World!\n");
    return 0;
}