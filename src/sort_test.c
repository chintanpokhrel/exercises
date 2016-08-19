#include "sort_test.h"
//#include "merge-sort.h"
#include "max_heap.h"
//#include "heap_sort.h"
#include <stdio.h>


int sort_test(){
	int a[] = {20, 18, 17, 21, 19, 15, 13, 25, 24, 5, 10, 9, 8, 7, 6, 30, 4, 3, 2, 1};
	//int b[20];
	
	//printf("Count = %d\n", merge_sort(a, 20, b));
	//heap_sort(a, 10);
	print_array(a, 20);
	return 0;
}

void build_max_heap_test(){
	int a[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	build_max_heap(a, 10);
	print_array(a, 10);
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
