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

int find_max(BST *bst){
	node *cur = bst->root;
	
	while(cur && cur->rchild){
		cur = cur->rchild;
	}
	return cur->val;
}

int find_min(BST *bst){
	if(!bst || !bst->root){
		return -1; //need to handle this case for empty bst
	}
	node *min_node = find_min_node(bst->root);
	return min_node ? min_node->val : -1; 
}

node *find_min_node(node *root){
	node *cur = root;
	
	while(cur && cur->lchild){
		cur = cur->lchild;
	}
	return cur;
}

node *find_max_node(node *root){
	node *cur = root;
	
	while(cur && cur->rchild){
		cur = cur->rchild;
	}
	return cur;
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

node *get_successor(BST *tree, int val){
	node *cur = tree->root;
	node *parent = NULL;
	/*while(cur){
		if(val > cur->val){
			if(!cur->rchild){
				return parent;
			}
			parent = cur;
			cur = cur->rchild;
		}else if(val < cur->val){
			if(!cur->lchild){
				return cur;
			}
			parent = cur;
			cur = cur->lchild;
		}else{
			if(cur->rchild){
				return find_min_node(cur->rchild);
			}else{
				if(parent->lchild==cur)
					return parent;
				return NULL;
			}
		}
	}*/
	//I completely missed such an elegant solution !
	while(cur){
		if(val < cur->val){
			parent = cur;
			cur = cur->lchild;
		}else{
			cur = cur->rchild;
		}
		
	}
	return parent;
}


node *get_predecessor(BST *bst, int val){
	node *cur = bst->root;
	node *so_far_predecessor = NULL;
	while(cur){
		if(val > cur->val){
			so_far_predecessor = cur;
			cur = cur->rchild;
		}else{
			cur = cur->lchild;
		}
	}
	return so_far_predecessor;
}





