#include "stack.h"

int stack_push(Stack *stack, const void *data)
{
    //push the data onto the stack/list top/head
    return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data)
{
    //pop the head data
    return list_rem_next(stack, NULL, data);
}