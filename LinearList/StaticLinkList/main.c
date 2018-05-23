#include "static_link_list.h"
#include <stdio.h>

int main() {
    StaticLinkList L;
    Status i;
    i = InitList(L);
    printf("初始化L后：L.length=%d\n",ListLength(L));

    i = ListInsert(L, 1, 'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    ListTraverse(L);

    i=ListInsert(L,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    ListTraverse(L);

    i=ListDelete(L,1);
    printf("\n在L的删除“A”后：\nL.data=");
    ListTraverse(L);

    printf("\n");
    return 0;
}