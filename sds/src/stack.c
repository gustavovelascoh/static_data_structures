#include "stack.h"
#include "string.h"

int16_t stack_init(stack_t * stack, void * array, uint16_t size, uint8_t element_size){
    stack->array = array;
    stack->size = size;
    stack->element_size = element_size;
    stack->index = 0;

    return 0;
}

int16_t stack_push(stack_t * stack, void * data){
    int16_t ret = -1;
    if (stack->index < stack->size){
        memcpy(stack->array + (stack->index * stack->element_size), data, stack->element_size);
        stack->index++;
        ret = 0;
    }
    return ret;
}

int16_t stack_pop(stack_t * stack, void * data){
    int16_t ret = -1;
    if (stack->index > 0){
        stack->index--;
        memcpy(data, stack->array + (stack->index * stack->element_size), stack->element_size);
        ret = 0;
    }
    return ret;
}
