#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    int valid = 1;
    valid = valid && (a0>=1 && a0<=100);
    valid = valid && (a1>=1 && a1<=100);
    valid = valid && (a2>=1 && a2<=100);
    valid = valid && (b0>=1 && b0<=100);
    valid = valid && (b1>=1 && b1<=100);
    valid = valid && (b2>=1 && b2<=100);
	
	if(!valid){
		return 0;
	}
	
    int alice = 0;
    alice += (a0 > b0) + (a1 > b1) + (a2 > b2);
    int bob = 0;
    bob = (b0 > a0) + (b1 > a1) + (b2 > a2);
    printf("%d %d", alice, bob);
    
    return 0;
}
