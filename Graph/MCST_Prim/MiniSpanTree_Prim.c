#include <stdio.h>

#define MAXVEX 10
#define TRUE 1
#define FALSE 0
#define INF 65535
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

typedef char VertexType;

typedef struct
{
    VertexType vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraphExample(MGraph *G)
{
    VertexType vexs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int arc[][9] = {
            {0, 10, INF, INF, INF, 11, INF, INF, INF},
            {10, 0, 18, INF, INF, INF, 16, INF, 12},
            {INF, 18, 0, 22, INF, INF, INF, INF, 8},
            {INF, INF, 22, 0, 20, INF, INF, 16, 21},
            {INF, INF, INF, 20, 0, 26, INF, 7, INF},
            {11, INF, INF, INF, 26, 0, 17, INF, INF},
            {INF, 16, INF, INF, INF, 17, 0, 19, INF},
            {INF, INF, INF, 16, 7, INF, 19, 0, INF},
            {INF, 12, 8, 21, INF, INF, INF, INF, 0}
    };

    G->numVertexes = LENGTH(vexs);
    G->numEdges = 0;

    for(int i = 0; i < G->numVertexes; i++)
        G->vexs[i] = vexs[i];
    for(int i = 0; i < G->numVertexes; i++)
    {
        for(int j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = arc[i][j];
        }
    }

    for(int i = 0; i < G->numVertexes; i++)
    {
        for(int j = 0; j < G->numVertexes; j++)
        {
            if(i != j && G->arc[i][j] != INF)
            {
                G->numEdges++;
            }
        }
    }

    printf("%d %d\n", G->numVertexes, G->numEdges / 2);

}

void CreateMGraph(MGraph *G)/* 构件图 */
{
    int i, j;

    /* printf("请输入边数和顶点数:"); */
    G->numEdges=15;
    G->numVertexes=9;

    for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
    {
        for ( j = 0; j < G->numVertexes; j++)
        {
            if (i==j)
                G->arc[i][j]=0;
            else
                G->arc[i][j] = G->arc[j][i] = INF;
        }
    }

    G->arc[0][1]=10;
    G->arc[0][5]=11;
    G->arc[1][2]=18;
    G->arc[1][8]=12;
    G->arc[1][6]=16;
    G->arc[2][8]=8;
    G->arc[2][3]=22;
    G->arc[3][8]=21;
    G->arc[3][6]=24;
    G->arc[3][7]=16;
    G->arc[3][4]=20;
    G->arc[4][7]=7;
    G->arc[4][5]=26;
    G->arc[5][6]=17;
    G->arc[6][7]=19;

    for(i = 0; i < G->numVertexes; i++)
    {
        for(j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] =G->arc[i][j];
        }
    }

}

/* Prim 算法生成最小生成树 */
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k;  // min 为当前权值最小值
    int lowcost[MAXVEX];  /* 保存顶点间边的权值 */
    int adjvex[MAXVEX];   /* 保存相关顶点的下标，即下标与其值所连边为当前最小权值边 */
    lowcost[0] = 0;  /* 选取第一个顶点为起始点， 即 v0 加入树， lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */
    adjvex[0] = 0;   /* 初始化第一个顶点下标为0 */
    for(i = 1; i < G.numVertexes; i++)  /* 循环除下标为 0 外的全部顶点 */
    {
        lowcost[i] = G.arc[0][i];  /* 将与 v0 顶点有边的权值存入数组 */
        adjvex[i] = 0;  /* 将其他所有顶点的值初始化为 v0 的下标 */
    }
    for(i = 1; i < G.numVertexes; i++)
    {
        min = INF;   /* 初始化最小权值为 无穷大 */
        j = 1, k = 0;
        while(j < G.numVertexes)  /* 循环全部顶点，寻找当前最小生成树顶点集合中最小权值的边 */
        {
            if(lowcost[j] != 0 && lowcost[j] < min)  /* 如果权值不为 0(即不在树中), 且权值小于 min */
            {
                min = lowcost[j];  /* 则让当前权值成为最小值 */
                k = j;             /* 将当前最小值的下标存入k */
            }
            j++;
        }
        lowcost[k] = 0;  /* 将当前顶点的权值设置为0, 表示此顶点已加入树的顶点集合 */
        printf("(%d, %d)", adjvex[k], k);  /* 打印当前顶点边中权值最小的边 */
        for(j = 1; j < G.numVertexes; j++)  /* 循环所有顶点 */
        {
            /* 如果下标为 k 的顶点边集中权值小于已存在的权值, 比如 (v0, v6)权值为INF, 而(v1, v6)权值为 16， 更新*/
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];  /* 将较小的权值存入 lowcost 相应位置 */
                adjvex[j] = k;   /* 将下标为 k 的顶点存入 adjvex */
            }
        }
    }
}

int main() {
    MGraph G;
    CreateMGraphExample(&G);
//    CreateMGraph(&G);
    MiniSpanTree_Prim(G);
    printf("Hello, World!\n");
    return 0;
}