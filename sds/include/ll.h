/*
 * ll.h
 *
 *  Created on: Dec 26, 2018
 *      Author: gustavo
 *
 *  Linked List data structure
 */

#ifndef LL_H_

#include <stdint.h>
#include "stack.h"

typedef void (* cb_t)(void *);

typedef struct{
    void * data;
    struct ll_node_t * next;
} ll_node_t;

typedef struct {
    stack_t * stack;
    ll_node_t * first;
    ll_node_t * node_arr;
    uint8_t element_size;
} ll_t;

void ll_init(ll_t * ll,
             ll_node_t * ll_node_a,
             void * ll_array,
             stack_t * stack,
             void * s_array,
             uint16_t size,
             uint8_t element_size);

void ll_push(ll_t * ll, void * data);
void ll_traverse(ll_t * ll, cb_t cb);
void ll_print(ll_t * ll);

#endif /* LL_H_ */
