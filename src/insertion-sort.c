#include <stdio.h>
#include "print_array.h"

int main(){
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//insertion sort
	//insert each element into the correct position

	int i=1;
	int j=i;
	int t;
	for(i=1; i<10; ++i){
		for(j=0; j<i; ++j){
			if(a[i]<a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			//swap a[i] and a[i-1]
			}
		}
		
	}
	print_array(a, 10);
	return 0;
}
