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
    ll->len = 0;
    ll->size = size;
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
    ll->len += 1;
    memcpy(prev->data, data, ll->element_size);
}

uint8_t ll_get_next(ll_t * ll, ll_node_t ** curr, ll_node_t ** next){
    uint8_t ret = LL_OK;

    printf("Current length: %d\n",ll->len);
    if (ll->len == 0){
        ret = LL_EMPTY;
    } else if (ll->len > ll->size){
        ret = LL_FULL;
    } else {
        if (curr == NULL){
            *next = ll->first;
        } else {
            *next = (ll_node_t *)(* curr)->next;

            if (*next == NULL){
                ret = LL_END;
            }
        }
    }
    return ret;
    //printf("B: curr: %p, next: %p\n", curr, next);
}

uint8_t ll_insert_next(ll_t * ll, ll_node_t * curr, void * data){
    uint8_t ret = LL_OK;
    ll_node_t * next;
    ll_node_t * new;

    if (ll->len < ll->size){
        stack_pop(ll->stack, &new);
        memcpy(new->data, data, ll->element_size);

        new->next = (struct ll_node_t *) curr->next;
        curr->next = (struct ll_node_t *) new;
        ll->len += 1;
    } else {
        ret = LL_FULL;
    }
}

void ll_delete_next(ll_t * ll, ll_node_t * curr){
    ll_node_t * next;
    ll_node_t * new_next;

    if (curr == NULL){
        next = (ll_node_t *) ll->first;
    }else {
        next = (ll_node_t *) curr->next;
    }

    new_next = (ll_node_t *) next->next;
    printf("next: %p, new_next: %p\n", next, new_next);
    if (next != NULL){
        stack_push(ll->stack, &(next));
        printf("PUSH'D\n");
        if (curr == NULL){
            ll->first = (ll_node_t *) new_next;
        } else{
            curr->next = (struct ll_node_t *) new_next;
        }
        ll->len -= 1;
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
    printf("length: %d\n", ll->len);
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
