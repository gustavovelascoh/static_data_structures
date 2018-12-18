#include "stack.h"

int16_t stack_init(stack_t * stack, void * array, uint16_t size){
    stack->array = array;
    stack->size = size;
    stack->index = 0;

    return 0;
}

int16_t stack_push(stack_t * stack, void * data){
    int16_t ret = -1;
    if (stack->index < stack->size){
        *(stack->array)[stack->index] = *data;
        stack->index++;
        ret = 0;
    }
    return ret;
}

int16_t stack_pop(stack_t * stack, void * data){
    int16_t ret = -1;
    if (stack->index > 0){
        *data = *(stack->array)[stack->index];
        return 0;
    }
    return ret;
}
