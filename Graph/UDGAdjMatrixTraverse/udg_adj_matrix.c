//
// Created by hao on 18-5-23.
//

#include "udg_adj_matrix.h"

/* 通过输入构建图 */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d%d", &G->numVertexes, &G->numEdges);  /* 输入顶点数和边数 */
    getchar();
    for(i = 0; i < G->numVertexes; i++)  /* 读入顶点信息,建立顶点表 */
        scanf("%c", &G->vexs[i]);

    for(i = 0; i < G->numVertexes; i++)
        for(j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINIFY;  /* 邻接矩阵初始化 */
    for(k = 0; k < G->numEdges; k++)  /* 读入numEdges条边，建立邻接矩阵 */
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w);  /* 输入边(vi,vj)上的权w */
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];  /* 因为是无向图，矩阵对称 */
    }
}

/* 获取顶点坐标 */
int GetPosition(MGraph G, VertexType ch)
{
    for(int i = 0; i < G.numVertexes; i++)
        if(G.vexs[i] == ch)
            return i;
    return -1;
}

/* 创建示例图 */
void CreateMGraphExample(MGraph *G)
{
    VertexType vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I'};  /* 顶点集合 */
    VertexType arcs[][2] = {  /* 边集合 */
            {'A', 'B'},
            {'A', 'F'},
            {'B', 'C'},
            {'B', 'G'},
            {'B', 'I'},
            {'C', 'D'},
            {'C', 'I'},
            {'D', 'E'},
            {'D', 'G'},
            {'D', 'H'},
            {'D', 'I'},
            {'E', 'F'},
            {'E', 'H'},
            {'F', 'G'},
            {'G', 'H'}
    };
    G->numVertexes = LENGTH(vexs);  /* 顶点数目 */
    G->numEdges = LENGTH(arcs);   /* 边数目 */
    for(int i = 0; i < G->numVertexes; i++)  /* 通过定义好的顶点集, 建立顶点表 */
        G->vexs[i] = vexs[i];
    for(int i = 0; i < G->numVertexes; i++)  /* 邻接矩阵初始化 */
    {
        for(int j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINIFY;
    }
    for(int i = 0; i < G->numEdges; i++)  /* 建立邻接矩阵 */
    {
        int p1 = GetPosition(*G, arcs[i][0]);
        int p2 = GetPosition(*G, arcs[i][1]);
        G->arc[p1][p2] = G->arc[p2][p1] = 1;  /* 边(p1,p2), 权值为 1. 无向图，矩阵对称 */
    }
}

/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i)
{
    printf("%c ", G.vexs[i]);  /* 打印顶点, 也可以是其他操作 */
    visited[i] = TRUE;
    for(int j = 0; j < G.numVertexes; j++)
    {
        if(!visited[j] && G.arc[i][j] == 1)
            DFS(G, j);                      /* 对未访问的邻接顶点递归调用 */
    }
}

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G)
{
    for(int i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;                /* 初始所有顶点状态都是未访问过状态 */
    for(int i = 0; i < G.numVertexes; i++)
        if(!visited[i])                    /* 对未访问过的顶点调用 DFS, 若是连通图，只会执行一次 */
            DFS(G, i);
}

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G)
{
    SqQueue Q;
    for(int i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);  /* 初始化辅助用的队列 */
    for(int i = 0; i < G.numVertexes; i++)  /* 对每一个顶点做循环 */
    {
        if(!visited[i])        /* 若是未访问过就处理 */
        {
            EnQueue(&Q, i);    /* 将此顶点入队 */
            visited[i] = TRUE;  /* 设置访问状态为TRUE */
            printf("%c ", G.vexs[i]);  /* 打印顶点, 也可以是其他操作 */
            while (!QueueEmpty(Q))    /* 若当前队列不为空 */
            {
                DeQueue(&Q, &i);      /* 将队中元素出队, 赋值给 i */
                for (int j = 0; j < G.numVertexes; j++)
                {
                    if (G.arc[i][j] == 1 && !visited[j])  /* 判断其他顶点若与当前顶点存在边且未访问过 */
                    {
                        EnQueue(&Q, j);      /* 将符合条件的顶点入队 */
                        printf("%c ", G.vexs[j]);  /* 打印顶点 */
                        visited[j] = TRUE;  /* 将符合条件的顶点标记为已访问 */
                    }
                }
            }
        }
    }
}