#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct node {
    int data;
    struct node *next;
};
struct dl_node {
    int data;
    struct dl_node *prev;
    struct dl_node *next;
};
struct node* linked_list(int value);
// struct node* dlinked_list(int length);
void print_linked_list(struct node *head);
int length(struct node *head);
void free_linked_list(struct node *head);
int peek(struct node *head);
struct node* pop(struct node *head, int* data);
void push(struct node *head, int value);

#endif // LINKED_LIST_H_INCLUDED
