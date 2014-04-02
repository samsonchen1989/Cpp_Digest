#include <stdio.h>
#include <stdlib.h>

#include "traverse.h"
#include "bitree.h"

static int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    List travelList;
    list_init(&travelList, NULL);

    BiTree tree;
    bitree_init(&tree, NULL);

    bitree_ins_left(&tree, NULL, (void*)(number));
    bitree_ins_left(&tree, bitree_root(&tree), (void*)(number + 1));
    bitree_ins_right(&tree, bitree_root(&tree), (void*)(number + 2));

    preorder(bitree_root(&tree), &travelList);

    ListElmt *node = list_head(&travelList);
    while (node != NULL) {
        printf("num:%d.\n", *((int*)(node->data)));
        node = node->next;
    }

    return 0;
}