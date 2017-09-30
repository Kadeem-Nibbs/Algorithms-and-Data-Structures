#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack{
    int height;
    struct StackNode* top;
};

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack* new_stack(void);
void spush(struct Stack* st, int value);
struct StackNode* spop(struct Stack* st);
int speek(struct Stack* st);
#endif // STACK_H_INCLUDED
