#include "binary-search-tree.h"
#include <stdlib.h>


BST* create_bst(){
	BST* bst = malloc(sizeof(BST));
	bst->root = NULL;
	return bst;
}

int build_bst(BST* bst, int* arr, int n){
	int i;
	for(i=0; i<n; ++i){
		insert_node(bst, arr[i]);
	}
	
	return 0;
}

int insert_node(BST* bst, int val){

	node* new_node = malloc(sizeof(node));
	if(!new_node){
		return -1;
	}
	
	new_node->val = val;
	new_node->rchild = NULL;
	new_node->lchild = NULL;
	
	if(!bst->root){
		bst->root = new_node;
		return 0;
	}
	
	node* cur = bst->root;
	
	while(cur){
		if(val <= cur->val){
			if(!cur->lchild){
				cur->lchild = new_node;
				break;	
			}
			cur = cur->lchild;			
		}else{
			if(!cur->rchild){
				cur->rchild = new_node;	
				break;			
			}
			cur = cur->rchild;		
		}
	}
	return 0;
}

int find_max(BST* bst){
	node* cur = bst->root;
	
	while(cur && cur->rchild){
		cur = cur->rchild;
	}
	return cur->val;
}

node* search(BST* bst, int val){
	node* cur = bst->root;
	while(cur){
		if(val == cur->val){
			return cur;
		}else if(val < cur->val){
			cur = cur->lchild;
		}else{
			cur = cur->rchild;
		}
	}
	return NULL;
}

void inorder_traversal(BST* bst, int* arr){
	inorder(bst->root, arr);
}

static int i = 0;
void inorder(node* n, int* arr){
	if(n){
		inorder(n->lchild, arr);
		//printf("%d \n", n->val);
		arr[i++] = n->val;
		inorder(n->rchild, arr);
	}
}


