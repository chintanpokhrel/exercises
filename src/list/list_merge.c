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
	int b[] = {4, 7, 10, 12};
	Node* list2;
	list2 = malloc(sizeof(Node));
	cur = list2;
	cur->data = b[0];
	cur->next = NULL;
	for(i=1; i<4; ++i){
		Node* new_node = malloc(sizeof(Node));
		new_node->data = b[i];
		new_node->next = NULL;
		cur->next = new_node;
		cur = cur->next;
	}
	printf("List 2: ");
	print(list2);
	//merging
	Node* curl1 = list1;
	Node* curl2 = list2;
	while(curl1->next){
		if(curl1->next->data >= curl2->data){
			Node* temp = curl2->next;
			curl2->next = curl1->next;
			//curl2 = curl1->next;
			curl1->next = curl2;
			curl2 = temp;
		}
		curl1 = curl1->next;
	}
	while(curl2){
		Node* temp = curl2->next;
		curl1->next = curl2;
		curl2->next = NULL;
		curl2 = temp;
		curl1 = curl1->next;
	}
	printf("List 1 after merge: ");
	print(list1);
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
