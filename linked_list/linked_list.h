#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node;
struct dl_node;
struct node* linked_list(int value);
struct node* dlinked_list(int length);
void print_linked_list(struct node *head);
int length(struct node *head);
void free_linked_list(struct node *head);
int peek(struct node *head);
struct node* pop(struct node *head, int* data);
void push(struct node *head, int value);

#endif // _linked_list
