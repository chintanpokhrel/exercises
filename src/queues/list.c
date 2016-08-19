#include "list.h"
#include <stdlib.h>

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
	ListNode *new_node = malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->next = NULL;
	
	if(!list->head){
		list->head = new_node;
	}
	
	list->tail->next = new_node;
	list->tail = new_node;
	return list;
}

