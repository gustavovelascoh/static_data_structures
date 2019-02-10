#include "permissions.h"

void main(){

    permission_t p1 = {"0025001234", 1234, 0xC0};
    permission_t p2 = {"AADD001234", 200, 0x40};
    permission_t p3 = {"99CC001234", 42, 0x80};

    permissions_init();


}
