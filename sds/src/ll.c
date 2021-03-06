#include "ll.h"
#include <stdio.h>
#include <string.h>



void ll_init(ll_t * ll,
             ll_node_t * ll_node_a,
             void * ll_array,
             stack_t * stack,
             ll_node_t * s_array[],
             uint16_t size,
             uint8_t element_size){

    uint16_t i = 0;
    void * temp_ptr = NULL;

    ll->stack = stack;
    ll->first = 0x00;
    ll->element_size = element_size;
    ll->node_arr = ll_node_a;
    stack_init(ll->stack, s_array, size, sizeof(void *));

    for (i=0; i<size; i++){
        (&ll_node_a[i])->data = ll_array+(i*element_size);
        (&ll_node_a[i])->next = 0x00;
        temp_ptr = &(ll->node_arr[i]);
        stack_push(ll->stack, &temp_ptr);
    }

}

void ll_push(ll_t * ll, void * data){
    ll_node_t * current;
    ll_node_t * prev;

    prev = ll->first;
    current = ll->first;

    while (current != 0x00){
        prev = current;
        current = (ll_node_t *) current->next;
    }

    if (prev == 0x00 && current == 0x00){
        stack_pop(ll->stack, &(ll->first));
        prev = ll->first;
    }
    else{
        stack_pop(ll->stack, &(prev->next));
        prev = (ll_node_t *) prev->next;
    }
    memcpy(prev->data, data, ll->element_size);
}

void ll_get_next(ll_t * ll, ll_node_t ** curr, ll_node_t ** next){
    //printf("A: curr: %p, next: %p\n", curr, next);
    if (curr == NULL){
        *next = ll->first;
    }else {
        *next = (ll_node_t *)(* curr)->next;
    }
    //printf("B: curr: %p, next: %p\n", curr, next);
}

void ll_delete_next(ll_t * ll, ll_node_t * curr){
    ll_node_t * next;
    ll_node_t * new_next;

    if (curr == NULL){
        next = ll->first;

    }else {
        next = curr->next;
    }

    new_next = next->next;
    printf("next: %p, new_next: %p\n", next, new_next);
    if (next != NULL){
        stack_push(ll->stack, &(next));
        printf("PUSH'D\n");
        if (curr == NULL){
            ll->first = new_next;
        } else{
            curr->next = new_next;
        }
    }
}

void ll_traverse(ll_t * ll, cb_t cb){
    uint16_t cnt = 0;
    ll_node_t * current;
    ll_node_t * prev;

    prev = ll->first;
    current = ll->first;

    while (current != 0x00){
        prev = current;
        current = (ll_node_t *) current->next;

        if (cb){
            cb(prev->data);
        }

        cnt++;
    }
}

void ll_print(ll_t * ll){
    ll_node_t * current;
    uint16_t size = 0;
    ll_node_t * prev;

    prev = ll->first;

    printf("----- LINKED LIST @ %p -----\n", ll);
    printf("element_size: %d\n", ll->element_size);
    printf("node_arr: %p\n", ll->node_arr);
    printf("first node: %p\n", ll->first);
    printf("stack:\n");
    stack_print(ll->stack);

    current = ll->first;

    while (current != 0x00){
        prev = current;
        current = (ll_node_t *) current->next;

        printf("node %d: data at %p\n", size, prev->data);
        size++;
    }

    printf("length: %d\n",size-1);

    printf("-----    END     -----\n");
}
