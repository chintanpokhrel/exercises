#include "max_heap.h"

void sort_inc_dec(int *arr, int n, int* karr, int k){
	if(n<2){
		return;
	}

	int i, j=1;
	int inc = 0;
	karr[0] = 0;
	for(i=1; i<n; ++i){
		if(inc && arr[i-1]-arr[i]>0){
			karr[j++]=i;
			inc = 0;
		}else if(!inc && arr[i-1]-arr[i]<0){
			karr[j++]=i;
			inc = 1;
		}
	}
	int j=1;
	int inc_dec = 1;
	while(k>1){
		merge(arr, 0, karr[j], karr[j+1], inc_dec);
		inc_dec = !inc_dec;
	}

}

merge(int *arr, int l, int m, int r){
	
}
