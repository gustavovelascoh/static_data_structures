#include <stdio.h>
#include "ll.h"

typedef struct {
    uint8_t age;
    char name[32];
} person_t;

#define PERSONS_LL_SIZE 16

void print_person(void * person_p){
    person_t * person = (person_t *) person_p;
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void print2(ll_t * pll){
    ll_node_t * curr;
    ll_node_t * next;
    person_t * p;

    ll_get_next(pll, NULL, &next);

    while (next != NULL){
        p = next->data;
        printf("Name: %s, Age: %d\n", p->name, p->age);
        curr = next;
        ll_get_next(pll, &curr, &next);
    }
}


int16_t main(){

    stack_t persons_ll_s;
    person_t persons_ll_a[PERSONS_LL_SIZE];
    ll_node_t * persons_ll_sa[PERSONS_LL_SIZE];
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

    ll_init(&persons_ll, persons_ll_na, &persons_ll_a, &persons_ll_s,
        persons_ll_sa, PERSONS_LL_SIZE, sizeof(person_t));

    ll_print(&persons_ll);

    ll_push(&persons_ll, &person_db[0]);
    ll_push(&persons_ll, &person_db[1]);
    ll_push(&persons_ll, &person_db[4]);
    ll_push(&persons_ll, &person_db[5]);
    ll_push(&persons_ll, &person_db[8]);
    ll_push(&persons_ll, &person_db[10]);

    ll_print(&persons_ll);

    ll_traverse(&persons_ll, print_person);

    print2(&persons_ll);

    return 0;
}
