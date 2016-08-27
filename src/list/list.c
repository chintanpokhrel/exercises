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

//#define DEBUG

#ifdef DEBUG
#define LOG(x, ...) printf(x, ##__VA_ARGS__)
#define PRINT_LIST(x) print_List(x)
#else
#define LOG(x, ...)
#define PRINT_LIST(x)
#endif

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
//void merge_List(ListNode *l, ListNode *m, ListNode *r, List *list);
//void _sort_List(ListNode *l, ListNode *r, List *list);
void __sort_List(int l, int r, List *list);
void _merge_List(int l, int m, int r, List *list);


void sort_List(List *list){
	if(!list || !list->head || !list->tail){
		return;
	}
	//_sort_List(list->head, list->tail, list);
	ListNode *cur = list->head;
	int n = 0;
	while(cur){
		++n;
		cur = cur->next;
	}
	__sort_List(0, n-1, list);
}

void __sort_List(int l, int r, List *list){
	if(l>=r){
		return;
	}
	//to find m
	int m = l + (r-l)/2;
	
	__sort_List(l, m, list);
	__sort_List(m+1, r, list);
	LOG("Before Merge l: %d, m: %d, r: %d list->head: %d list: ", l, m, r, list->head->data);
	PRINT_LIST(list);
	_merge_List(l, m, r, list);	
	LOG("After Merge l: %d, m: %d, r: %d list->head: %d list: ", l, m, r, list->head->data);
	PRINT_LIST(list);
	//getchar();
}


void _merge_List(int l, int m, int r, List *list){

	ListNode *lptr = list->head;
	int i = 0;
	while(i != l){
		++i;
		lptr = lptr->next;
	}
	
	//to find rptr
	ListNode *rptr = list->head;
	i=0;
	while(i != r){
		++i;
		rptr = rptr->next;
	}
	
	//to find mptr
	ListNode *mptr = list->head;
	i=0;
	while(i != m){
		++i;
		mptr = mptr->next;
	}
	
	ListNode *lcur = lptr,  *rcur = mptr->next;
	ListNode *lprev = NULL;
	
	//to find lprev
	ListNode *cur = list->head;
	if(cur == lptr){
		lprev = NULL;
	}else{
		while(cur->next != lptr){
			cur = cur->next;
		}
		lprev = cur;
	}
	//printf("In merge lprev: %d\n", lprev->data);
	ListNode *end = rptr->next;
	while(mptr->next != end && lcur != mptr->next){
		if(lcur->data <= rcur->data){
			lprev = lcur;
			lcur = lcur->next;
		}else{
			if(!lprev){
				//move node at rcur to the beginning of the list
				lprev = rcur;
				mptr->next = rcur->next;
				rcur->next = lptr;
				list->head = rcur;
				rcur = mptr->next;
			}else{
				lprev->next = rcur;
				mptr->next = rcur->next;
				rcur->next = lcur;
				lprev = rcur;
				rcur = mptr->next;
			}
		}
	}
	if(!mptr->next){
		list->tail = mptr;
	}
}






