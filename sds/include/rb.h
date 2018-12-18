/*
 * rb.h
 *
 *  Created on: Mar 27, 2017
 *      Author: gustavo
 *
 *  Ring Buffer data structure
 */

#ifndef RB_H_
#define RB_H_

#include <stdint.h>

typedef struct
{
    uint16_t element_size;
    uint16_t length;
    void * buffer;
} rb_attr_t;

typedef struct
{
    uint16_t element_size;
    uint16_t length;
    void * buffer;
    uint8_t head;
    uint8_t tail;
} rb_t;

void rb_init(rb_t * rb, rb_attr_t * rb_attr);
static uint8_t rb_full(rb_t * rb);
uint8_t rb_empty(rb_t * rb);
int8_t rb_put(rb_t * rb, const void *data);
int8_t rb_get(rb_t * rb, void *data);
void rb_flush(rb_t * rb);

#endif /* RB_H_ */
