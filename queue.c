#include<stdio.h>

int dequeue(int *qu, int head, int tail) {
	if(tail < head) {
		printf("The queue is empty.\n");
		return head;
	}
	printf("Value dequeued: %d\n", qu[head++]);
	return head;
}

int enqueue(int *qu, int tail) {
	if(tail == 19) {
		printf("The queue is full.\n");
		return 19;
	}
	printf("Enter the queue element: ");
	scanf("%d", (qu+(++tail)));
	return tail;
}

void display(int *qu, int head, int tail) {
	int i;
	if (tail < head) {
		printf("The queue is empty.\n");
		return;
	}
	printf("The current queue status is:\n");
	for (i=head; i<=tail; i++) 
		printf("%d ", qu[i]);
	printf("\n");
}

void main() {
	int queue[20], head = 0, tail = -1, ch;
	do {
		printf("Enter one of these:\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1: 
				tail = enqueue(queue, tail);
				break;
			case 2: 
				head = dequeue(queue, head, tail);
				break;
			case 3:
				display(queue, head, tail);
				break;
			default:
				printf("Invalid choice. Try again.\n");
				break;
			case 4:
				break;
		}
	} while(ch != 4);
}
