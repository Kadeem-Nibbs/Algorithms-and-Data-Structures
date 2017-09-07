#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node* intersection(struct node* llist, struct node* llist2);

int main()
{
    struct node* list1 = linked_list(9);
    struct node* list2 = linked_list(7);
    struct node* list3 = linked_list(25);
    struct node* crossover;
    int i;
    for (i = 0; i < 10 ; i++){
        push(list1, 9);
        push(list2, 7);
    }
    printf("First list ...\n");
    print_linked_list(list1);
    printf("\n\nSecond list ...\n");
    print_linked_list(list2);
    crossover = intersection(list1, list2);
    printf("Checking intersection between first and second list ... \n");
    if (crossover == NULL){
        printf("\n\nNo intersection");
    }
    else{
        printf("\n\n%d\n", crossover->data);
    }
    list3->next = linked_list(13);
    list3->next->next = list2;
    printf("\n\nThird List ...\n");
    print_linked_list(list3);
    crossover = intersection(list3, list2);
    printf("Checking intersection between second and third list ... \n");
    if (crossover == NULL){
        printf("\n\nNo intersection");
    }
    else{
        printf("\n\n%d\n", crossover->data);
    }

    return 0;
}

struct node* intersection(struct node* llist, struct node* llist2){
    struct node* ptr = llist;
    struct node* ptr2 = llist2;
    struct node* intersection;
    int len;
    int len2;
    int diff;
    int i;
    if (ptr == NULL || ptr2 == NULL){
        return NULL;
    }
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    while (ptr2->next != NULL){
        ptr2 = ptr2->next;
    }
    if (ptr != ptr2){ // if two lists intersect they must have the same last node
        return NULL;
    }
    len = length(llist);
    len2 = length(llist2);
    ptr = llist;
    ptr2 = llist2;
    if (len > len2){
        diff = len - len2;
        for (i=0; i<diff; i++){
            ptr = ptr->next;
        }
    }
    else {
        diff = len2 - len;
        for (i=0; i<diff; i++){
            ptr2 = ptr2->next;
        }
    }
    while (ptr != ptr2){
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    return ptr;
};
