#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "stack.h"

int palindrome(struct node* llist);

int main()
{
    struct node* llist;
    struct node* llist2;
    int i;
    llist = linked_list(1);
    for (i = 2; i <= 5; i++){
        push(llist, i);
    }
    for (i = 5; i >=1; i--){
        push(llist, i);
    }
    printf("The first linked list is ...\n");
    print_linked_list(llist);
    if (palindrome(llist)){
        printf("\n\nIt's a palindrome!!!\n\n");
    }
    else {
        printf("\n\nIt's not a palindrome.\n\n");
    }
    free_linked_list(llist);
    llist2 = linked_list(1);
    for (i = 2; i <= 10; i++){
        push(llist2, i);
    }
    printf("The second linked list is ...\n");
    print_linked_list(llist);
    if (palindrome(llist)){
        printf("\n\nIt's a palindrome!!!\n\n");
    }
    else {
        printf("\n\nIt's not a palindrome.\n\n");
    }
    return 0;
}

/**
 * palindrome - Determines whether or not a linked list is a palindrome
 * @llist:      pointer to lead node of linked list
 *
 * Returns 1 if the linked list is a palindrome and 0 otherwise
 */
int palindrome(struct node* llist){
    int len;
    int len_is_odd;
    int first_half;
    int second_half;
    int value;
    int i;
    struct node* ptr;
    struct Stack* st;
    if (llist == NULL){
        return 0;
    }
    ptr = llist;
    len = length(llist);
    len_is_odd = len % 2;
    first_half = len / 2;
    second_half = first_half;
    st = new_stack();
    for (i = 0; i < first_half; i++){
        value = ptr->data;
        spush(st, value);
        ptr = ptr->next;
    }
    if (len_is_odd){ // skip over middle element of odd-length linked list
        ptr = ptr->next;
    }
    for (i = 0; i < second_half; i++){
        value = (spop(st))->data;
        if (value != ptr->data){
            return 0;
        }
        ptr = ptr->next;
    }
    return 1;
}
