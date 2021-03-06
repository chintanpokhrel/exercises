#ifndef _stack_h
#define _stack_h

extern short overflow;
extern short underflow;

typedef struct Node{
	int data;
	int cached_max;
	struct Node *next;
}Node;

typedef struct Stack{
	struct Node *top;
}Stack;

Stack *create_stack();

Stack *stack_push(Stack*, int);
int stack_pop(Stack*);

int stack_max(Stack*);

int stack_empty(Stack*);

#endif
