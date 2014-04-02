#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <stdlib.h>

#include "bitree.h"
#include "list.h"

//preorder
int preorder(const BiTreeNode *node, List *list);

//inorder
int inorder(const BiTreeNode *node, List *list);

//postorder
int postorder(const BiTreeNode *node, List *list);

#endif