#include "permissions.h"


void permissions_init(){
    
}

void permissions_add(permissions_t p);

void permissions_remove(uint32_t id);

void permissions_flush();

uint8_t permissions_validate(tag_t rfid);
