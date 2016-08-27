#include "list.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	
	List *l = create_List();
	int i;
	//test 1
	printf("Test 1: normal test case: \n");
	int arr[] = {3, 8, 9, 4, 1, -1, 7, 11, 0, 1};
	for(i=0; i<10; ++i){
		push_List(l, arr[i]);
	}
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	//test 2
	printf("Test 2: empty list test case: \n");
	l = create_List();
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	//test 3
	printf("Test 3: single element test case: \n");
	l = create_List();
	push_List(l, 0);
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	//test 4
	printf("Test 4: equal elements test case: \n");
	l = create_List();
	for(i=0; i<10; ++i){
		push_List(l, -1);
	}
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	//test 5
	printf("Test 5: already ascending test case: \n");
	l = create_List();
	for(i=0; i<10; ++i){
		push_List(l, i);
	}
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	printf("Test 6: worst case - descending test case: \n");
	l = create_List();
	for(i=10; i>0; --i){
		push_List(l, i);
	}
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	
	return 0;
}
