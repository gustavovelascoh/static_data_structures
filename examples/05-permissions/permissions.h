/*
 * permissions.h
 *
 *  Created on: Feb 10, 2019
 *      Author: gustavo
 *
 *  Permissions module
 */
#include <stdint.h>
#include <string.h>

#define LL_OK       0
#define LL_EMPTY    1
#define LL_FULL     2

#define PERM_LL_SIZE 10

typedef char tag_t[10];

 typedef struct {
     tag_t rfid;
     uint32_t id;
     uint8_t mask;
 } permission_t;

void permissions_init();

void permissions_add(permission_t p);

void permissions_remove(uint32_t id);

void permissions_flush();

uint8_t permissions_validate(tag_t rfid);

void permissions_calc_crc();

void permissions_get_list_ids(uint32_t * ids, uint8_t * len);
