#include "bst_test.h"
#include "binary-search-tree.h"
#include <stdio.h>
 
void bst_test(){
	int arr[] = {1, 10, 9, 7, 8, 11, 5, 4, 3, 15};
	BST* bst = create_bst();
	build_bst(bst, arr, 10);
	printf("Root: %d\n", bst->root->val);
	//printf("Root's left and right child: %d \n", bst->root->rchild->val);
	printf("Max in the BST: %d\n", find_max(bst));
	node* n = search(bst, 15);
	if(n){
		printf("Found: %d\n", n->val);
	}else{
		printf("Not found!\n");
	}
	inorder_traversal(bst, arr);
	print_array(arr, 10);
	
}	

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
