#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void print(Node*);
int delete_kth_last(Node*, int k);

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
	printf("Deleted data: %d\n", delete_kth_last(list1, 3));
	print(list1);
	return 0;
}
//constraint: can't record the length of the list
/*strategy: use two iterators cur1 and cur2
  Initially both point to the first node. Advance cur2 k nodes ahead
  and then advance each one by one until cur2 reaches the last node
  Now, cur1 is at the (k+1)th position from the last. So, delete cur1->next*/
int delete_kth_last(Node* list, int k){
	Node* cur1 = list;
	Node* cur2 = list;
	
	while(k--){
		cur2 = cur2->next;
	}
	
	while(cur2->next){
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	
	Node* t = cur1->next;
	cur1->next = t->next;
	int data = t->data;
	free(t);
	return data;
}

void print(Node* n){
	Node* cur = n;
	while(cur){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
