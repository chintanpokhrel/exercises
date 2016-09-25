#include "bst_test.h"
#include "binary-search-tree.h"
#include "k_largest.c"
#include "bst_lca.c"
#include <stdio.h>
 
void bst_test(){
	int arr[] = {1, 10, 9, 7, 8, 11, 5, 4, 3, 15};
	BST* bst = create_bst();
	build_bst(bst, arr, 10);
	printf("Root: %d\n", bst->root->val);
	//printf("Root's left and right child: %d \n", bst->root->rchild->val);
	printf("Max in the BST: %d\n", find_max(bst));
	printf("Min in the BST: %d\n", find_min(bst));
	
	node* n = search(bst, 15);
	
	if(n){
		printf("Found: %d\n", n->val);
	}else{
		printf("Test Failed: Not found 15!\n");
	}
	
	n = search(bst, 21);
	if(!n){
		printf("Yass! Not found.\n");
	}else{
		printf("Test Failed: Found non existant 21!\n");
	}
	n = get_successor(bst, 7);
	if(n){
		printf("Successor of 7 in the tree is: %d\n", n->val);
	}else{
		printf("Successor of 7 not found!\n");
	}
	
	n = get_successor(bst, 1);
	if(n){
		printf("Successor of 1 in the tree is: %d\n", n->val);
	}else{
		printf("Successor of 1 not found!\n");
	}
	
	n = get_successor(bst, 15);
	if(n){
		printf("Successor of 15 in the tree is: %d\n", n->val);
	}else{
		printf("Successor of 15 not found!\n");
	}
	
	n = get_successor(bst, 6);
	if(n){
		printf("Successor of 6 in the tree is: %d\n", n->val);
	}else{
		printf("Successor of 6 not found!\n");
	}
	
	n = get_successor(bst, 0);
	if(n){
		printf("Successor of 0 in the tree is: %d\n", n->val);
	}else{
		printf("Successor of 0 not found!\n");
	}
	
	n = get_predecessor(bst, 7);
	if(n){
		printf("predecessor of 7 in the tree is: %d\n", n->val);
	}else{
		printf("predecessor of 7 not found!\n");
	}
	
	n = get_predecessor(bst, 1);
	if(n){
		printf("predecessor of 1 in the tree is: %d\n", n->val);
	}else{
		printf("predecessor of 1 not found!\n");
	}
	
	n = get_predecessor(bst, 16);
	if(n){
		printf("predecessor of 16 in the tree is: %d\n", n->val);
	}else{
		printf("predecessor of 16 not found!\n");
	}
	
	n = get_predecessor(bst, 6);
	if(n){
		printf("predecessor of 6 in the tree is: %d\n", n->val);
	}else{
		printf("predecessor of 6 not found!\n");
	}
	
	n = get_predecessor(bst, 0);
	if(n){
		printf("predecessor of 0 in the tree is: %d\n", n->val);
	}else{
		printf("predecessor of 0 not found!\n");
	}
	
	
	printf("Inorder Traversal: ");
	inorder_traversal(bst, arr);
	print_array(arr, 10);
	
}	

void k_largest_test(){
	int arr[] = {1, 10, 9, 7, 8, 11, 5, 4, 3, 15};
	BST* bst = create_bst();
	build_bst(bst, arr, 10);
	int *k_largest = get_k_largest(bst, 0);
	if(k_largest){
		printf("Test Failed with k_largest for k=0\n");
	}else{
		printf("Test passed with k_largest for k=0\n");
	}
	//printf("First among 0 largest elements(Nonsense): %d ", k_largest[0]);
	k_largest = get_k_largest(bst, 1);
	printf("1 largest element: ");
	print_array(k_largest, 1);
	
	k_largest = get_k_largest(bst, 5);
	printf("5 largest element: ");
	print_array(k_largest, 5);
	
	k_largest = get_k_largest(bst, 20);
	printf("20 largest element: ");
	print_array(k_largest, 10);
	
}


void bst_lca_test(){
	int arr[] = {1, 10, 9, 7, 8, 11, 5, 4, 3, 15};
	BST* bst = create_bst();
	build_bst(bst, arr, 10);
	
	node *n1 = get_predecessor(bst, 15);
	node *n2 = get_successor(bst, 8);
	
	node *lca = get_LCA(bst, n1, n2);
	if(!lca){
		printf("LCA for predecessor of 7 and successor of 1 not found!\n");
	}else{
		printf("LCA: %d\n", lca->val);
	}
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	//bst_test();
	//k_largest_test();
	bst_lca_test();
	return 0;
}
