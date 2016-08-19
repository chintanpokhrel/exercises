#include <stdio.h>

int main(){
	char a[15];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c'; a[3] = 'a';
	a[4] = 'b'; a[5] = 'b';
	a[6] = 'a';
	printf("Before: %s\n", a);
	int n=7;
	//remove b and count a
	int i, k=0;
	int acount = 0;
	int bcount = 0;
	for(i=0; i<7; ++i){
		if(a[i] == 'a'){
			++acount;
		}
		if(a[i]!='b'){
			a[k++] = a[i];
		}else{
			++bcount;
		}
		
	}
	printf("After removing b: %s\n", a);
	printf("acount: %d\nbcount: %d\n", acount, bcount);
	//replace a with d d
	int count = n + acount - bcount;
	
	k = count - 1;
	for(i = n-1-bcount; i>=0; --k, --i){
		if(a[i] == 'a'){
			a[k] = 'd';
			a[k-1] = 'd'; --k;
		}else{
			a[k] = a[i];
		}
	}	
	printf("After: %s\n", a);
}
