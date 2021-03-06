#ifndef _binary_search_tree_h
#define _binary_search_tree_h


typedef struct node{
	int val;
	int height;
	struct node* lchild;
	struct node* rchild;
}node;


typedef struct BST{
	struct node* root;
}BST;


BST* create_bst();

int build_bst(BST*, int*, int);

int insert_node(BST*, int);

node *find_max_node(node *);

int find_max(BST*);

node *search(BST*, int); //return pointer to the node that contains the value

void inorder_traversal(BST*, int*);

void inorder(node*, int*);

node *find_min_node(node *);

int find_min(BST *);

node *get_successor(BST *, int);

node *get_predecessor(BST *, int);
//destroy is missing

#endif
