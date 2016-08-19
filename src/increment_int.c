#include <stdio.h>

void increment(int*, int);

int main(){
	int arr[] = {9, 9, 9, 9};
	int n = 4;
	increment(arr, 4);
	printf("%d%d%d%d", arr[0], arr[1], arr[2], arr[3]);
	return 0;
}

void increment(int* a, int n){
	int i;
	for(i=n-1; i>=0; --i){
		int t = a[i] + 1;
		a[i] = t%10;
		if(t<10){
			break;
		}
	}
}
