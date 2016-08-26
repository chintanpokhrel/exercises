#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *, int, int *);
void _merge_sort(int *, int, int, int *);
void merge(int *, int, int, int, int *);
void copy(int *, int, int, int *);
void print_array(int *, int);

void merge_sort(int *a, int n, int *b){
	_merge_sort(a, 0, n-1, b);
}

void _merge_sort(int *a, int l, int r, int *b){
	int m = l + (r-l)/2;
	//printf("l= %d m= %d r= %d \n", l, m, r);

	if(l>=r){
		return;
	}

	_merge_sort(a, l, m, b);
	_merge_sort(a, m+1, r, b);
	
	//printf("Before merge: ");
	//print_array(a, r+1);
	merge(a, l, m, r, b);
	/*printf("After merge b: ");
	print_array(b, r+1);*/
	copy(a, l, r, b); 
	//printf("After copy: ");
	//print_array(a, r+1);
	//getchar();
	
}

void merge(int *a, int l, int m, int r, int *b){
	int i = l;
	int j = m+1;
	int k = 0;
	while(k<=r){
		if((a[i] <= a[j] || j>r ) && i<=m){
			b[k] = a[i++];
		}else{
			b[k] = a[j++];
		}
		++k;
	}
}

void copy(int *a, int l, int r, int *b){
	int i, j;
	for(i=l, j=0; i<=r; ++i, ++j){
		a[i] = b[j];
		//printf("Inside copy: a[i]=%d b[j]=%d i=%d j=%d \n", a[i], b[j], i, j);
	}
}

void merge_sort_inplace(int *, int);
void _merge_sort_inplace(int *, int, int,  int);
void merge_inplace(int *, int, int, int, int);

void merge_sort_inplace(int *a, int n){
	_merge_sort_inplace(a, 0, n-1, n);
}

void _merge_sort_inplace(int *a, int l, int r, int n){
	int m = l + (r-l)/2;
	//printf("l= %d m= %d r= %d \n", l, m, r);

	if(l>=r){
		return;
	}

	_merge_sort_inplace(a, l, m, n);
	_merge_sort_inplace(a, m+1, r, n);
	merge_inplace(a, l, m, r, n);
	//printf("l= %d m= %d r= %d n=%d\n", l, m, r, n);
	//print_array(a, n);
	//copy(a, l, r); 

}

void merge_inplace(int *a, int l, int m, int r, int n){
	int i, j;
	for(i=l, j=n; i<=m; ++i, ++j){
		a[j] = a[i];
	}
	i=n, j=m+1;
	int k=l;
	while(k <= r){
		if((i <= n + m - l) && (j>r || a[i] <= a[j])){
			a[k] = a[i++];
		}else{
			a[k] = a[j++];
		}
		++k;
	}
}

void print_array(int *a, int n){
	int i;
	for(i=0; i<n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

#define SIZE 20
int main(){
	int a[SIZE] = {9, 8, 10, 6, 15, 11, 34, 1, -1, 25};
	//int b[SIZE];
	printf("Before sort: ");
	print_array(a, SIZE-10);
	merge_sort_inplace(a, SIZE-10);
	printf("After sort: ");
	print_array(a, SIZE-10);
	return 0;
}
