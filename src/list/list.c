#include "list.h"
#include <stdlib.h>

#include <stdio.h>

void print_List(List *l){
	if(!l){
		return;
	}
	ListNode *cur = l->head;
	while(cur){
		printf("%d --> ", cur->data); 
		cur = cur->next;
	}
	printf("\n");
}

List *create_List(){
	List *list = malloc(sizeof(List));
	if(list){
		list->head = NULL;
		list->tail = NULL;
	}
	return list;
}

void destroy_List(List *list){
	ListNode *cur = list->head;
	while(cur){
		ListNode *temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(list);
}

List *push_List(List *list, int data){
	if(!list){
		return NULL;
	}
	ListNode *new_node = malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->next = NULL;
	
	if(!list->head){
		list->head = new_node;
		list->tail = new_node;
	}else{
		list->tail->next = new_node;
		list->tail = new_node;
	}
	return list;
}

//merge sort on linked list
void merge_List(ListNode *l, ListNode *m, ListNode *r, List *list);
void _sort_List(ListNode *l, ListNode *r, List *list);

void sort_List(List *list){
	if(!list || !list->head || !list->tail){
		return;
	}
	_sort_List(list->head, list->tail, list);
}

void _sort_List(ListNode *l, ListNode *r, List *list){
	print_List(list);
	if(l == r){
		return;
	}
	ListNode *fast = l;
	ListNode *slow = l;
	while(fast->next != r && fast != r){
		fast = fast->next->next;
		slow = slow->next;
		printf("Fast: %d Slow: %d\n", fast->data, slow->data);
	}
	//printf("\n");
	//at this point slow is at the mid point
	//checks required here
	_sort_List(l, slow, list); 
	_sort_List(slow->next, r, list);
	merge_List(l, slow, r, list);
}

void merge_List(ListNode *l, ListNode *m, ListNode *r, List *list){
	ListNode *lcur = l,  *rcur = m->next;
	ListNode *lprev = NULL, *rprev = m;
	printf("Here in merge!\n");
	ListNode *end = r->next;
	while(rprev->next != end){
		if(lcur->data <= rcur->data){
			lprev = lcur;
			lcur = lcur->next;
		}else{
			if(!lprev){
				lprev = rcur;
				list->head = rcur;
			}
			rprev->next = rcur->next;
			rcur = rprev->next;
			lprev->next = lcur;
		}
	}
	if(!m->next){
		list->tail = m;
	}
}



