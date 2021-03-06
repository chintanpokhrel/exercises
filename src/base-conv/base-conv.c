#include <stdio.h>
#include <math.h>

void base_conv(char *a, int n1, int b1, int b2){
	int i;
	int numb1 = 0;
	printf("Before: %s\n", a);
	//stoi to b1
	for(i=0; i<n1; ++i){
		int digit = a[i] - '0';
		numb1 = numb1*10 + digit;
	}
	printf("in b1: %d", numb1);
	//b1 to dec
	int dec = 0;
	i=0;
	while(numb1){
		dec += (numb1%10) * pow(b1, i++);
		numb1 /= 10;
	}
	printf("in dec: %d", dec);
	//dec to b2
	int numb2 = 0;
	i=n1-1;
	while(dec){
		int digit = dec % b2;
		switch(digit){		
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8: 
			case 9: a[i] = '0'+digit; break;
			case 10: a[i] = 'A'; break;
			case 11: a[i] = 'B'; break;
			case 12: a[i] = 'C'; break;
			case 13: a[i] = 'D'; break;
			case 14: a[i] = 'E'; break;
			case 15: a[i] = 'F'; break;
		}
		dec /= b2; --i;
	}
	printf("After: %s\n", a);
}

int main(){
	char a[] = "615";
	base_conv(a, 3, 7, 13);
	return 0;
}

