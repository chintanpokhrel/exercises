#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void print(Node*);
Node* even_odd_merge(Node*);

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
	list1 = even_odd_merge(list1);
	printf("List 1 after even odd merge: ");
	print(list1);
	return 0;
}


Node* even_odd_merge(Node* list){
	Node *list1 = list, *list2 = list->next;
	list = list2->next;
	list1->next = NULL, list2->next = NULL;
	Node *even = list;
	Node *odd = even->next;
	Node *curl1 = list1, *curl2 = list2;
	while(even && odd){
		curl1->next = even;
		list = even->next;
		even->next = NULL;
		curl1 = curl1->next;
		
		curl2->next = odd;
		list = odd->next;
		odd->next = NULL;
		curl2 = curl2->next;
		
		even = list, odd = even->next;
		
		printf("List 1: ");
		print(list1);
		printf("List 2: ");
		print(list2);
	}
	
	if(even){
		curl1->next = even;
		list = NULL;
		even->next = NULL;
		curl1 = curl1->next;
	}
	
	printf("List 1: ");
	print(list1);
	printf("List 2: ");
	print(list2);
	
	//merging - actually concatenating
	curl2 = list2;
	list2 = NULL;
	list = list1;
	list1 = NULL;
	while(curl2){
		Node* t = curl2->next;
		curl2->next = NULL;
		curl1->next = curl2;
		curl1 = curl1->next;
		curl2 = t;
	}
	return list;
}

void print(Node *n){
	Node *cur = n;
	while(cur){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

























