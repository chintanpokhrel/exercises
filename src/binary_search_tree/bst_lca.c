#include "binary-search-tree.h"


node *_get_LCA(node *n1, node *n2, node *root);

node *get_LCA(BST *bst, node *n1, node *n2){
	return bst ? _get_LCA(n1, n2, bst->root) : NULL;
}

node *_get_LCA(node *n1, node *n2, node *root){ //O(h) time and space, O(h) space can be reduced to O(1) if implemented recursively
	if(!root){
		return NULL;
	}

	if(root == n1 || root == n2){
		return n1;
	}
	
	if((n1->val >= root->val && n2->val <= root->val) || (n1->val <= root->val && n2->val >= root->val)){
		return root;
	}
	
	node *result;
	if(n1->val >= root->val){
		result = _get_LCA(n1, n2, root->rchild);
	}else{
		result = _get_LCA(n1, n2, root->lchild);
	}
	
	if(result == n1 || result == n2){
		return root;
	}
	
	return result;
}
