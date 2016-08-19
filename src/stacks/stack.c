#include "stack.h"
#include <stdlib.h>

short overflow = 0;
short underflow = 0;

Stack *create_stack(){
	Stack *stack = malloc(sizeof(Stack));
	stack->top = NULL;
}

Stack *stack_push(Stack *stack, int val){
	if(!stack){
		stack = create_stack();
	}
	Node *new_node = malloc(sizeof(Node));
	//if !new_node then overflow
	if(!new_node){
		overflow = 1;
		return stack;
	}
	Node *temp = stack->top;
	stack->top = new_node;
	new_node->next = temp;
	new_node->data = val;
	
	if(temp){
		new_node->cached_max = (val>temp->cached_max) ? val : temp->cached_max;
	}else{
		new_node->cached_max = val;
	}
	
	return stack;
}

int stack_pop(Stack* stack){
	if(!stack || !stack->top){
		underflow = 1;
		return -1;
	}
	Node *temp = stack->top;
	stack->top = stack->top->next;
	int data = temp->data;
	free(temp);
	return data;
}


int stack_max(Stack* stack){
	if(!stack || !stack->top){
		underflow = 1;
		return -1;
	}
	return stack->top->cached_max;
}

int stack_empty(Stack *stack){
	return stack->top?0:1;
}





