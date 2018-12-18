/*
 * rb.c
 *
 *  Created on: Mar 27, 2017
 *      Author: gustavo
 *
 *     Version: 1.0
 */

#include "rb.h"
#include "string.h"

int8_t rb_reset(rb_t * rb)
{
    int8_t ret = RB_ERROR;

    if(rb){
        ret = RB_NO_ERROR;
        rb->head = 0;
        rb->tail = 0;
    }

    return ret;
}

uint8_t rb_full(rb_t * rb)
{
    return ((rb->head + 1) % rb->length) == rb->tail;
}

uint8_t rb_empty(rb_t * rb)
{
    return (rb->head == rb->tail);
}

int8_t rb_put(rb_t * rb, const void *data)
{
    int8_t ret = RB_ERROR;
    uint16_t offset = 0;
    uint8_t * buf = (uint8_t *) rb->buffer;

    if(rb){
        offset = rb->head * rb->element_size;
        memcpy(&(buf[offset]), data, rb->element_size);
        rb->head = (rb->head + 1) % rb->length;

        ret = RB_NO_ERROR;

        if (rb->head == rb->tail){
            rb->tail = (rb->tail + 1) % rb->length;
            ret = RB_OVERWRITE;
        }
    }

    return ret;
}

int8_t rb_peek(rb_t * rb, void *data)
{
    int8_t ret = RB_ERROR;
    uint16_t offset = 0;
    uint8_t * buf = (uint8_t *) rb->buffer;

    if(rb && data){
        if (!rb_empty(rb))
        {
            ret = RB_NO_ERROR;
            offset = rb->tail * rb->element_size;
            memcpy(data, &(buf[offset]), rb->element_size);
        }
        else
        {
            ret = RB_EMPTY;
        }
    }

    return ret;
}

int8_t rb_get(rb_t * rb, void *data)
{
    int8_t ret = RB_ERROR;
    uint16_t offset = 0;
    uint8_t * buf = (uint8_t *) rb->buffer;

    if(rb && data){
        if (!rb_empty(rb))
        {
            ret = RB_NO_ERROR;
            offset = rb->tail * rb->element_size;
            memcpy(data, &(buf[offset]), rb->element_size);
            rb->tail = (rb->tail + 1) % rb->length;
        }
        else
        {
            ret = RB_EMPTY;
        }
    }

    return ret;
}
