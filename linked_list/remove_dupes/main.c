#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

// This program defines a function to remove duplicate elements from a linked list

void remove_dupes(struct node* head);

int main()
{
    struct node* ll;
    struct node* sll;
    ll = linked_list(7);
    int i;
    for (i = 1; i < 10; i++){
        push(ll, 7);
    }
    printf("First list...\n");
    print_linked_list(ll);
    printf("Removing duplicates ... \n\n");
    remove_dupes(ll);
    print_linked_list(ll);
    sll = linked_list(0);
    for (i=1; i<10; i++){
        push(sll,(i%3));
    }
    printf("\n\nSecond linked list...\n");
    print_linked_list(sll);
    printf("Removing duplicates ... \n\n");
    remove_dupes(sll);
    print_linked_list(sll);
    return 0;
}

/*
 * remove_dupes - Removes duplicate elements from a linked list in O(n^2) time using O(1) space.
 *                This will be revisited and improved once i learn how to implement hash tables in C.
 * @head: pointer to first node of linked list
 */
void remove_dupes(struct node* head){
    struct node* tmp;
    struct node* tmp2;
    struct node* tmp3;
    tmp = head;
    tmp2 = head;
    while (tmp != NULL && tmp->next != NULL){
        tmp2 = tmp;
        while (tmp2->next != NULL){
            tmp3 = tmp2->next;
            if (tmp3->data == tmp->data){ // found duplicate
                if (tmp3->next != NULL){
                    tmp2->next = tmp3->next;
                    free( tmp3 );
                }
                else { // at end of linked list
                  tmp2->next = NULL;
                  free( tmp3 );
                }
            }
            else {
                tmp2 = tmp2->next;
            }
        }
        tmp = tmp->next;
    }
};
