#include "../max_heap.h"
#include <stdio.h>


void sort_almost_sorted(int *arr, int n, int *karr, int k){
	int i;
	for(i=0; i<k+1; ++i){
		karr[i] = arr[i];
	}
	build_max_heap(karr, k+1);
	for(;i<n; ++i){
		int max = extract_max(karr, k+1);
		printf("%d ", max);
		insert_max_heap(karr, k+1, arr[i]);
	}
	int remaining = k+1;
	for(i=0; i<k+1; ++i){
		printf("%d ",extract_max(karr, remaining--));
		
	}
	printf("\n");
}
