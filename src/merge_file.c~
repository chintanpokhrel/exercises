#include "max_heap.h"
#include "merge_file.h"
#include <stdio.h>
void print_array(int *arr, int n);

//assumes enough space is there in merged is merge to hold all the data, maybe also assumes square matrix
void merge_sorted_files(int data[][COL_SIZE], int n, int *merged){
	int i=0, k=COL_SIZE;
	int temp[COL_SIZE];
	int j, x;
	for(j=0; j<k; j++){
			temp[j] = data[j][0];
	}
		
	for(x = 1; x<n; ++x){
		for(j=0; j<k; j++){
			int max = extract_max(temp, k);
			
			insert_max_heap(temp, k, data[j][x]);
			
			merged[i] = max; ++i;
		}	
	}

	for(j=0; j<COL_SIZE; ++j){
		merged[i++] = extract_max(temp, k--);
	}
}

/*void print_array(int *arr, int n){
	int x;
	for(x=0; x<COL_SIZE; ++x){
		printf("%d ", arr[x]);
	}
	printf("\n");
}*/

/*how to merge
build a max heap, extract max and insert from next array
what to put in max heap
data[j][] */
