#include "bt.h"
#include "queue.h"
#include <stdio.h>

int main(){
	BinaryTree *tree = create_BinaryTree();
	if(!tree){
		printf("Error! Not able to allocate memory");
		return 0;
	}
	tree->root = get_Node();
	tree->root->data = 314;
	tree->root->left = get_Node();
	tree->root->left->data = 6;
	tree->root->right = get_Node();
	tree->root->right->data = 8;
	tree->root->left->left = get_Node();
	tree->root->left->left->data = 271;
	tree->root->left->right = get_Node();
	tree->root->left->right->data = 561;
	tree->root->left->right->left = get_Node();
	tree->root->left->right->left->data = 3;
	
	tree->root->right->left = get_Node();
	tree->root->right->left->data = 10;
	tree->root->right->right = get_Node();
	tree->root->right->right->data = 71;
	tree->root->right->left->right = get_Node();
	tree->root->right->left->right->data = 1;
	printf("Tree Created!\n");
	Queue* queue = create_queue();
	if(!queue){
		printf("Error! Not able to allocate memory");
		return 0;
	}
	
	enQueue(queue, tree->root);
	//printf("queue Created and root enqueued! \n %d\n", queue->front->data->data);
	//TreeNode *elem = deQueue(queue);
	//printf("Dequed and data \n %d\n", elem->data);
	//enQueue(queue, elem->left);
	//enQueue(queue, elem->right);
	//elem = deQueue(queue);
	//printf("Dequed and data \n %d\n", elem->data);
	while(queue->front){
		TreeNode *elem = deQueue(queue);
		printf("Taking out %d \n", elem->data);
		if(elem->left){
			enQueue(queue, elem->left);
			printf("Inserting %d\n", elem->left->data);
		}
		if(elem->right){	
			enQueue(queue, elem->right);
			printf("Inserting %d\n", elem->right->data);
		}
					
	}
	destroy_BinaryTree(tree);
	destroy_Queue(queue);
	return 0;
	
}
