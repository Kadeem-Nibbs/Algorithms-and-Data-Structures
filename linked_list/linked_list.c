#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX_VALUE = 100;

struct node {
    int data;
    struct node *next;
};

struct dl_node {
    int data;
    struct dl_node *prev;
    struct dl_node *next;
};

struct node* initialize_linked_list(int length);
struct node* initialize_dlinked_list(int length);
void print_linked_list(struct node *head);
int get_length(struct node *head);
void free_linked_list(struct node *head);
int peek(struct node *head);
struct node* pop(struct node *head);
struct node* push(struct node *head, int value);

int main()
{
    printf("First linked list...\n");
    struct node *head;
    head = initialize_linked_list(20);
    print_linked_list(head);
    free_linked_list(head);
    printf("\n\nSecond linked list...\n");
    struct node *new_head;
    new_head = malloc( sizeof(struct node) );
    new_head->data = 0;
    new_head->next = 0;
    int i;
    for (i = 1; i < 20; i++){
        push(new_head, i);
    }
    print_linked_list(new_head);
    printf("\n\nDeleting the head of the second linked list...\n");
    new_head = pop(new_head);
    print_linked_list(new_head);
    return 0;
}

/**
 * initialize_linked_list - Create linked list with random integer values
 * @length:     The length of the linked list to be created
 *
 * Returns a pointer to the first node of a newly created linked list
 */
struct node* initialize_linked_list(int length)
{
    int i;
    struct node *head;
    struct node *pointer;
    head = malloc( sizeof(struct node) );
    head->data = rand()%MAX_VALUE;
    head->next = 0;
    pointer = head;
    srand( time(NULL) );
    // Would a linked list defined this way be contiguous in memory?
    for (i = 0; i < length - 1; i++){
        pointer->next = malloc( sizeof(struct node) );
        pointer = pointer->next;
        pointer->data = rand()%MAX_VALUE;
    }
    pointer->next = 0;
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
    while (pointer != 0){
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
}

/**
 * get_length - Return length of linked list
 * @head:       pointer to head node of linked list
 */
int get_length(struct node *head)
{
    struct node *pointer;
    pointer = head;
    int count = 0;
    while (pointer != 0){
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
    while (pointer != 0){
        tmp = pointer;
        pointer = pointer->next;
        free( tmp );
    }
}

/**
 * peek - return the value of the head node of a linked list
 * @head:       pointer to head node of linked list
 */
int peek(struct node *head)
{
    if (head != 0){
        return head->data;
    }
    return -1;
}

/**
 * pop - Delete head node of linked list
 * @head:       pointer to head node of linked list
 *
 * Return pointer to new head node.
 */
struct node* pop(struct node *head)
{
    struct node *tmp;
    if (head == 0){
        return 0;
    }
    tmp = head;
    head = head->next;
    free( tmp );
    return head;
};

/**
 * push - Add node to tail end of linked list
 * @head:       pointer to head node of linked list
 * @value:      value of node added to tail end of list
 *
 * Returns pointer to head node of linked list.
 */
struct node* push(struct node *head, int value)
{
    if (head == 0){
        return 0;
    }
    struct node *pointer, *tmp;
    tmp = pointer = head;
    while (tmp != 0){
        pointer = tmp;
        tmp = tmp->next;
    }
    pointer->next = malloc( sizeof(struct node) );
    pointer = pointer->next;
    pointer->data = value;
    pointer->next = 0;
    return head;
};
