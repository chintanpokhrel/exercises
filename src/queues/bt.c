#include "bt.h"
#include <math.h>
//debug
#include <stdio.h>


BinaryTree* create_BinaryTree(){
	BinaryTree *temp = malloc(sizeof(BinaryTree));
	if(temp){
		temp->root = NULL;
	}
	return temp;
}

TreeNode* get_Node(){
	TreeNode *temp = malloc(sizeof(TreeNode));
	if(temp){
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
}

void destroy_BinaryTree(BinaryTree *b){
	//need to free all the nodes first. This implementation is wrong.
	//to free all the nodes, I need to traverse the tree and free from the leaves bottom up. Not implemented yet in this file.
	free(b);
}
//I hate this implementation. Possibly buggy. Need to clean it.
short isBalanced_BinaryTree(BinaryTree *b){
	int height_l = findHeight(b->root->left);
	int height_r = findHeight(b->root->right);
	//printf("height->left: %d, height->right: %d\n", height_l, height_r);
	if(height_l == -2 || height_r == -2){
		return 0;
	}
	return abs(height_l-height_r) <= 1;
}


//Caution: this doesn't always find the height. Its a hack. Returns -2 if the tree is unbalanced!
int findHeight(TreeNode *t){
	TreeNode *cur = t;
	
	if(!t->left && !t->right){
		return 0;	
	}
	
	int height_l = -1;
	int height_r = -1;
	
	if(t->left && !t->right){
		height_l = findHeight(t->left);
		if(height_l == -2){
			return -2;
		}
		if(abs(height_l - height_r)>1){
			return -2;
		}
		return height_l + 1;
	}else if(!t->left && t->right){
		height_r = findHeight(t->right);
		if(height_r == -2){
			return -2;
		}
		if(abs(height_l - height_r)>1){
			return -2;
		}
		return height_r + 1;
	}else{
		int height_l =  findHeight(t->left);
		int height_r = findHeight(t->right);
		if(height_l == -2 || height_r == -2){
			return -2;
		}
		return height_l >= height_r ? height_l : height_r;
	}
}

List *getList_BinaryTree(BinaryTree *t){
	List *list = create_List();
	traverseInorder_BinaryTree(t->root, list->head);
	return list;
}

//Inorder traverses the tree and returns the data in a linked list. Untested.
ListNode *traverseInorder_BinaryTree(TreeNode *n, ListNode* cur){
	
	if(!n->left && !n->right){
		ListNode *temp = malloc(sizeof(ListNode));
		temp->data = n->data;
		cur = temp;
		return cur;
	}
	
	traverseInorder_BinaryTree(n->left, cur);
	
	cur = traverseInorder_BinaryTree(n, cur);
	ListNode *temp = malloc(sizeof(ListNode));
	temp->next = NULL;
	cur->next = temp;
	temp->data = n->data;
	
	traverseInorder_BinaryTree(n->right, cur);
	return cur;
}

short isSymmetric_BinaryTree(BinaryTree *tree){
	return tree == NULL ? 1 : checkSymmetric(tree->root->left, tree->root->right);
}

short checkSymmetric(TreeNode *subtree0, TreeNode *subtree1){
	if(!subtree0 && !subtree1){
		return 1;
	}else if(subtree0 && subtree1){
		return (subtree0->data == subtree1->data) 
					&& checkSymmetric(subtree0->left, subtree1->right) 
					&& checkSymmetric(subtree0->right, subtree1->left);
	}
	return 0;
}


typedef struct LCAHelperPair{
	int n;
	TreeNode *node;
}Pair;


//this is very cool - because I still didn't understand it properly
Pair LCAHelper(TreeNode* root, TreeNode *n1, TreeNode *n2){
	if(!root){
		Pair p = {0, NULL};
		return p;
	}
	
	Pair left_pair = LCAHelper(root->left, n1, n2);
	if(left_pair.n == 2){
		return left_pair;
	}
	
	Pair right_pair = LCAHelper(root->right, n1, n2);
	if(right_pair.n == 2){
		return right_pair;
	}
	
	int num_target_nodes = left_pair.n + right_pair.n + (root == n1) + (root == n2);
	Pair p = {num_target_nodes, num_target_nodes == 2 ? root : NULL};
	return p;
}



TreeNode *getLCA_BinaryTree(BinaryTree *tree, TreeNode *n1, TreeNode *n2){
	Pair p = LCAHelper(tree ? tree->root : NULL, n1, n2);
	return p.node;
}


BinaryTree* getTreeFromTraversal(int *inorder, int *preorder, int n){
	BinaryTree *tree = create_BinaryTree();
	tree->root = get_Node();
	getTreeFromTraversalHelper(tree->root, inorder, preorder, n);
	
	//printf("%p", tree->root);
	return tree;
}

void getTreeFromTraversalHelper(TreeNode* root, int *inorder, int *preorder, int n){
	
	if(!n){
		return;
	}

	root->data = preorder[0];
	//printf("\ndata=%c\n",root->data);
	/*if(inorder[0] == inorder[n-1]){
		return;
	}*/
	
	int i;
	for(i=0; i<n; ++i){
		if(preorder[0] == inorder[i]){
			break;
		}
	}
	
	static int pre = 1;
	
	//printf("\nn=%d i=%d pre=%d data=%c\n",n, i, pre++, root->data);
	//asumming things are not unexpected
	root->left = get_Node();
	root->right = get_Node();
	
	getTreeFromTraversalHelper(root->left, inorder, &(preorder[1]), i);
	getTreeFromTraversalHelper(root->right, &(inorder[i+1]), &(preorder[i+1]), n-(i+1));
}

