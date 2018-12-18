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

#define RB_NO_ERROR     0
#define RB_ERROR        -1
#define RB_OVERWRITE    -2
#define RB_EMPTY        -3


typedef struct
{
    uint16_t element_size;
    uint16_t length;
    void * buffer;
    uint8_t head;
    uint8_t tail;
} rb_t;

int8_t rb_reset(rb_t * rb);
uint8_t rb_full(rb_t * rb);
uint8_t rb_empty(rb_t * rb);
int8_t rb_put(rb_t * rb, const void *data);
int8_t rb_peek(rb_t * rb, void *data);
int8_t rb_get(rb_t * rb, void *data);

#endif /* RB_H_ */
