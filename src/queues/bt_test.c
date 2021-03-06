#include <stdio.h>
#include "list.h"
#include "bt.h"

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
	tree->root->left->left = get_Node();
	tree->root->left->left->data = 271;
	tree->root->left->right = get_Node();
	tree->root->left->right->data = 561;
	tree->root->left->right->left = get_Node();
	tree->root->left->right->left->data = 3;
	//tree->root->left->right->left->right = get_Node();
	//tree->root->left->right->left->right->data = 31;
	tree->root->right = get_Node();
	tree->root->right->data = 6;
	tree->root->right->right = get_Node();
	tree->root->right->right->data = 271;
	tree->root->right->left = get_Node();
	tree->root->right->left->data = 561;
	tree->root->right->left->right = get_Node();
	tree->root->right->left->right->data = 3;
	//tree->root->right->left->right->left = get_Node();
	//tree->root->right->left->right->left->data = 29;
	
	printf("Tree Created!\n");
	
	printf("Balanced or not: %d\n", isBalanced_BinaryTree(tree));
	printf("Symmetric or not: %d\n", isSymmetric_BinaryTree(tree));
	
	TreeNode *n = getLCA_BinaryTree(tree, tree->root->left->right->left, tree->root->left->right);
	
	printf("LCA is: %d\n", n->data);
	
	int arr1[] = {'F', 'B', 'A', 'E', 'H', 'C', 'D', 'I', 'G'};
	int arr2[] = {'H', 'B', 'F', 'E', 'A', 'C', 'D', 'G', 'I'};
	tree = getTreeFromTraversal(arr1, arr2, 9);
	
	printf("%c %c %c %c %c %c %c %c %c", tree->root->left->left->data, tree->root->left->right->left->data,
										 tree->root->left->right->data, tree->root->left->data, tree->root->right->right->right->left->data,
										 tree->root->right->right->right->data, tree->root->right->right->data, tree->root->right->data,
										 tree->root->data);
										 //printf("%c %c %c", tree->root->left->data, tree->root->right->data, tree->root->data);
	//printf("%c", tree->root->data);
	
	return 0;
}
