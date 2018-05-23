//
// Created by hao on 18-5-23.
//

#ifndef UDGADJMATRIXTRAVERSE_UDG_ADJ_MATRIX_H
#define UDGADJMATRIXTRAVERSE_UDG_ADJ_MATRIX_H

#include <stdio.h>
#include "circular_queue.h"

#define MAXVEX 100  // 最大顶点数
#define INFINIFY 65535  // 用 65535 代表无限大
#define TRUE 1
#define FALSE 0
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上的权值类型
typedef int Boolean;
Boolean visited[MAXVEX];

typedef struct
{
    VertexType vexs[MAXVEX];  // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵，可看做边表
    int numVertexes, numEdges;  // 图中当前的顶点数和边数
}MGraph;

/* 通过输入构建图的邻接矩阵结构 */
void CreateMGraph(MGraph *G);

/* 获取顶点坐标 */
int GetPosition(MGraph G, VertexType ch);

/* 创建示例图 */
void CreateMGraphExample(MGraph *G);

/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i);

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G);

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G);

#endif //UDGADJMATRIXTRAVERSE_UDG_ADJ_MATRIX_H
