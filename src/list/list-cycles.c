#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void print(Node*);
Node* get_cycle(Node*);

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
	cur->next = list1->next->next; //making a cylce
	
	Node* cycle = get_cycle(list1);
	if(cycle){
		printf("Found a cycle at: %p Data: %d\n", cycle, cycle->data);
	}else{
		printf("Did not find a cycle.");
	}
	
	return 0;
}

Node* get_cycle(Node* list){
	Node* cur1 = list;
	int i=1;
	while(cur1){
		Node* cur2 = list;
		int j=1;
		while(cur2 && j<i){
			if(cur2==cur1){
				return cur2;
			}
			cur2=cur2->next;
			++j;
		}
		cur1 = cur1->next;
		++i;
		printf("i: %d, j: %d\n", i, j);
	}
	return NULL;
}

void print(Node* n){
	Node* cur = n;
	while(cur){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
