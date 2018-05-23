//
// Created by hao on 18-5-23.
//

#include "udg_adj_list.h"

/* 通过输入创建图的邻接表结构 */
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);  /* 输入顶点数和边数 */
    for(i = 0; i < G->numVertexes; i++)  /* 读入顶点信息, 建立顶点表 */
    {
        scanf("%c", &G->adjList[i].data);  /* 输入顶点信息 */
        G->adjList[i].firstedge = NULL;  /* 将边表置为空表 */
    }
    for(k = 0; k < G->numEdges; k++)  /* 建立边表 */
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);  /* 输入边(vi,vj)上的顶点序号 */
        e = (EdgeNode*)malloc(sizeof(EdgeNode));  /* 向内存申请空间, 生成边表结点 */
        e->adjvex = j;  /* 邻接序号为 j */
        e->next = G->adjList[i].firstedge;  /* 将 e 指针指向当前顶点指向的结点 */
        G->adjList[i].firstedge = e;  /* 将当前顶点的指针指向 e */

        e = (EdgeNode *)malloc(sizeof(EdgeNode));  /* 向内存申请空间, 生成边表结点 */
        e->adjvex = i;  /* 邻接序号为 i */
        e->next = G->adjList[j].firstedge;  /* 将 e 指针指向当前顶点指向的结点 */
        G->adjList[j].firstedge = e;  /* 将当前顶点的指针指向 e */
    }
}

/* 获取顶点坐标 */
int GetPosition(GraphAdjList G, VertexType ch)
{
    for(int i = 0; i < G.numVertexes; i++)
        if(G.adjList[i].data == ch)
            return i;
    return -1;
}

/* 通过输入创建示例图的邻接表结构 */
void CreateALGraphExample(GraphAdjList *G)
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

    G->numVertexes = LENGTH(vexs);
    G->numEdges = LENGTH(arcs);
    for(int i = 0; i < G->numVertexes; i++)
    {
        G->adjList[i].data = vexs[i];
        G->adjList[i].firstedge = NULL;
    }

    for(int i = 0; i < G->numEdges; i++)
    {
        int p1 = GetPosition(*G, arcs[i][0]);
        int p2 = GetPosition(*G, arcs[i][1]);

        EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = p2;
        e->weight = 0;
        e->next = G->adjList[p1].firstedge;
        G->adjList[p1].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = p1;
        e->weight = 0;
        e->next = G->adjList[p2].firstedge;
        G->adjList[p2].firstedge = e;
    }
}