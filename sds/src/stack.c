#include "stack.h"
#include "string.h"
#include <stdio.h>

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

void stack_print(stack_t * stack){
    uint16_t i = 0;
    printf("----- STACK @ %p -----\n", stack);
    printf("index: %d\n", stack->index);
    printf("element_size: %d\n", stack->element_size);
    printf("\n");

    for (i=stack->size; i>0;--i){
        printf("%04d\t%p\n", i-1, stack->array+((i-1)*stack->element_size));
    }
    printf("-----   END  -----\n");
}
