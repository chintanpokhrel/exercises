#include "insertion_test.h"
#include "insertion_sort.h"
#include <stdio.h>


int insertion_sort_test(){
	int a[] = {10, 1, 8, 7, 9, 4, 3, 5, 6, 2};
	int b[] = {10, 1, 8, 7, 9, 4, 3, 5, 6, 2};
	insertion_sort(a, 10);
	print_array(a, 10);
	improved_insertion_sort(b, 10);
	print_array(a, 10);
}

int binary_search_test(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int test[] = {-1, 0, 1, 2.5, 4, 6.5, 7.6, 9.9, 9, 10.1, 11, 12};
	int test_expected[] = {0, 0, 0, 1, 3, 5, 6, 8, 8, 9, 9, 9};
	int res;
	int n = 10;
	int i;
	for(i = 0; i<12; ++i){
		res = binary_search(a, n, test[i]);
		if(res==test_expected[i]){
			printf("Test Passed: (passed, expected): (%d, %d)\n", test[i], test_expected[i]);
		}else{
			printf("Test Failed: (passed, expected, got): (%d, %d, %d)\n", test[i], test_expected[i], res);
			return -1;
		}	
	}
	return 0;
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
