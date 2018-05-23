//
// Created by hao on 18-5-23.
//

#ifndef UDGADJMATRIXCREATE_UDG_ADJ_MATRIX_H
#define UDGADJMATRIXCREATE_UDG_ADJ_MATRIX_H

#include <stdio.h>

#define MAXVEX 100  // 最大顶点数
#define INFINIFY 65535  // 用 65535 代表无限大
#define TRUE 1
#define FALSE 0
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上的权值类型

typedef struct
{
    VertexType vexs[MAXVEX];  // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵，可看做边表
    int numVertexes, numEdges;  // 图中当前的顶点数和边数
}MGraph;

void CreateMGraph(MGraph *G);

int GetPosition(MGraph G, VertexType ch);

void CreateMGraphExample(MGraph *G);

#endif //UDGADJMATRIXCREATE_UDG_ADJ_MATRIX_H
