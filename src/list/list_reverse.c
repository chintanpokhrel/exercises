#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void print(Node*);

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
	
	//reversing
	cur = list1->next;
	Node* list2 = list1;
	list2->next = NULL;
	while(cur){
		Node* t = cur->next;
		cur->next = list2;
		list2 = cur;
		//list2->next = NULL;
		cur = t;
	}
	printf("List 1 after reversing: ");
	print(list2);
	return 0;
}

void print(Node* n){
	Node* cur = n;
	while(cur){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
