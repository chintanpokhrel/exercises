#include <stdio.h>

int find_smallest(int *a, int n){
	if(n==0){
		return -1;
	}
	
	if(n==1){
		return 0;
	}
	
	int l = 0, m = -1, r = n-1;
	while(l<=r){
		m = l + (r-l)/2;
		if(a[m] <= a[(m-1+n)%n] && a[m] <= a[(m+1+10)%10]){
			return m;
		}else if(a[m] <= a[r]){
			r = m;
		}else if(a[m] >= a[l]){
			l = m;
		}
	}
	
	return -1;
}

//doesn't work when elements are repeated
int main(){
	int arr1[] = {};
	printf("Expected -1, got: %d\n", find_smallest(arr1, 0));
	int arr2[] = {1};
	printf("Expected 0, got: %d\n", find_smallest(arr2, 1));

	int arr3[] = {1, 2};
	printf("Expected 0, got: %d\n", find_smallest(arr3, 3));
	int arr4[] = {2, 2};
	printf("Expected 0, got: %d\n", find_smallest(arr4, 2));
	int arr5[] = {4, 5, 6, 1, 2, 3};
	printf("Expected 3, got: %d\n", find_smallest(arr5, 6));
	int arr6[] = {6, 6, 6, 6, 6, 6};
	printf("Expected 0, got: %d\n", find_smallest(arr6, 6));

	int arr9[] = {1, 2, 3, 4, 4, 5};
	printf("Expected 0, got: %d\n", find_smallest(arr9, 6));
	
	return 0;
}
