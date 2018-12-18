#include <stdio.h>
#include "stack.h"

typedef struct {
    uint8_t age;
    char name[32];
} person_t;

int16_t main(){

    stack_t person_stack;
    person_t person_st_a[16];

    person_t person_db[16] = {
        {12, "John"},
        {12, "Jenny"},
        {11, "Dan"},
        {10, "Steve"},
        {15, "Anne"},
        {19, "Tom"},
        {12, "Joe"},
        {14, "Julie"},
        {12, "Cris"},
        {21, "Meg"},
        {16, "Sam"},
        {14, "Alex"},
        {12, "Con"},
        {21, "Alf"},
        {10, "Mary"},
        {22, "Alex"}
    };

    stack_init(&person_stack, person_st_a, 16, sizeof(person_t));

    uint8_t i = 0;
    uint8_t retval = 0;

    for (i=0;i<18;i++){
        printf("Pushing {%d, %s}\n", person_db[i].age, person_db[i].name);
        if (stack_push(&person_stack, &person_db[i]) < 0){
            printf("STACK OVERFLOW\n");
        }
    }

    for (i=0;i<18;i++){
        if (stack_pop(&person_stack, &person_db[i]) < 0){
            printf("STACK EMPTY\n");
        } else {
            printf("{%d, %s}\n", person_db[i].age, person_db[i].name);
        }
    }

    return 0;
}
