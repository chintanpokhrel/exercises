#include "binary-search-tree.h"

void _get_bst_from_preorder(BST *bst, node *root, int *preorder, int n);

BST *get_bst_from_preorder(int *preorder, int n){
	BST *bst = create_bst();
	_get_bst_from_preorder(bst, bst->root, preorder, n);
	return bst;
}

void _get_bst_from_preorder(BST *bst, node *root, int *preorder, int n){
	
}
