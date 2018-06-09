#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode  /* 结点结构 */
{
    int data;           /* 结点数据 */
    struct BiTNode *lchild, *rchild;   /* 左右孩子指针 */
}BiTNode, *BiTree;

BiTNode* CreateBiTNode(int key)
{
    BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

/*
 * 递归查找二叉排序树 T 中是否存在 key, 指针 f 指向 T 的双亲, 其初始调用值是 NULL. 若查找成功, 则指针 p 指向该数据元素结点, 并返回 TRUE
 * 否则 指针 p 指向查找路径上访问的最后一个结点并返回 FALSE
 *
 */
Status SearchBST(BiTree T, int key, BiTNode *f, BiTNode **p)
{
    if(!T)  /* 查找不成功 */
    {
        *p = f;
        return FALSE;
    }
    else if(key == T->data)  /* 查找成功 */
    {
        *p = T;
        return TRUE;
    }
    else if(key < T->data)
        return SearchBST(T->lchild, key, T, p);  /* 在左子树中继续查找 */
    else
        return SearchBST(T->rchild, key, T, p);  /* 在右子树中继续查找 */
}

/*
 *
 * 当二叉排序树 T 中不存在关键字等于 key 的数据元素时, 插入 key 并返回 TRUE, 否则返回 FALSE
 *
 */
Status InsertBST(BiTree *T, int key)
{
    BiTNode *p, *s;
    if(!SearchBST(*T, key, NULL, &p))  /* 查找不成功 */
    {
        s = CreateBiTNode(key);
        if(!p)
            *T = s;  /* 插入 s 为新的根节点 */
        else if(key < p->data)
            p->lchild = s;  /* 插入 s 为左孩子 */
        else
            p->rchild = s;  /* 插入 s 为右孩子 */
        return TRUE;
    }
    return FALSE;  /* 树中已有关键字相同的结点, 不再插入 */
}

/*
 * 从二叉排序树中删除节点 p, 并重接它的左或右子树
 */
Status Delete(BiTNode **p)
{
    BiTNode *q, *s;
    if((*p)->lchild == NULL)  /* 若右子树为空，则只需重接它的左子树 */
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if((*p)->rchild == NULL)  /* 若左子树为空，则只需重接它的右子树 */
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else  /* 左右子树均不空 */
    {
        q = *p;
        s = (*p)->lchild;  /* s 为其左子树 */
        while(s->rchild)   /* 转左，寻找其左子树最右结点, 即寻找待删结点的前驱 */
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;  /* s 指向被删结点的直接前驱 */
        if(q != (*p))
            q->rchild = s->lchild;  /* 重接 q 的右子树 */
        else
            q->lchild = s->lchild;  /* 重接 q 的左子树 */
        free(s);
    }
    return TRUE;
}

/*
 * 若二叉排序树 T 中存在关键字等于 key 的数据元素时, 则删除该数据元素结点, 并返回 TRUE; 否则返回 FALSE.
 */
Status DeleteBST(BiTree *T, int key)
{
    if(!(*T))       /* 不存在关键字等于 key 的数据元素 */
        return FALSE;
    else if(key == (*T)->data)    /* 找到关键字等于 key 的数据元素 */
        return Delete(T);
    else if(key < (*T)->data)
        return DeleteBST(&(*T)->lchild, key);
    else
        return DeleteBST(&(*T)->rchild, key);
}

void PreOrder(BiTree T)
{
    if(T)
    {
        printf("%d ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if(T)
    {
        InOrder(T->lchild);
        printf("%d ", T->data);
        InOrder(T->rchild);
    }
}

int main() {

    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    BiTree T = NULL;

    for(int i = 0; i < 10; i++)
        InsertBST(&T, a[i]);

    printf("前序遍历： ");
    PreOrder(T);
    printf("\n");
    printf("中序遍历： ");
    InOrder(T);
    printf("\n");

    DeleteBST(&T, 73);
    InOrder(T);
    printf("\n");

    printf("Hello, World!\n");
    return 0;
}