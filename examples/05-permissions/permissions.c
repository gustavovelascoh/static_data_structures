#include "permissions.h"
#include "ll.h"
#include <stdio.h>

stack_t permissions_ll_s;
permission_t permissions_ll_a[PERM_LL_SIZE];
ll_node_t * permissions_ll_sa[PERM_LL_SIZE];
ll_node_t permissions_ll_na[PERM_LL_SIZE];
ll_t permissions_ll;
uint16_t permissions_crc;
uint8_t permissions_cnt;

void permissions_init(){
    ll_init(&permissions_ll, permissions_ll_na, &permissions_ll_a,
        &permissions_ll_s, permissions_ll_sa, PERM_LL_SIZE,
        sizeof(permission_t));
    permissions_cnt = 0;
    permissions_crc = 0x0000;

    ll_print(&permissions_ll);
}

void permissions_add(permission_t p){
    ll_node_t * next;
    ll_node_t * curr;
    uint8_t ret = 0;

    ret = ll_get_next(&permissions_ll, NULL, &next);

    printf("next: %p\n", next);

    if (ret == LL_OK){
        //TODO: Insert by ID
        ;
    } else if (ret == LL_EMPTY) {
        ll_push(&permissions_ll, &p);
    } else {
        // FULL

    }

    ll_print(&permissions_ll);
}

void permissions_remove(uint32_t id);

void permissions_flush();

uint8_t permissions_validate(tag_t rfid);

void permissions_calc_crc(){

}

void permissions_list_ids(){

}
