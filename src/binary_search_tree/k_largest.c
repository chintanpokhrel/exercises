#include "binary-search-tree.h"
#include <stdlib.h>

void get_k_largest_helper(node *n, int k, int *arr, int arr_size);

//this is a nice way to do it - reverse inorder traversal - O(k)
int *get_k_largest(BST *bst, int k){
	int *k_largest = (int *)calloc(k, sizeof(int));
	
	get_k_largest_helper(bst->root, k, k_largest, 0);
	return k_largest;
}

void get_k_largest_helper(node *n, int k, int *arr, int arr_size){
	if(arr_size >= k){
		return;
	}
	if(n){
		get_k_largest_helper(n->rchild, k, arr, arr_size);
		arr[arr_size++] = n->val;
		get_k_largest_helper(n->lchild, k, arr, arr_size);
	}
}

//get the k largest elements of a binary tree - O(k lg n ) - this is a stupid way to do it
int *get_k_largest_stupid(BST *bst, int k){
	if(k<=0 || !bst || !bst->root)
		return NULL;
	int i=0;
	int *k_largest = (int *)calloc(k, sizeof(int));
	node *n = find_max_node(bst->root);
	while(i<k && n){
		k_largest[i++] = n->val;
		n = get_predecessor(bst, n->val);  //O(lg n)
	}
	return k_largest;
}

