#ifndef _list_h
#define _list_h

typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode;

typedef struct List{
	ListNode *head;
	ListNode *tail;
}List;

List *create_List();
void destroy_List(List *);
List *push_List(List *, int);
void sort_List(List *);

void print_List(List *);

#endif
