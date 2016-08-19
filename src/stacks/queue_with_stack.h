#ifndef _queue_with_stack_h
#define _queue_with_stack_h

#include "stack.h"

typedef struct Queue{
	Node *front;
	Node *rear;
}Queue;

Queue* create_Queue();
void enQueue(Queue *queue, int data);
int deQueue(Queue *queue);
void destroy_Queue(Queue*);

#endif
