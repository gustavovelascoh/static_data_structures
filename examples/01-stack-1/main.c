#include <stdio.h>
#include "stack.h"


int16_t main(){

    stack_t u8_stack;
    uint8_t u8_st_a[16];

    stack_init(&u8_stack, u8_st_a, 16, sizeof(uint8_t));

    uint8_t i = 0;
    uint8_t retval = 0;

    for (i=0;i<18;i++){
        retval = 4*i;
        printf("Pushing %d\n", retval);
        if (stack_push(&u8_stack, &retval) < 0){
            printf("STACK OVERFLOW\n");
        }
    }

    for (i=0;i<18;i++){
        if (stack_pop(&u8_stack, &retval) < 0){
            printf("STACK EMPTY\n");
        } else {
            printf("%d\n", retval);
        }
    }

    return 0;
}
