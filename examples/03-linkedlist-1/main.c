#include <stdio.h>
#include "ll.h"

typedef struct {
    uint8_t age;
    char name[32];
} person_t;

#define PERSONS_LL_SIZE 16

int16_t main(){

    stack_t persons_ll_s;
    person_t persons_ll_a[PERSONS_LL_SIZE];
    person_t * persons_ll_sa[PERSONS_LL_SIZE];
    ll_node_t persons_ll_na[PERSONS_LL_SIZE];
    ll_t persons_ll;

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

    ll_init(&persons_ll, persons_ll_na, &persons_ll_a, &persons_ll_s, &persons_ll_sa, PERSONS_LL_SIZE, sizeof(person_t));

    ll_print(&persons_ll);

    ll_push(&persons_ll, &person_db[0]);
    //ll_push(&persons_ll, &person_db[1]);

    ll_print(&persons_ll);
    // uint8_t i = 0;
    // uint8_t retval = 0;
    //
    // for (i=0;i<18;i++){
    //     printf("Pushing {%d, %s}\n", person_db[i].age, person_db[i].name);
    //     if (stack_push(&person_stack, &person_db[i]) < 0){
    //         printf("STACK OVERFLOW\n");
    //     }
    // }
    //
    // for (i=0;i<18;i++){
    //     if (stack_pop(&person_stack, &person_db[i]) < 0){
    //         printf("STACK EMPTY\n");
    //     } else {
    //         printf("{%d, %s}\n", person_db[i].age, person_db[i].name);
    //     }
    // }
    //
    return 0;
}
