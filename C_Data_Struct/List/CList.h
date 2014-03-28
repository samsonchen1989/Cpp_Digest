#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

//define a struct for circular list elements
typedef struct CListElemt_
{
    void *data;
    struct CListElemt_ *next;
}CListElemt;

//define a struct for circular list
typedef struct CList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    CListElemt *head;
}CList;

//public interface
void clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, CListElemt *element, const void *data);
int clist_rem_next(CList *list, CListElemt *element, void **data);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next) 

#endif