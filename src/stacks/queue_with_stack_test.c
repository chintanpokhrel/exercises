#include <stdio.h>
#include "queue_with_stack.h"

int main(){
	Queue *queue = create_Queue();
	enQueue(queue, 10);
	enQueue(queue, 15);
	enQueue(queue, 20);
	printf("Dequeued: %d", deQueue(queue));
	printf("Dequeued: %d", deQueue(queue));
	printf("Dequeued: %d", deQueue(queue));
	printf("Dequeued: %d", deQueue(queue));
	return 0;
}
