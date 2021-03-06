#include <stdio.h>

int delete_dup(int[], int);

int main(){
	int arr[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
	int n = 9;
	printf("Before: ");
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", arr[i]);
	}
	
	int k = delete_dup(arr, 9);
	printf("\nAfter: ");
	
	for(i=0; i<k; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int delete_dup(int a[], int n){
	int i, k;
	for(i=1, k=1; i<n; ++i){
		if(a[i]-a[i-1]){ //if not the same
			a[k] = a[i];
			++k;
		}
	}
	return k;
}
