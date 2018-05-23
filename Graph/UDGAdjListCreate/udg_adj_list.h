//
// Created by hao on 18-5-23.
//

#ifndef UDGADJLISTCREATE_UDG_ADJ_LIST_H
#define UDGADJLISTCREATE_UDG_ADJ_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define TRUE 1
#define FALSE 0
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;

typedef struct EdgeNode  /* 边表结点 */
{
    int adjvex;  /* 邻接点域，存储该顶点对顶的下标 */
    EdgeType weight;  /* 用于存储权值，对于非网图可以不需要 */
    struct EdgeNode *next;  /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;  /* 顶点域，存储顶点信息 */
    EdgeNode *firstedge;  /* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;  /* 图中当前顶点数和边数 */
}GraphAdjList;

Boolean visited[MAXVEX];

/* 通过输入创建图的邻接表结构 */
void CreateALGraph(GraphAdjList *G);

/* 获取顶点坐标 */
int GetPosition(GraphAdjList G, VertexType ch);

/* 通过输入创建示例图的邻接表结构 */
void CreateALGraphExample(GraphAdjList *G);

#endif //UDGADJLISTCREATE_UDG_ADJ_LIST_H
