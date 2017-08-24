#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

struct dl_node {
    int data;
    struct dl_node *prev;
    struct dl_node *next;
};

int main()
{
    return 0;
}

/**
 * linked_list - Initialize single node linked list
 * @value:     The value of the node created
 *
 * Returns a pointer to the first node of a newly created linked list
 */
struct node* linked_list(int value)
{
    struct node *head;
    head = malloc( sizeof(head) );
    head->data = value;
    head->next = NULL;
    return head;
}

/**
 * print_linked_list - Print the values contained within a linked list
 * @head:       pointer to head node of linked list
 */
void print_linked_list(struct node *head)
{
    struct node *pointer;
    pointer = head;
    while (pointer != NULL){
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
}

/**
 * get_length - Return length of linked list
 * @head:       pointer to head node of linked list
 */
int length(struct node *head)
{
    struct node *pointer;
    pointer = head;
    int count = 0;
    while (pointer != NULL){
        count++;
        pointer = pointer->next;
    }
    return count;
}

/**
 * free_linked_list - Free the memory taken up by a linked list
 * @head:       pointer to head node of linked list
 */
void free_linked_list(struct node *head)
{
    struct node *pointer, *tmp;
    pointer = head;
    while (pointer != NULL){
        tmp = pointer;
        pointer = pointer->next;
        free( tmp );
    }
}

/**
 * peek - return the value of the head node of a linked list
 * @head:       pointer to head node of linked list
 *
 * Return data if head is not null, print -1 and return error message otherwise
 */
int peek(struct node *head)
{
    if (head != NULL){
        return head->data;
    }
    printf('You done goofed');
    return -1;
}

/**
 * pop - Delete head node of linked list
 * @head:       pointer to head node of linked list
 * @data:       points to location to store data at head of linked list in
 *
 * Return value new head node and store data from old head in int
 */
struct node* pop(struct node *head, int* data)
{
    struct node *tmp;
    if (head == NULL){
        return;
    }
    tmp = head;
    // *data = tmp->data; // This line crashed the program, any ideas why?
    printf("Got here");
    head = head->next;
    free( tmp );
    return head;
};

/**
 * push - Add node to tail end of linked list
 * @head:       pointer to head node of linked list
 * @value:      value of node added to tail end of list
 *
 * Prints error message if input head is null
 */
void push(struct node *head, int value)
{
    if (head == NULL){
        head->data = value;
        head->next = NULL;
        printf("You done goofed");
        return;
    }
    struct node *pointer, *tmp;
    tmp = pointer = head;
    while (tmp != NULL){
        pointer = tmp;
        tmp = tmp->next;
    }
    pointer->next = malloc( sizeof(pointer) );
    pointer = pointer->next;
    pointer->data = value;
    pointer->next = NULL;
};
