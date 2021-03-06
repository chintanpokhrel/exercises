#include "heap_sort.h"
#include "max_heap.h"

void perform_sort(int*, int);

void heap_sort(int* a, int n){
	build_max_heap(a, n);	
	perform_sort(a, n);
}

void perform_sort(int* a, int n){
	//int m = n;
	int t;
	if(n<1){
		return;
	}
	t = a[0];
	a[0] = a[n-1];
	a[n-1] = t;
	n = n-1;
	max_heapify(a, n, 0);
	perform_sort(a, n);
}
