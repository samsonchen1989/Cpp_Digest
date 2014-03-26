#include "DList.h"

void dlist_init(DList *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    list->destroy = destroy;

    return;
}

void dlist_destroy(DList *list)
{
    void *data;

    if (list->size == 0) {
        return;
    }

    while (dlist_remove(list, dlist_tail(list), (void**)&data) == 0) {
        if (list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(DList));

    return;
}

int dlist_remove(DList *list, DListElmt *element, void **data)
{
    if (dlist_size(list) == 0 || element == NULL) {
        return -1;
    }

    //head node or not
    if (element == list->head) {
        DListElmt* nextElmt = element->next;
        if (nextElmt == NULL) {
            list->tail = NULL;
        } else {
            nextElmt->prev = NULL;
        }

        list->head = nextElmt;
    } else {
        DListElmt* nextElmt = element->next;
        DListElmt* prevElmt = element->prev;

        prevElmt->next = nextElmt;

        if (nextElmt == NULL) {
            list->tail = prevElmt;
        } else {
            nextElmt->prev = prevElmt;
        }
    }

    *data = element->data;
    free(element);

    list->size--;

    return 0;
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
    if (element == NULL && list->size != 0) {
        return -1;
    }

    DListElmt *newNode = (DListElmt*)malloc(sizeof(DListElmt));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;

    if (list->size == 0) {
        //insert as head
        newNode->next = NULL;
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = element;
        newNode->next = element->next;

        if (element == list->tail) {
            //element->next = newNode;
            list->tail = newNode;
        } else {
            element->next->pre = newNode;
            //element->next = newNode;
        }

        element->next = newNode;
    }

    list->size++;

    return 0;
}

int dlist_ins_pre(DList *list, DListElmt *element, const void *data)
{
    if (element == NULL && list->size != 0) {
        return -1;
    }

    DListElmt *newNode = (DListElmt*)malloc(sizeof(DListElmt));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = (void*)data;

    if (list->size == 0) {
        newNode->prev = NULL;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = element;
        newNode->prev = element->prev;

        if (element == list->head) {
            //element->prev = newNode;
            list->head = newNode;
        } else {
            element->prev->next = newNode;
            //element->prev = newNode;
        }

        element->prev = newNode;
    }

    list->size++;
    return 0;
}