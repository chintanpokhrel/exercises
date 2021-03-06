#include "merge-sort.h"

void split_and_merge(int*, int, int, int*);
void merge(int*, int, int, int, int*);
void copy(int*, int, int, int*);

static int count = 0;

int merge_sort(int*a, int n, int* b){
	split_and_merge(a, 0, n, b);
	return count;
}

void split_and_merge(int* a, int l, int r, int* b){

	int mid;
	
	if(r-l<2){
		return;
	}
	
	mid = (r+l)/2;
	split_and_merge(a, l, mid, b);
	split_and_merge(a, mid, r, b);
	merge(a, l, mid, r, b);
	copy(a, l, r, b);
}

void merge(int*a, int l, int mid, int r, int* b){
	int i = l, j = mid, k;
	for(k = l; k < r; ++k){
		++count;
		if(i<mid && (a[i] <=a [j] || j>=r)){
			b[k] = a[i];
			++i;
		}else{
			b[k] = a[j];
			++j;
		}
	}
}

void copy(int* a, int l, int r, int* b){
	int i;
	for(i=l; i<r; ++i){
		a[i] = b[i];
	}
}

