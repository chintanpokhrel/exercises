#include <stdio.h>

int first_occurence(int *arr, int n, int k){
	
	if(n<=0){
		return -1;
	}
	
	int first=-1;
	int l=0, u=n-1, m;
	while(l<=u){
		m = l+ (u-l)/2;
		if(k <= arr[m]){
			if(k==arr[m]){
				//if((first != -1 && m < first) || first == -1){
					first=m;
				//}
			}
			if(l==u){
				break;
			}
			u=m;
				
		}else{
			l=m+1;
		}
	}
	return first;
}

int main(){

	int arr1[] = {};
	printf("Expected -1, got: %d\n", first_occurence(arr1, 0, 5));
	int arr2[] = {1};
	printf("Expected 0, got: %d\n", first_occurence(arr2, 1, 1));
	printf("Expected -1, got: %d\n", first_occurence(arr2, 1, 5));
	
	int arr3[] = {1, 2};
	printf("Expected 1, got: %d\n", first_occurence(arr3, 2, 2));
	int arr4[] = {2, 2};
	printf("Expected 0, got: %d\n", first_occurence(arr4, 2, 2));
	int arr5[] = {1, 2, 3, 3, 4, 5};
	printf("Expected 2, got: %d\n", first_occurence(arr5, 6, 3));
	int arr6[] = {1, 2, 3, 4, 5, 6};
	printf("Expected 2, got: %d\n", first_occurence(arr6, 6, 3));
	int arr7[] = {6, 6, 6, 6, 6, 6};
	printf("Expected 0, got: %d\n", first_occurence(arr7, 6, 6));
	int arr8[] = {6, 6, 6, 6, 6, 6};
	printf("Expected -1, got: %d\n", first_occurence(arr8, 6, 10));
	int arr9[] = {1, 2, 3, 4, 4, 5};
	printf("Expected 3, got: %d\n", first_occurence(arr9, 6, 4));
	
	return 0;
}
