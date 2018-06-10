#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

typedef int ElementType;

/* 平衡二叉树结构 */
typedef struct AVLTNode
{
    ElementType data;
    int height;  /* 高度 */
    struct AVLTNode *lchild, *rchild;
}AVLTNode, *AVLTree;

/*
 * 创建 AVL 树节点
 */
AVLTNode* CreateNode(ElementType data)
{
    AVLTNode *q = (AVLTNode*)malloc(sizeof(AVLTNode));
    q->data = data;
    q->height = 0;
    q->lchild = q->rchild = NULL;
    return q;
}

/*
 * 获取以 T 为根节点的子树的最大值
 */
AVLTNode* GetMax(AVLTree T)
{
    if(!T)
        return NULL;
    while(T->rchild)
        T = T->rchild;
    return T;
}

/*
 * 获取以 T 为根节点的子树的最小值
 */
AVLTNode* GetMin(AVLTree T)
{
    if(!T)
        return NULL;
    while(T->lchild)
        T = T->lchild;
    return T;
}

/*
 * 获取某结点为根节点的子树的高度
 */
int GetHeight(AVLTNode *p)
{
    return p == NULL ? 0 : p->height;
}

/*
 * LL 单旋, 单向右旋
 * 返回值: 旋转后的节点
 */
AVLTNode* LL_Rotate(AVLTNode *p)
{
    AVLTNode *q = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;

    p->height = MAX(GetHeight(p->lchild), GetHeight(p->rchild)) + 1;
    q->height = MAX(GetHeight(q->lchild), GetHeight(q->rchild)) + 1;

    return q;
}

/*
 * RR 单旋, 单向左旋
 * 返回值: 旋转后的节点
 */
AVLTNode* RR_Rotate(AVLTNode *p)
{
    AVLTNode *q = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;

    p->height = MAX(GetHeight(p->lchild), GetHeight(p->rchild)) + 1;
    q->height = MAX(GetHeight(q->lchild), GetHeight(q->rchild)) + 1;

    return q;
}

/*
 * LR双旋: 先左后右双向旋转
 * 返回值: 旋转后的节点
 */
AVLTNode* LR_Rotate(AVLTNode *p)
{
    p->lchild = RR_Rotate(p->lchild);
    return LL_Rotate(p);
}

/*
 * RL双旋: 先右后左双向旋转
 * 返回值： 旋转后的结点
 */
AVLTNode* RL_Rotate(AVLTNode *p)
{
    p->rchild = LL_Rotate(p->rchild);
    return RR_Rotate(p);
}

/*
 * 插入节点到 AVL 树中, 并返回根节点
 */
AVLTree Insert(AVLTree T, ElementType data)
{
    if(T == NULL)  /* 若树为空或找到插入值的位置 */
    {
        T = CreateNode(data);
        if(!T)
            return NULL;
    }
    else if(data < T->data)  /* 将节点插入到左子树 */
    {
        T->lchild = Insert(T->lchild, data);  /* 递归寻找插入节点位置 */
        if (GetHeight(T->lchild) - GetHeight(T->rchild) == 2)  /* 判断插入后左子树与右子树的平衡因子是否为 2 */
        {
            if (data < T->lchild->data)  /* 表示插入到第一个失衡根节点的左子树的左子树上 */
                T = LL_Rotate(T);
            else                         /* 表示插入到第一个失衡根节点的左子树的右子树上 */
                T = LR_Rotate(T);
        }
    }
    else if(data > T->data)  /* 将节点插入到右子树 */
    {
        T->rchild = Insert(T->rchild, data);  /* 递归寻找插入节点位置 */
        if (GetHeight(T->rchild) - GetHeight(T->lchild) == 2)  /* 判断插入后左子树与右子树的平衡因子是否为 -2 */
        {
            if (data > T->rchild->data)  /* 表示插入到第一个失衡根节点的右子树的右子树上 */
                T = RR_Rotate(T);
            else                         /* 表示插入到第一个失衡根节点的右子树的左子树上 */
                T = RL_Rotate(T);
        }
    }
    else
        printf("Fail to insert the same node!");

    T->height = MAX(GetHeight(T->lchild), GetHeight(T->rchild)) + 1;
    return T;
}

