//#include "sort_test.h"
//#include "bst_test.h"

//#include "merge_file.h"
#include <stdio.h>
#include "sort_almost_sorted.c"
#include <stdlib.h>


int main()
{
	//build_max_heap_test();
	//merge_sort_test();
	//sort_test();
	//bst_test();
	/*int data[4][COL_SIZE];
	int i, j, k=16;
	
	for(i=0; i<COL_SIZE; ++i){
		for(j=0; j<COL_SIZE; ++j){
			data[j][i] = k--;
		}
	}
	
	printf("Data: \n");
	for(i=0; i<COL_SIZE; ++i){
		for(j=0; j<COL_SIZE; ++j){
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
					 
	int result[COL_SIZE*COL_SIZE];
	merge_sorted_files(data, COL_SIZE, result);

	for(i=0; i<COL_SIZE*COL_SIZE; ++i){
		printf("%d ", result[i]);
	}
	printf("\n");*/
	int data[] = {8, 5, 4, 6, 2, -1, 3};
	int *karr = calloc(2, sizeof(int));
	sort_almost_sorted(data, 7, karr, 2);
 	return 0;
}


