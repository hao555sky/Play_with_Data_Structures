#include <stdio.h>

#define MAXVEX 9
#define INF 65535

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];
typedef int VertexType;

typedef struct
{
    VertexType vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
    int i, j;
    G->numEdges = 16;
    G->numVertexes = 9;
    for(i = 0; i < G->numVertexes; i++)
        G->vexs[i] = i;

    for(i = 0; i < G->numVertexes; i++)
    {
        for(j = 0; j < G->numVertexes; j++)
        {
            if(i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = G->arc[j][i] = INF;
        }
    }
    G->arc[0][1]=1;
    G->arc[0][2]=5;
    G->arc[1][2]=3;
    G->arc[1][3]=7;
    G->arc[1][4]=5;

    G->arc[2][4]=1;
    G->arc[2][5]=7;
    G->arc[3][4]=2;
    G->arc[3][6]=3;
    G->arc[4][5]=3;

    G->arc[4][6]=6;
    G->arc[4][7]=9;
    G->arc[5][7]=5;
    G->arc[6][7]=2;
    G->arc[6][8]=7;

    G->arc[7][8]=4;


    for(i = 0; i < G->numVertexes; i++)
    {
        for(j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] =G->arc[i][j];
        }
    }

}

/* Dijkstra算法， 求有向网 G 的 v0 顶点到其余顶点 v 最短路径 P[v] 及带权长度 D[v], P[v] 的值为前驱顶点下标,
 * D[v] 表示 v0 到 v 的最短路径长度和 */
void ShortestPath_Dijkstra(MGraph G, int v0, ShortPathTable *D, Patharc *P)
{
    int min, k, final[MAXVEX];  /* final[w] = 1 表示求得顶点 v0 至 vw 的最短路径 */
    for(int v = 0; v < G.numVertexes; v++)  /* 初始化数据 */
    {
        final[v] = 0;     /* 全部顶点初始化为未知最短路径状态 */
        (*D)[v] = G.arc[v0][v];   /* 将与 v0 顶点有连线的顶点加上权值 */
        (*P)[v] = -1;     /* 初始化路径数组 P 为 0 */
    }
    final[v0] = 1;   /* v0 至 v0 不需要求路径 */
    (*D)[v0] = 0;    /* v0 至 v0 路径为 0 */

    /* 开始主循环, 每次求得 v0 到某个 v 顶点的最短路径 */
    for(int v = 1; v < G.numVertexes; v++)
    {
        min = INF;   /* 当前所知离 v0 顶点的最近距离 */
        for(int w = 0; w < G.numVertexes; w++)   /* 寻找离 v0 最近的顶点 */
        {
            if(!final[w] && (*D)[w] < min)
            {
                min = (*D)[w];    /* w 顶点离 v0 顶点更近 */
                k = w;
            }
        }
        final[k] = 1;   /* 将目前找到的最近的顶点置为 1 */
        for(int w = 0; w < G.numVertexes; w++)   /* 更新当前最短路径及距离 */
        {
            /* 如果经过 v 顶点的路径比现在这条路径的长度短的话 */
            if(!final[w] && (min + G.arc[k][w]) < (*D)[w])
            {
                /* 说明找到了更短的路径, 修改 D[w] 和 P[w] */
                (*D)[w] = min + G.arc[k][w];   /* 修改当前路径长度 */
                (*P)[w] = k;
            }
        }
    }
}

int main() {
    int i, j, v0;
    MGraph G;
    Patharc P;
    ShortPathTable  D;
    v0 = 0;

    CreateMGraph(&G);

    ShortestPath_Dijkstra(G, v0, &D, &P);

    for(i  = 1; i < G.numVertexes; i++)
    {
        printf("v%d - v%d : ",v0,i);
        j = i;
        while(P[j] != -1)
        {
            printf("%d ",P[j]);
            j = P[j];
        }
        printf("\n");
    }
    for(i=1;i<G.numVertexes;++i)
        printf("v%d - v%d : %d \n",G.vexs[0],G.vexs[i],D[i]);
    return 0;
}