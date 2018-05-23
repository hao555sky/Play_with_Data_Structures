#include <stdio.h>
#include "udg_adj_matrix.h"

int main() {
    MGraph G;
    CreateMGraphExample(&G);

    DFSTraverse(G);

    printf("\n");

    BFSTraverse(G);
    printf("Hello, World!\n");
    return 0;
}