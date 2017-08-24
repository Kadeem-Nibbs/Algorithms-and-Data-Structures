#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h" /* Can't access functions from this file
                    although I have them in the same directory
                    */

// This program defines a function to remove duplicate elements from a linked list

void remove_dupes(struct node* head);

int main()
{
    struct node* ll;
    ll = linked_list(7);
    int i;
    for(i = 1; i < 10; i++){
        push(ll, 7);
    }
    print_linked_list(ll);
    remove_dupes(ll);
    print_linked_list(ll);
    return 0;
}

/*
 * remove_dupes - Removes duplicate elements from a linked list
 * @head: pointer to first node of linked list
 */
void remove_dupes(struct node* head){
    struct node* tmp1 = head;
    struct node* tmp2 = head;
    int checker = 0;
    while (tmp1->next != NULL){ /* This line breaks the program
                        due to "dereferencing pointer to incomplete type
                        but I'm suspicious that this is due to a problem with
                        CodeBlocks.
                        */
        tmp2 = tmp1;
        if (checker & (1 << (tmp1->data))){
            tmp2 = tmp2->next;
            tmp1 = tmp2->next;
            free( tmp2 );
        }
        else{
            checker = checker + (1 << (tmp1->data));
        }
    }
};
