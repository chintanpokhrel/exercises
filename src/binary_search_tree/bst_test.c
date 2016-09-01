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
	
	printf("Inorder Traversal: ");
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

int main(){
	bst_test();
	return 0;
}
