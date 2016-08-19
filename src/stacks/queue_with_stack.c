#include "queue_with_stack.h"
#include <stdlib.h>

struct Stack *enqueueStack;
struct Stack *dequeueStack;

Queue* create_Queue(){
	Queue *queue = malloc(sizeof(Queue));
	enqueueStack = malloc(sizeof(Stack));
	dequeueStack = malloc(sizeof(Stack));
	if(queue && enqueueStack && dequeueStack){
		queue->front = NULL;
		queue->rear = NULL;
		enqueueStack->top = NULL;
		enqueueStack->top = NULL;		
	}else{
		free(queue);
		free(enqueueStack);
		free(dequeueStack);
	}
	return queue;
}

void enQueue(Queue *queue, int data){
	if(!queue){
		queue = create_Queue();
		if(!queue){
			return;
		}
	}
	stack_push(enqueueStack, data);
}

int deQueue(Queue *queue){
	if(!queue){
		//underflow, error variable needed to handle this
		return -1;
	}
	if(!dequeueStack->top){
		while(enqueueStack->top){
			//error handling missing, weird things may happen
			int data = stack_pop(enqueueStack);
			stack_push(dequeueStack, data);
		}
	}
	int data = stack_pop(dequeueStack);
	return data;
}

void empty_Queue(Queue *queue){
	if(!queue){
		return;
	}
	while(queue->front){
		deQueue(queue);
	}
}

void destroy_Queue(Queue *queue){
	empty_Queue(queue);
	free(enqueueStack);
	free(dequeueStack);
	free(queue);
}

