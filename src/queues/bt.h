#ifndef _binary_tree_h
#define _binary_tree_h
#include "list.h"
#include <stdlib.h>


typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

typedef struct BinaryTree{
	struct TreeNode *root;
}BinaryTree;

BinaryTree* create_BinaryTree();

TreeNode* get_Node();

void destroy_BinaryTree(BinaryTree*);

short isBalanced_BinaryTree(BinaryTree *);

int findHeight(TreeNode*);

ListNode *traverseInorder_BinaryTree(TreeNode *, ListNode *);

List *getList_BinaryTree(BinaryTree *);

short isSymmetric_BinaryTree(BinaryTree *);

short checkSymmetric(TreeNode *, TreeNode *);

//given two nodes in a binary tree, get their Lowest Common Ancestor
TreeNode *getLCA_BinaryTree(BinaryTree *tree, TreeNode *, TreeNode *);

BinaryTree* getTreeFromTraversal(int *, int *, int); 

void getTreeFromTraversalHelper(TreeNode *, int *, int *, int);


#endif
