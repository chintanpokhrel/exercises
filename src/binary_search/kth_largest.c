#include <stdio.h>

//returns the index of the kth largest element
//how to ?
//1. sort and return the (k-1)th element O(n lg n) , O(n) additional storage (merge sort)
//2. use a maxheap, extract_max k elements, return the kth one O(n lg k) time, requires O(n) additional storage
//3. use a pivot
int kth_largest(int *arr, int n, int k){
	if(n==0){
		return -1;
	}
	int i, pivot = arr[n/2];
	for(i=0; i<n; ++i){
		
	}
}
