#include <stdio.h>

int main(int argc, char* argv[]){
	int n, m;
	m = 0;
	int i, j;
	int k = 0;
	printf("Enter number> ");
	scanf("%d", &n);
	printf("Enter i> ");
	scanf("%d", &i);
	printf("Enter j>: ");
	scanf("%d", &j);
	//Assuming i < j
	/*int t1;
	while(n>0){
		int t = n & ~(n-1);
		if(i==k){
			t = t << (j-i);
		}else if(j==k){
			t = t >> (j-i);
		}
		m = m | t;
		n = n & (n-1);
		++k;
	}*/
	if((n>>i & 1) ^ (n>>j & 1)){
		int mask = 1 << i | i<<j;
		m = n ^ mask;
	}else{
		m = n;
	}
	printf("Swapped bits: %d\n", m);  
}
