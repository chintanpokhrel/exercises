#include <stdio.h>

//assumes min_max arr has two places to put the min and max value - in that order
//Caveat: sounds like minimax but has got nothing to do with it
void min_and_max(int *arr, int n, int *min_max){
	if(n==0){
		return;
	}
	min_max[0] = arr[0];
	min_max[1] = arr[0];
	
	int i;
	for(i=0; i<n-1; i+=2){
		//cmp current two elements i.e. at i and at i+1
		int tmp_min, tmp_max;
		
		if(arr[i] <= arr[i+1]){
			tmp_min = arr[i];
			tmp_max = arr[i+1];
		}else{
			tmp_min = arr[i+1];
			tmp_max = arr[i];
		}
		
		if(tmp_min < min_max[0]){
			min_max[0] = tmp_min;
		}
		if(tmp_max > min_max[1]){
			min_max[1] = tmp_max;
		}
	}
	
	// case when n is odd
	if(n%2){
		if(arr[i] < min_max[0]){
			min_max[0] = arr[i];
		}else{
		/*if(arr[i] > min_max[1]){ 
		//if last element 
		can be both min and max, it means all elements are equal and min and max are correctly assigned already*/
			min_max[1] = arr[i];
		}
	}
}

int main(){
	int min_max[2];
	int arr1[] = {};
	min_and_max(arr1, 0, min_max);
	printf("Expected nothing, got: %d,%d\n", min_max[0], min_max[1]);
	int arr2[] = {1};
	min_and_max(arr2, 1, min_max);
	printf("Expected 1, 1, got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr3[] = {1, 2};
	min_and_max(arr3, 2, min_max);
	printf("Expected 1,2 got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr4[] = {2, 2};
	min_and_max(arr4, 2, min_max);
	printf("Expected 2,2, got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr5[] = {1, 2, 3, 3, 4, 5};
	min_and_max(arr5, 6, min_max);
	printf("Expected 1,5, got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr6[] = {1, 2, 3, 4, 5, 6};
	min_and_max(arr6, 6, min_max);
	printf("Expected 1,6, got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr7[] = {6, 6, 6, 6, 6};
	min_and_max(arr7, 5, min_max);
	printf("Expected 6,6 got: %d,%d\n", min_max[0], min_max[1]);
	
	int arr9[] = {1, 2, 3, 4, 4, 5};
	min_and_max(arr9, 6, min_max);
	printf("Expected 1,5 got: %d,%d\n", min_max[0], min_max[1]);
	
	return 0;
}


