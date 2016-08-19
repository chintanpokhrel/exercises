#include <stdio.h>
int queue[5];
int front = -1;
int rear = -1;
short empty = 1;
int size = 5;

void enqueue(int);
int dequeue();

int main(){
	
	enqueue(10); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(5); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(20); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n",dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n", dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(6); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(7); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(4); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(2); printf("Front: %d Rear: %d\n", front, rear);
	enqueue(9); printf("Front: %d Rear: %d\n", front, rear); //this should fail 
	printf("Dequeued %d \n",dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n", dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n",dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n", dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n",dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	printf("Dequeued %d \n", dequeue()); printf("Front: %d Rear: %d\n", front, rear);
	return 0;
}

void enqueue(int data){
	int new_rear = ((rear+1)+size)%size;
	if(new_rear == front){
		printf("Queue full!\n");
		return;
	}
	
	if(front == -1 && rear == -1){
		front = 0, rear = 0;
	}else{
		rear = new_rear;
	}
	queue[rear] = data;
	empty = 0;
	return;	
}

int dequeue(){
	if(empty){
		printf("Queue Empty\n");
		return -1;
	}
	int new_front = ((front+1)+size)%size;
	if(front == rear){
		//printf("Queue Empty\n");
		empty = 1;
	}else{
		front = new_front;
	}
	int data = queue[new_front];
	
	return data;
}

