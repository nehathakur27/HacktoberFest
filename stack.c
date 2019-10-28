#include<stdio.h>

int POP(int *st, int n) {
	if(n == -1) {
		printf("The stack is empty\n");
		return -1;
	}
	printf("Value popped: %d\n", st[n--]);
	return n;
}

int PUSH(int *st, int n) {
	if(n == 19) {
		printf("The stack is full.\n");
		return 19;
	}
	printf("Enter the stack element: ");
	scanf("%d", (st+(++n)));
	return n;
}

void display(int *st, int n) {
	int i;
	if (n == -1) 
		printf("The current stack is empty.");
	else
		printf("The current stack status is:\n");
	for (i=0; i<=n; i++) 
		printf("%d ", st[i]);
	printf("\n");
}

void main() {
	int stack[20], top = -1, ch;
	do {
		printf("Enter one of these:\n1: Push\n2: Pop\n3: Display\n4: Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1: 
				top = PUSH(stack, top);
				break;
			case 2: 
				top = POP(stack, top);
				break;
			case 3:
				display(stack, top);
				break;
			default:
				printf("Invalid choice. Try again.\n");
				break;
			case 4:
				break;
		}
	} while(ch != 4);
}
