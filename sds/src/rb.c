/*
 * rb.c
 *
 *  Created on: Mar 27, 2017
 *      Author: gustavo
 */

#include "rb.h"
#include "string.h"

void rb_init(rb_t * rb, rb_attr_t * rb_attr)
{
    rb->head = 0;
    rb->tail = 0;
    rb->buffer = rb_attr->buffer;
    rb->element_size = rb_attr->element_size;
    rb->length = rb_attr->length;
}

static uint8_t rb_full(rb_t * rb)
{
    return ((rb->head - rb->tail) == rb->length) ? 1 : 0;
}

uint8_t rb_empty(rb_t * rb)
{
    return ((rb->head - rb->tail) == 0U) ? 1 : 0;
}

int8_t rb_put(rb_t * rb, const void *data)
{
    int8_t ret = -1;
    uint16_t offset = 0;

    if (!rb_full(rb))
    {
        offset = (rb->head & (rb->length - 1)) * rb->element_size;
        memcpy(&(rb->buffer[offset]), data, rb->element_size);
        rb->head++;
        ret = 0;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

int8_t rb_get(rb_t * rb, void *data)
{
    int err = 0;
    uint16_t offset = 0;

    if (rb_empty(rb) == 0)
    {
        offset = (rb->tail & (rb->length - 1)) * rb->element_size;
        memcpy(data, &(rb->buffer[offset]), rb->element_size);
        rb->tail++;
    }
    else
    {
        err = -1;
    }

    return err;
}

void rb_flush(rb_t * rb)
{
    rb->tail = 0;
    rb->head = 0;
}
