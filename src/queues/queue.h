#ifndef _queue_h
#define _queue_h

#include <stdlib.h>
#include "bt.h"

typedef enum { integer, treeNode } type_t; //add types here

typedef struct Node{
	void *data;
	struct Node *next;
}Node;

typedef struct Queue{
	type_t type; //enforcing the type for no reason I can think of except simplicity,
	//I could allow nodes with different node types buy placing this in Node
	struct Node *front;
	struct Node *rear;
}Queue;

Queue *create_Queue(type_t);

void enQueue(Queue *, void *);

void *deQueue(Queue *);

void destroy_Queue(Queue *);

void empty_Queue(Queue *);

/*typedef struct Node{
	TreeNode* data;
	struct Node *next;
}Node;

typedef struct Queue{
	struct Node *front;
	struct Node *rear;
}Queue;

Queue* create_queue();


void enQueue(Queue*, TreeNode*);

TreeNode* deQueue(Queue*);

void destroy_Queue(Queue*);*/

#endif

