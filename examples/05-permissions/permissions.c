#include "permissions.h"
#include "ll.h"

stack_t permissions_ll_s;
permission_t permissions_ll_a[PERM_LL_SIZE];
ll_node_t * permissions_ll_sa[PERM_LL_SIZE];
ll_node_t permissions_ll_na[PERM_LL_SIZE];
ll_t permissions_ll;
uint16_t permissions_crc;

void permissions_init(){
    ll_init(&permissions_ll, permissions_ll_na, &permissions_ll_a,
        &permissions_ll_s, permissions_ll_sa, PERM_LL_SIZE,
        sizeof(permission_t));
}

void permissions_add(permission_t p);

void permissions_remove(uint32_t id);

void permissions_flush();

uint8_t permissions_validate(tag_t rfid);

void permissions_calc_crc();
