/*
 * permssions.h
 *
 *  Created on: Feb 10, 2019
 *      Author: gustavo
 *
 *  Permissions module
 */
#include <stdint.h>

typedef char tag_t[10];

 typedef struct {
     tag_t rfid;
     uint32_t id;
     uint8_t mask;
 } permissions_t;

void permissions_init();

void permissions_add(permissions_t p);

void permissions_remove(uint32_t id);

void permissions_flush();
