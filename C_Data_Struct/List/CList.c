#include <string.h> //memset
#include "CList.h"

void clist_init(CList *list, void (*destroy)(void *data))
{
    if (list == NULL) {
        return;
    }

    list->size = 0;
    list->head = NULL;
    list->destroy = destroy;
}

void clist_destroy(CList *list)
{
    void *data;

    if (list == NULL) {
        return;
    }

    while(clist_rem_next(list, NULL, (void**)&data) == 0) {
        if (list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0x00, sizeof(CList));

    return;
}

int clist_rem_next(CList *list, CListElemt *element, void **data)
{
    if (list == NULL) {
        return -1;
    }

    if (list->size <= 0 || element == NULL) {
        return -1;
    }

    CListElemt *nextElemt = element->next;
    *data = nextElemt->data;

    if (nextElemt == element) {
        list->head = NULL;
    } else {
        element->next = nextElemt->next;
        //if remove head, set old head's next elem
        //to new head
        if(nextElemt == clist_head(list)) {
            list->head = nextElemt->next;
        }
    }

    free(nextElemt);

    list->size--;

    return 0;
}

int clist_ins_next(CList *list, CListElemt *element, const void *data)
{
    if (list == NULL) {
        return -1;
    }

    CListElemt *newElemt = (CListElemt*)malloc(sizeof(CListElemt));
    if (newElemt == NULL) {
        return -1;
    }

    newElemt->data = (void*)data;
    
    //if list is empty, add new elem and
    //set its next node to itself
    if (list->size == 0) {
        newElemt->next = newElemt;
        list->head = newElemt;
    } else {
        newElemt->next = element->next;
        element->next = newElemt;
    }

    list->size++;

    return 0;
}