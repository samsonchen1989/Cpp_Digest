#include <string.h>
#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
    if (tree == NULL) {
        return;
    }

    tree->size = 0;
    tree->root = NULL;
    tree->compare = NULL;
    tree->destroy = destroy;
}

void bitree_destroy(BiTree *tree)
{
    //remove all the nodes from the tree
    bitree_rem_left(tree, NULL);

    //no operation are allowed now, clear the structure as a precaution
    memset(tree, 0, sizeof(BiTree));

    return;
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (tree == NULL) {
        return;
    }

    if (bitree_size(tree) == 0) {
        return;
    }

    if (node == NULL) {
        position = &(tree->root);
    } else {
        position = &(node->left);
    }

    //remove the nodes
    if (*position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL) {
            //call user-defined function to free dynamically allocated data
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        //adjust size of the tree to account for removed node
        tree->size--;
    }

    return;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (tree == NULL) {
        return;
    }

    if (bitree_size(tree) == 0) {
        return;
    }

    if (node == NULL) {
        *position = tree->root;
    } else {
        *position = node->right;
    }

    if (*position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL) {
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size--;
    }

    return;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *newLeftNode;
    BiTreeNode **position;

    if (tree == NULL) {
        return -1;
    }

    newLeftNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if(newLeftNode == NULL) {
        return -1;
    }

    newLeftNode->data = (void*)data;
    newLeftNode->left = NULL;
    newLeftNode->right = NULL;

    if (node == NULL) {
        if (tree->size != 0) {
            return -1;
        }

        position = &(tree->root);
    } else {
        if (node->left != NULL) {
            return -1;
        }

        position = &(node->left);
    }

    *position = newLeftNode;
    tree->size++;

    return 0;
}


int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *newRightNode;
    BiTreeNode **position;

    if (tree == NULL) {
        return -1;
    }

    newRightNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if(newRightNode == NULL) {
        return -1;
    }

    newRightNode->data = (void*)data;
    newRightNode->left = NULL;
    newRightNode->right = NULL;

    if (node == NULL) {
        if (tree->size != 0) {
            return -1;
        }

        position = &(tree->root);
    } else {
        if (node->right != NULL) {
            return -1;
        }

        position = &(node->right);
    }

    *position = newRightNode;
    tree->size++;

    return 0;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
    //initialize the merged tree
    bitree_init(merge, left->destroy);

    //insert the data for the root node of merged tree
    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    //merge two binary trees into a singlr binary tree
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);

    //adjust the size of the new binary tree
    merge->size = merge->size + bitree_size(left) + bitree_size(right);

    //do not let the original trees access the merged nodes
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}