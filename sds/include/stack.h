/*
 * stack.h
 *
 *  Created on: Dec 18, 2018
 *      Author: gustavo
 *
 *  Stack data structure
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>

typedef struct {
    void * array;
    uint16_t size;
    uint16_t index;
    uint8_t element_size;
} stack_t;

int16_t stack_init(stack_t * stack, void * array, uint16_t size, uint8_t element_size);
int16_t stack_push(stack_t * stack, void * data);
int16_t stack_pop(stack_t * stack, void * data);

void stack_print(stack_t * stack);

#endif /* STACK_H_ */
