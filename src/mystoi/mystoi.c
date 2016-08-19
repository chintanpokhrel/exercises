#include <stdio.h>
#include <math.h>

int mystoi(char*, int);

int error = -1;

int main(){
	char a[] = "123";
	char b[] = "aloo";
	
	int n;
	n = mystoi(a, 3);
	if(error==-1){
		printf("123 has become %d\n", n);
	}else{
		printf("Cannot be parsed into an integer!\n");
		error = -1;
	}
	n = mystoi(b, 4);
	if(error==-1){
		printf("123 has become %d\n", n);
	}else{
		printf("Cannot be parsed into an integer!\n");
		error = -1;
	}
	
	return 0;
}

int mystoi(char *a, int n){
	int num = 0;
	int i, j;
	for(i=n-1, j=0; i>=0; --i, ++j){
		switch(a[i]){
			case '0':
				num += 0*pow(10, j); break;
			case '1':
				num += 1*pow(10, j); break;
			case '2':
				num += 2*pow(10, j); break;
			case '3':
				num += 3*pow(10, j); break;
			case '4':
				num += 4*pow(10, j); break;
			case '5':
				num += 5*pow(10, j); break;
			case '6':
				num += 6*pow(10, j); break;
			case '7':
				num += 7*pow(10, j); break;
			case '8':
				num += 8*pow(10, j); break;
			case '9':
				num += 9*pow(10, j); break;
			default:
				error = 1;
				return -1;
		}
	}
	return num;
}
