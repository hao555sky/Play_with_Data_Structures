#include <stdio.h>
#include <string>
#include <stack>
#include <queue>

using std::string;
using std::stack;
using std::queue;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char TElemType;
typedef int Status;

string s;
int index = 0;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T)
{
    TElemType ch = s[index++];
    if(ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int BiTreeDepth(BiTree T)
{
    if(T == NULL)
        return 0;
    int left_depth = BiTreeDepth(T->lchild) + 1;
    int right_depth = BiTreeDepth(T->rchild) + 1;
    return left_depth > right_depth ? left_depth : right_depth;
}

/* 二叉树的前序遍历递归算法 */
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    printf("%c", T->data);  // 显示结点数据，可以更改为其他对结点的操作
    PreOrderTraverse(T->lchild);  // 再先序遍历左子树
    PreOrderTraverse(T->rchild);  // 最后先序遍历右子树
}

/* 二叉树的前序遍历非递归算法 */
void PreOrderTraverseNoRecursive(BiTree T)
{
    stack<BiTree> s;
    BiTree p = T;
    while(p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            printf("%c", p->data);
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

/* 二叉树的中序遍历递归算法 */
void InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(T->lchild);  // 中序遍历左子树
    printf("%c", T->data);  // 显示结点数据，可以更改为其他对结点的操作
    InOrderTraverse(T->rchild);  // 最后中序遍历右子树
}

/* 二叉树的中序非遍历递归算法 */
void InOrderTraverseNoRecursive(BiTree T)
{
    stack<BiTree> s;
    BiTree p = T;
    while(p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            printf("%c", p->data);
            p = p->rchild;
        }
    }
}

/* 二叉树的后序遍历递归算法 */
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    PostOrderTraverse(T->lchild);  // 先后序遍历左子树
    PostOrderTraverse(T->rchild);  // 再后序遍历右子树
    printf("%c", T->data);  // 显示结点数据，可以更改为其他对结点的操作
}

/* 二叉树的后序非遍历递归算法 */
void PostOrderTraverseNoRecursive(BiTree T)
{
    stack<BiTree> s, st;
    BiTree p;
    s.push(T);
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        st.push(p);
        if(p->lchild)
            s.push(p->lchild);
        if(p->rchild)
            s.push(p->rchild);
    }
    while(!st.empty())
    {
        printf("%c", st.top()->data);
        st.pop();
    }
}

/* 二叉树的层序遍历算法 */
void LevelOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    queue<BiTree> q;
    BiTree p;
    q.push(T);
    while(!q.empty())
    {
        p = q.front();
        printf("%c", p->data);
        q.pop();
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }
}

int main() {

    BiTree T;
    s = "ABDH#K###E##CFI###G#J##";
    CreateBiTree(&T);

    printf("\n树的深度:%d", BiTreeDepth(T));

    printf("\n前序递归遍历二叉树:");
    PreOrderTraverse(T);
    printf("\n前序非递归遍历二叉树:");
    PreOrderTraverseNoRecursive(T);

    printf("\n中序递归遍历二叉树:");
    InOrderTraverse(T);
    printf("\n中序非递归遍历二叉树:");
    InOrderTraverseNoRecursive(T);

    printf("\n后序递归遍历二叉树:");
    PostOrderTraverse(T);
    printf("\n后序非递归遍历二叉树:");
    PostOrderTraverseNoRecursive(T);

    printf("\n层次遍历二叉树:");
    LevelOrderTraverse(T);

    return 0;
}