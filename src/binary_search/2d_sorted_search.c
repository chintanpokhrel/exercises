#include <stdio.h>

#define MAX_COLS 4

int TwoDSearch(int a[][MAX_COLS], int m, int k){
	int n=MAX_COLS;
	if(m==0 || n==0){
		return -1;
	}
	int i, l1, r1, l2, r2, m1, m2;
	for(i=0; i<m; ++i){
		l1 = i, r1 = n-1;
		l2 = i+1, r2 = m-1;
		
		while(l1<=r1){
			m1 = l1 + (r1-l1)/2;
			printf("i=%d l1=%d r1=%d m1=%d, a[i][m1]=%d \n", i, l1, r1, m1, a[i][m1]);
			getchar();
			if(a[i][m1]==k)
				return 1;
			else if(a[i][m1]>k){
				r1 = m1-1;
			}else{
				l1 = m1+1;
			}

		}
		
		while(l2<=r2){
			m2 = l2 + (r2-l2)/2;
			if(a[m2][i]==k)
				return 1;
			else if(a[m2][i]>k){
				r2 = m2-1;
			}else{
				l2 = m2+1;
			}
		}

	}
	return 0;
}

int print_array(int a[][MAX_COLS], int m){
	int i, j, n = MAX_COLS;
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	int arr1[][MAX_COLS] = {};
	printf("Expected -1, got: %d\n", TwoDSearch(arr1, 0, 5));
	int arr2[][MAX_COLS] = {{1, 3, 8, 9}};
	printf("Expected 1, got: %d\n", TwoDSearch(arr2, 1, 1));
	printf("Expected 0, got: %d\n", TwoDSearch(arr2, 1, 5));
	
	int arr3[][MAX_COLS] = {{1, 2, 4, 6},
							{5, 4, 6, 7},
							{8, 9, 10, 11}};
	print_array(arr3, 3);
	printf("Expected 1, got: %d\n", TwoDSearch(arr3, 3, 9));
	/*int arr4[][MAX_COLS] = {2, 2};
	printf("Expected 0, got: %d\n", TwoDSearch(arr4, 3, 2));
	int arr5[][MAX_COLS] = {1, 2, 3, 3, 4, 5};
	printf("Expected 2, got: %d\n", TwoDSearch(arr5, 6, 3));
	int arr6[][MAX_COLS] = {1, 2, 3, 4, 5, 6};
	printf("Expected 2, got: %d\n", TwoDSearch(arr6, 6, 3));
	int arr7[][MAX_COLS] = {6, 6, 6, 6, 6, 6};
	printf("Expected 0, got: %d\n", TwoDSearch(arr7, 6, 6));
	int arr8[][MAX_COLS] = {6, 6, 6, 6, 6, 6};
	printf("Expected -1, got: %d\n", TwoDSearch(arr8, 6, 10));
	int arr9[][MAX_COLS] = {1, 2, 3, 4, 4, 5};
	printf("Expected 3, got: %d\n", TwoDSearch(arr9, 6, 4));*/

	return 0;
}
