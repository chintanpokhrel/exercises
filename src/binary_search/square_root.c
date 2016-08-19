#include <stdio.h>

int square_root(int n){
	if(n==0){
		return 0;
	}
	int l=1, r = n;
	while(l<r){
		int m = l + (r-l)/2;
		int sq = m*m;
		if(sq==n){
			return m;
		}else if(sq<n){
			if(l<m){
				l=m;
			}else{
				break;	
			}			
		}else{
			r=m;
		}	
	}
	return l;
}

int main(){
	printf("Expected 0 got %d\n", square_root(0));
	printf("Expected 1 got %d\n", square_root(1));
	printf("Expected 1 got %d\n", square_root(2));
	printf("Expected 7 got %d\n", square_root(49));
	printf("Expected 2 got %d\n", square_root(7));
	printf("Expected 6 got %d\n", square_root(37));
	return 0;
}
