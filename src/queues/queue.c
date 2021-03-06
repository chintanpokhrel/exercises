#include "queue.h"
#include <stdio.h>

Queue* create_Queue(type_t type){
	Queue *queue = malloc(sizeof(Queue));
	if(queue){
		queue->type = type;
		queue->front = NULL;
		queue->rear = NULL;
	}
	
	return queue;
}

void enQueue(Queue *queue, void *data){
	Node *new_node = malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;
	
	if(queue->rear){
		queue->rear->next = new_node;
		queue->rear = new_node;
	}else{
		queue->front = new_node;
		queue->rear = new_node;
	}		

}

void *deQueue(Queue *queue){
	if(!queue || !queue->front){
		//set queue empty error first, return value is useless
		return NULL;
	}
	Node *temp = queue->front;
	queue->front = temp->next;
	if(temp == queue->rear){
		queue->rear = NULL;
	}
	void *data = temp->data;
	free(temp);
	
	return data;	
}

void destroy_Queue(Queue *queue){
	if(queue->front){
		printf("Emptying Queue, front: %p\n", queue->front);
		empty_Queue(queue);
	}
	printf("Freeing Queue, queue: %p\n", queue);
	free(queue);
}

void empty_Queue(Queue *queue){
	while(queue->rear){
		deQueue(queue);
	}
}


void eraseNode_Queue(Queue *queue, Node *node){
	if(!queue){
		return;
	}
	Node *cur = queue->front;
	if(cur == node){
		deQueue(queue);
		return;
	}
	while(cur->next){
		if(cur->next == node){
			Node *temp = node;
			cur->next = node->next;
			if(!node->next){
				queue->rear = cur;
			}
			free(node->data);
			free(node);
		}
	}
}

/* //type dependent - TreeNode type queue
Queue* create_Queue(){
	Queue *queue = malloc(sizeof(Queue));
	if(queue){
		queue->front = NULL;
		queue->rear = NULL;
	}
	
	return queue;
}

void enQueue(Queue *queue, TreeNode *data){
	Node *new_node = malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;
	
	if(queue->rear){
		queue->rear->next = new_node;
		queue->rear = new_node;
	}else{
		queue->front = new_node;
		queue->rear = new_node;
	}		

}

TreeNode* deQueue(Queue* queue){
	if(!queue || !queue->front){
		//set queue empty error first, return value is useless
		return NULL;
	}
	Node *temp = queue->front;
	queue->front = temp->next;
	if(temp == queue->rear){
		queue->rear = NULL;
	}
	TreeNode *data = temp->data;
	//free(temp);
	return data;	
}

void destroy_Queue(Queue* queue){
	free(queue);
}*/


