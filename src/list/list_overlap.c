#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void print(Node*);
Node* get_overlap(Node*, Node*);

int main(){
	int a[] = {2, 3, 5, 9, 11};
	Node *list1;
	int i;
	
	list1 = malloc(sizeof(Node));
	Node* cur = list1;
	cur->data = a[0];
	cur->next = NULL;
	for(i=1; i<5; ++i){
		Node* new_node = malloc(sizeof(Node));
		new_node->data = a[i];
		new_node->next = NULL;
		cur->next = new_node;
		cur = cur->next;
	}
	
	printf("List 1: ");
	print(list1);
	
	int b[] = {4, 7, 10};
	Node* list2;
	list2 = malloc(sizeof(Node));
	cur = list2;
	cur->data = b[0];
	cur->next = NULL;
	for(i=1; i<3; ++i){
		Node* new_node = malloc(sizeof(Node));
		new_node->data = b[i];
		new_node->next = NULL;
		cur->next = new_node;
		cur = cur->next;
	}
	
	//overlapping
	list2->next->next->next = list1->next->next;
	printf("List 2: ");
	print(list2);
	
	//find overlapping
	Node* overlap = get_overlap(list1, list2);
	print(overlap);
	
	return 0;
}

Node* get_overlap(Node* list1, Node* list2){
	if(!list1 || !list2){
		return NULL;
	}
	Node* cur1 = list1;
	Node* cur2 = list2;
	
	int l1=1;
	int l2=1;
	while(cur1->next){
		++l1;
		cur1 = cur1->next;
	}
	while(cur2->next){
		++l2;
		cur2 = cur2->next;
	}
	
	//if tail is not the same then return null
	if(cur1 != cur2){
		return NULL;
	}
	
	cur1 = list1;
	cur2 = list2;
	
	if(l1>=l2){
		int dl = l1-l2;
		while(dl){
			cur1 = cur1->next;
			--dl;
		}
	}else{
		int dl = l2-l1;
		while(dl){
			cur2 = cur2->next;
			--dl;
		}
	}
	
	while(cur1 != cur2){
		cur1 = cur1->next;
		cur2 = cur2->next;
	}	
	
	return cur1;	
}

void print(Node* n){
	Node* cur = n;
	while(cur){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
