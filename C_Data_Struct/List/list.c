#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_init(List *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = NULL;
    list->head = NULL;
    list->tail = NULL;

    return;
}

void list_destroy(List *list)
{
    void *data;
    while (list_size(list) != 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 &&
            list->destroy != NULL) {
            list->destroy(data);
        }
    }
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element;
    new_element = (ListElmt*)malloc(sizeof(ListElmt));

    if (new_element == NULL) {
        return -1;
    }

    new_element->data = (void *)data;

    if (element == NULL) {
        //insert at the head of the list
        new_element->next = list->head;
        list->head = new_element;

        if (list_size(list) == 0) {
            list_tail = new_element;
        }
    } else {
        new_element->next = element->next;
        element->next = new_element;

        if (element->next == NULL) {
            list->tail = new_element;
        }
    }

    (list->size)++;

    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element;

    if (list_size(list) == 0) {
        return -1;
    }

    if (element == NULL) {
        //remove from the head of the list
        *data = list->head->data;
        old_element = list->head;
        list->head = old_element->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        if (element->next == NULL) {
            return -1;
        }

        *data = element->next->data;
        old_element = element->next;
        element->next = old_element->next;

        if (element->next == NULL) {
            list->tail = element;
        }
    }

    free(old_element);

    list->size--;
    return 0;
}
