#include <stdio.h>
int* max_profit(int*, int, int*);
int* max_profit_better(int*, int, int*);

int main(){
	int arr[] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	int buy_sell[2];
	max_profit(arr, 10, buy_sell);
	printf("Buying Price> %d\nSelling Price> %d\n", buy_sell[0], buy_sell[1]);
	max_profit_better(arr, 10, buy_sell);
	printf("Buying Price> %d\nSelling Price> %d\n", buy_sell[0], buy_sell[1]);
	return 0;
}

int* max_profit(int* a, int n, int* buy_sell){
	int i, j;
	buy_sell[0] = a[0];
	buy_sell[1] = a[1];
	int max = buy_sell[1] - buy_sell[0];
	for(i = 0; i<n; ++i){
		for(j=i; j<n; ++j){
			if(a[j] - a[i] > max){
				buy_sell[0] = a[i];
				buy_sell[1] = a[j];
				max = buy_sell[1] - buy_sell[0];
			}
		}
	}
	
	//selling price - cost price
	return buy_sell;
}

int* max_profit_better(int* a, int n, int* buy_sell){
	//compute min price so far
	//compute profit 
	//find max
	//first with a naive approach
	int b[20];
	b[0] = a[0];

	//min so far
	int i;
	/*for(i=1; i<n; ++i){
		if(a[i]<b[i-1]){
			b[i] = a[i];
		}else{
			b[i] = b[i-1];
		}
	}*/
	
	//profit that could be made with with min so far
	//int c[20];
	//c[0] = 0;
	/*for(i = 1; i<n; ++i){
		c[i] = a[i] - b[i];
	}*/
	
	int pos = 0;
	int max = 0;
	/*for(i=1; i<n; ++i){
		if(c[i] > max){
			max = c[i];
			pos = i;
		}
	}*/
	int ci = 0;
	
	for(i=1; i<n; ++i){
		if(a[i]<b[i-1]){
			b[i] = a[i];
		}else{
			b[i] = b[i-1];
		}
		ci = a[i] - b[i];
		if(ci > max){
			max = ci;
			pos = i;
		}
	}

	buy_sell[0] = b[pos];
	buy_sell[1] = a[pos];
	return buy_sell;
}
