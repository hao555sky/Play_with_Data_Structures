#include <stdio.h>
#include "udg_adj_list.h"

int main() {
    GraphAdjList G;
    CreateALGraphExample(&G);

    DFSTraverse(G);

    printf("\n");

    BFSTraverse(G);
    return 0;
}