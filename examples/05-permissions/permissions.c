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
static uint32_t __ids_list[PERM_LL_SIZE];
static uint8_t __ids_cnt = 0;

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
    ll_node_t * curr = NULL;

    permission_t * next_perm;
    permission_t * curr_perm;

    uint8_t ret = 0;

    ret = ll_get_next(&permissions_ll, NULL, &next);

    //printf("next: %p, ret: %d\n", next, ret);

    if (ret == LL_OK){
        while (ret==LL_OK){
            next_perm = next->data;
            //printf("New ID %d, curr id %d\n", p.id, next_perm->id);
            if (next_perm->id > p.id){
                printf("Inserting ID %d before id %d\n", p.id, next_perm->id);
                if (curr == NULL){
                    // TODO: INSERT AT FIRST
                    ll_insert_next(&permissions_ll, (permissions_ll.first), &p);
                } else {
                    //insert after curr:
                    ll_insert_next(&permissions_ll, curr, &p);
                }
                break;
            }

            curr = next;
            ret = ll_get_next(&permissions_ll, &curr, &next);
        }

        if (ret == LL_END){
            ll_insert_next(&permissions_ll, curr, &p);
            printf("Inserting ID %d at the end of the list\n", p.id);
        }

    } else if (ret == LL_EMPTY) {
        ll_push(&permissions_ll, &p);
        printf("Inserting ID %d as first element\n", p.id);
    } else {
        // FULL

    }

    //ll_print(&permissions_ll);
}

void permissions_remove(uint32_t id){
    ll_node_t * next;
    ll_node_t * curr = NULL;

    permission_t * next_perm;
    permission_t * curr_perm;

    uint8_t ret = 0;

    ret = ll_get_next(&permissions_ll, NULL, &next);

    //printf("next: %p, ret: %d\n", next, ret);

    if (ret == LL_OK){
        while (ret==LL_OK){
            next_perm = next->data;

            if (next_perm->id == id){
                printf("Removing ID %d, found after id %d\n", id, ((permission_t *)(curr->data))->id);
                ll_delete_next(&permissions_ll, curr);
                break;
            }

            curr = next;
            ret = ll_get_next(&permissions_ll, &curr, &next);
        }

        if (ret == LL_END){
            // NOTHING TO REMOVE
        }

    } else if (ret == LL_EMPTY) {
        // NOTHING TO REMOVE
    } else {
        // FULL

    }
}

void permissions_flush();

uint8_t permissions_validate(tag_t rfid);

void permissions_calc_crc(){

}

void __fill_ids_list(void * data){
    permission_t * p = data;
    __ids_list[__ids_cnt++] = p->id;
}

void permissions_get_list_ids(uint32_t * ids, uint8_t * len){
    __ids_cnt = 0;
    ll_traverse(&permissions_ll, __fill_ids_list);
    memcpy(ids, __ids_list, __ids_cnt*sizeof(uint32_t));
    *len = __ids_cnt;
}

void permissions_update_start(){
    permissions_crc = 0x00;
}

void permissions_update_end(){

}

void permisisons_print(){
    ll_node_t * curr;
    ll_node_t * next;
    permission_t * p;

    ll_get_next(&permissions_ll, NULL, &next);

    printf("\n% 8s\t%10s\t%s\n", "ID", "RFID", "MASK");

    while (next != NULL){
        p = next->data;
        printf("% 8d\t%10s\t%02X\n", p->id, p->rfid, p->mask);
        curr = next;
        ll_get_next(&permissions_ll, &curr, &next);
    }
}