/*
 * 查找某个值, 返回该结点
 */
AVLTNode* Search(AVLTree T, ElementType data)
{
    if(!T || data == T->data)
        return T;
    else if(data < T->data)
        return Search(T->lchild, data);
    else
        return Search(T->rchild, data);
}

/*
 * 删除某个值
 */
AVLTree Delete(AVLTree T, ElementType data)
{
    /* 判断 T 是否为空 */
    if(T == NULL)
        return NULL;
    else if(data < T->data)  // 若删除的值小于当前结点所指向的值
    {
        T->lchild = Delete(T->lchild, data);  // 在左子树中递归查找要删除的值所在的结点
        if(GetHeight(T->rchild) - GetHeight(T->lchild) == 2)  // 删除节点后, 判断结点是否失衡, 即平衡因子是否为 -2
        {
            AVLTNode *rchild = T->rchild;
            /* 比较以当前结点右子树为根节点的子树的高度, 判断应该采用哪种旋转类型 */
            if(GetHeight(rchild->rchild) > GetHeight(rchild->lchild))
                T = RR_Rotate(T);
            else
                T = RL_Rotate(T);
        }
    }
    else if(data > T->data)  // 若删除的值小于当前结点所指向的值
    {
        T->rchild = Delete(T->rchild, data);  // 在右子树中递归查找要删除的值所在的结点
        if(GetHeight(T->lchild) - GetHeight(T->rchild) == 2)  // 删除节点后, 判断结点是否失衡, 即平衡因子是否为 2
        {
            AVLTNode *lchild = T->lchild;
            /* 比较以当前结点左子树为根节点的子树的高度, 判断应该采用哪种旋转类型 */
            if(GetHeight(lchild->lchild) > GetHeight(lchild->rchild))
                T = LL_Rotate(T);
            else
                T = LR_Rotate(T);
        }
    }
    else // 找到删除节点
    {
        if(T->lchild && T->rchild)  /* 左右子树均不空 */
        {
            // 若左子树高度高于右子树, 则选取待删除节点的前驱节点取代待删除节点
            if(GetHeight(T->lchild) > GetHeight(T->rchild))
            {
                AVLTNode *tmp = GetMax(T->lchild);
                T->data = tmp->data;
                T->lchild = Delete(T->lchild, tmp->data);
            }
            else  // 否则选取待删除节点的后继节点取代待删除节点
            {
                AVLTNode *tmp = GetMin(T->rchild);
                T->data = tmp->data;
                T->rchild = Delete(T->rchild, tmp->data);
            }
        }
        else  // 若待删除节点只有左子树或右子树, 或为叶子节点
        {
            AVLTNode *tmp = T;
            T = T->lchild != NULL ? T->lchild : T->rchild;
            free(tmp);
        }
    }
    return T;
}

/*
 * 前序递归遍历
 */
void PreOrder(AVLTree T)
{
    if(T)
    {
        printf("%d ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*
 * 中序递归遍历
 */
void InOrder(AVLTree T)
{
    if(T)
    {
        InOrder(T->lchild);
        printf("%d ", T->data);
        InOrder(T->rchild);
    }
}

int main() {

    int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9}, ilen = LENGTH(arr);
    AVLTree tree = NULL;

    printf("== 高度: %d\n", GetHeight(tree));

    printf("== 依次添加: ");
    for(int i = 0; i < ilen; i++)
        tree = Insert(tree, arr[i]);

    printf("\n== 前序遍历: ");
    PreOrder(tree);
    printf("\n== 中序遍历: ");
    InOrder(tree);
    printf("\n");


    printf("== 高度: %d\n", GetHeight(tree));
    printf("== 最小值: %d\n", GetMin(tree)->data);
    printf("== 最大值: %d\n", GetMax(tree)->data);
    printf("== 树的详细信息: \n");

    int i = 12;
    printf("\n== 删除根节点: %d", i);
    tree = Delete(tree, i);
    printf("\n== 高度: %d\n", GetHeight(tree));
    printf("\n== 前序遍历: ");
    PreOrder(tree);
    printf("\n== 中序遍历: ");
    InOrder(tree);
    printf("\n");

    return 0;
}