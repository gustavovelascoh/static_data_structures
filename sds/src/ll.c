#include "ll.h"
#include <stdio.h>
#include <string.h>

void ll_init(ll_t * ll,
             ll_node_t * ll_node_a,
             void * ll_array,
             stack_t * stack,
             void * s_array,
             uint16_t size,
             uint8_t element_size){

    uint16_t i = 0;

    ll->stack = stack;
    ll->first = 0x00;
    ll->element_size = element_size;
    ll->node_arr = ll_node_a;
    stack_init(ll->stack, s_array, size, sizeof(void *));

    for (i=0; i<size; i++){
        (&ll_node_a[i])->data = ll_array+(i*element_size);
        (&ll_node_a[i])->next = 0x00;
        stack_push(ll->stack, ll_node_a+(i*sizeof(ll_node_t)));
    }

}

void ll_push(ll_t * ll, void * data){
    ll_node_t * current;
    ll_node_t * prev;

    prev = ll->first;
    current = ll->first;

    while (current != 0x00){
        prev = current;
        current = current->next;
    }

    printf("prev %p, curr: %p\n",prev, current);
    if (prev == 0x00 && current == 0x00){
        printf("xx");
        stack_pop(ll->stack, ll->first);
    }
    else{
        printf("dd");
        stack_pop(ll->stack, prev->next);
    }
    printf("prev %p\n",prev);
    memcpy(prev->data, data, ll->element_size);
}

void ll_print(ll_t * ll){
    ll_node_t * current;
    uint16_t size = 0;

    printf("----- LINKED LIST @ %p -----\n", ll);
    printf("element_size: %d\n", ll->element_size);
    printf("node_arr: %p\n", ll->node_arr);
    printf("first: %p\n", ll->first);
    printf("stack:\n");
    stack_print(ll->stack);

    current = ll->first;

    while (current != 0x00){

    }

    printf("length: %d\n",size);

    printf("-----    END     -----\n");
}
