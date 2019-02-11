#include "permissions.h"

void main(){

    permission_t p0 = {"00AA22CC33", 1, 0xF0};
    permission_t p1 = {"0025001234", 1234, 0xC0};
    permission_t p2 = {"AADD001234", 200, 0x40};
    permission_t p3 = {"99CC001234", 42, 0x80};
    permission_t p4 = {"0025001234", 653, 0xC0};
    permission_t p5 = {"AADD001234", 65535, 0x30};
    permission_t p6 = {"99CC001234", 2145241, 0x80};
    permission_t p7 = {"0025001234", 36, 0xC0};
    permission_t p8 = {"AADD001234", 18, 0x40};
    permission_t p9 = {"99CC001234", 999, 0xF0};

    permissions_init();

    permissions_add(p0);

}
