#include <stdio.h>
#include "queue.h"

int main(){
	type_t type = integer;
	Queue *queue = create_Queue(type);
	int data[] = {10, 11, 25, 34, 21, 16};
	int i;
	for(i=0; i<6; ++i){
		enQueue(queue, (void *)&data[i]);	
	}
	
	for(i=0; i<6; ++i){
		printf("%d ", *((int *)deQueue(queue)));
	}
	
	printf("\n");
	
	destroy_Queue(queue);
	
	type = treeNode;
	
	queue = create_Queue(type);
	
	TreeNode *root = get_Node();
	root->data = 314;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 14;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 34;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 4;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 3;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 43;
	enQueue(queue, (void *)root);
	
	root = get_Node();
	root->data = 42;
	enQueue(queue, (void *)root);
	
	for(i=0; i<7; ++i){
		printf("%d ", ((TreeNode *)deQueue(queue))->data);
	}
	
	printf("\n");
	
	destroy_Queue(queue);
	
	return 0;
}
