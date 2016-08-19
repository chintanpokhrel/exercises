#include <stdio.h>
#include "stack.h"
#include <ctype.h>
#include <string.h>

int main(){
	Stack *stack = create_stack();
	char a[] = {"3,4,+,2,*,1,+"};
	int n = 13;
	char *tokens[2] = strtok(a, ",");
	stack_push(
	eval_rpn(stack, 	
	printf("Push complete!\n");
	return 0;
}
