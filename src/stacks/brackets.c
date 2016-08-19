#include <stdio.h>
#include "stack.h"

int main(){
	Stack *stack = create_stack();
	char *a = "[]{}{{}}";
	char c ;
	int n=8;
	int i=0;
	for(i=0; i<n; ++i){
		switch(a[i]){
			case '{':
			case '(':
			case '[': 
				stack_push(stack, a[i]); 
				if(overflow){
					overflow = 0;
					printf("Stack overflow");
					return;
				}
				break;
			case '}': 
				c = stack_pop(stack);
				printf("Popped: %c\n", c);
				if(underflow){
					underflow = 0;
					printf("Stack underflow");
					return;
				}
				if(c!='{'){
					printf("Not well formed!");
					return;
				}
				break;
			case ')':
				if(underflow){
					underflow = 0;
					printf("Stack underflow");
					return;
				}
				
				c = stack_pop(stack);
				printf("Popped: %c\n", c);
				if(c!='('){
					printf("Not well formed!");
					return;
				}
				break;
			case ']':
				if(underflow){
					underflow = 0;
					printf("Stack underflow");
					return;
				}				
				c = stack_pop(stack);
				printf("Popped: %c\n", c);
				if(c!='['){
					printf("Not well formed!");
					return;
				}
				break;
		}
		
	}
	if(stack_empty(stack)){
		printf("Well formed! : %s", a);
		return;
	}
	
	printf("Not well formed!");
		
	return 0;
}
