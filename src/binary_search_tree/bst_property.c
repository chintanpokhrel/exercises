#include "binary-search-tree.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int _if_bst(node *root);
int if_bst(BST *tree);

int if_bst(BST *tree){ //technically stupid because I'm taking input a BST type and saying, is it a BST ? 
//Lol, I should have enforced that at the first place
	return tree ? _if_bst(tree->root) : TRUE;	
}

int _if_bst(node *root){
	if(!root){
		return TRUE;
	}
	if(root->lchild){
		if(root->lchild->val <= root->val)
			return TRUE && _if_bst(root->lchild);
		else
			return FALSE;
	}
	if(root->rchild){
		if(root->rchild->val >= root->val)
			return TRUE && _if_bst(root->rchild);
		else
			return FALSE;
	}
	return TRUE;
}

int main(){
	BST *bst = create_bst();
	printf("Empty BST..Is it a BST ? %d\n", if_bst(bst));
	int arr[] = {7, 5, 4, 3, 2, 10, 23, 0, -1, 100};
	build_bst(bst, arr, 10);
	printf("Actually a BST..Is it a BST ? %d\n", if_bst(bst));
	BST *notBST = create_bst(); //possible because this BST is just a BT, we can do anything we want with it
	notBST->root = malloc(sizeof(node));
	notBST->root->val = 5;
	notBST->root->height = 0;
	notBST->root->lchild = NULL;
	notBST->root->rchild = NULL;
	printf("Single Node BST..Is it a BST ? %d\n", if_bst(notBST));
	
	notBST->root->lchild = malloc(sizeof(node));
	notBST->root->lchild->val = 10;
	notBST->root->lchild->height = 1;
	notBST->root->lchild->lchild = NULL;
	notBST->root->lchild->rchild = NULL;

	printf("Not a BST..Is it a BST ? %d\n", if_bst(notBST));
	return 0;
}
