#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack* new_stack(){
    struct Stack *st;
    struct StackNode* top;
    st = malloc( sizeof(st) );
    st->height = 0;
    st->top = NULL;
    return st;
};

/**
 * spush - Add new value to top of stack
 * @st:       stack to add new value to
 * @value:    value to add to stack
 *
 */
void spush(struct Stack* st, int value){
    struct StackNode* new_top;
    new_top = malloc( sizeof(new_top) );
    new_top->data = value;
    new_top->next = st->top;
    st->top = new_top;
    st->height++;
};

/**
 * spop - Add new value to top of stack
 * @st:       stack to add new value to
 *
 * Returns StackNode at the top of the stack
 */
struct StackNode* spop(struct Stack* st){
    struct StackNode* tmp;
    if (st->top == NULL){
        return NULL;
    }
    tmp = st->top;
    st->top = st->top->next;
    st->height--;
    return tmp;
};

/**
 * speek - Add new value to top of stack
 * @st:       stack to peek at
 *
 * Returns value of node at top of stack
 */
int speek(struct Stack* st){
    int value;
    if (st->top == NULL){
        return NULL;
    }
    value = st->top->data;
    return value;
};
