#include "insertion_sort.h"
#include <stdio.h>

int insertion_sort(int *a, int n){
	int i=1;
	int j=i;
	int t;
	for(i=1; i<n; ++i){
		for(j=0; j<i; ++j){
			if(a[i]<a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	return 0;
}

int improved_insertion_sort(int *a, int n){
	int i=1;
	int j;
	int t;
	for(i=1; i<n; ++i){
		j = binary_search(a, i+1, a[i]);
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	return 0;
}

int binary_search(int *a, int n, int v){
	int left = 0;
	int right = n-1;
	int middle = (right - left)/2;
	
	while(left != right &&(middle != n-1 || middle !=0))
	{
		if(a[middle] == v )
		{
			return middle;
			
		}else if(a[middle]<v){
			if(a[middle+1]>v){
				return middle;
			}
			left = middle + 1;
			middle = (right - left)/2 + left;
		}else{
			if(a[middle-1]<=v){
				return middle-1;
			}
			right = middle-1;
			middle = (right - left)/2;
		}
	}
	if(a[left]>v){
		return 0;
	}else{
		return n-1;
	}
}


