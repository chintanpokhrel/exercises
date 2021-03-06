#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int num = 1001;
	printf("Check palindrome by reversing: %d\n", palin_by_rev(num));
	printf("Check palindrome by digit comparison: %d\n", palin_by_comp(num));
	return 0;
}

int palin_by_rev(int num){
	int n = num;
	int rev = 0;
	while(n){
		int t = n%10;
		n = n/10;
		rev *= 10;
		rev += t;
	}
	return !(rev == num);
}

int palin_by_comp(int num){
	int digits = floor(log10(num)) + 1;
	int n = num;
	int mask = pow(10, digits-1);
	while(n){		
		int l = n%10;
		int r = n/mask;
		if(l!=r){
			return 0;	
		}
		n = n%mask;
		n = n%10;	
		mask /= 100;	
	}
	return 1;
}
