#include "stack.h"
#include <stdio.h>

int main(){
	Stack *stack = create_stack();
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;
	int i;
	for(i=0; i<10; ++i){
		stack_push(stack, arr[i]);
		if(overflow){
			overflow = 0;
			printf("Stack Overflow!\n");
			break;
		}
	}
	printf("Push complete!\n");
	int data;
	
	for(i=0; i<=10; ++i){
		int max = stack_max(stack);
		if(underflow){
			underflow = 0;
			printf("Stack Underflow!\n");
			break;
		}
		printf("Max val: %d\n", max);
		data = stack_pop(stack);
		if(underflow){
			underflow = 0;
			printf("Stack Underflow!\n");
			break;
		}
		printf("%d ", data);
	}
	return 0;
}
