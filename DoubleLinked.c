#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
} *head, *tail, *new;

void create() {
	int data;
	printf("Enter the value: ");
	scanf("%d", &data);
	new = malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	head = new;
	tail = new;
}

void IAB() {
	int data;
	printf("Enter the value: ");
	scanf("%d", &data);
	new = malloc(sizeof(struct node));
	new->data = data;
	new->next = head;
	new->prev = NULL;
	head->prev = new;
	head = new;
}

void IAE() {
	int data;
	printf("Enter the value: ");
	scanf("%d", &data);
	new = malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	new->prev = tail;
	tail->next = new;
	tail = new;
}

void IAP() {
	int pos, i=0, data;
	printf("Enter the value and position of the element: ");
	scanf("%d %d", &data, &pos);
	if (pos == 0) {
		new = malloc(sizeof(struct node));
	        new->data = data;
       	 	new->next = head;
		new->prev = NULL;
		head->prev = new;
        	head = new;
		return;
	}
	struct node *it;
	it = head;
	while((i != pos-1) && (it->next != NULL)) {
		it = it->next;
		i++;
	}
	if((it->next == NULL) && (i != pos-1)) {
		printf("The element you want to enter into is out of bounds.\n");
		return;
	}
	new = malloc(sizeof(struct node));
	new->data = data;
	new->next = it->next;
	new->prev = it;
	it->next = new;
	if (new->next == NULL)
		tail = new;
	else
		new->next->prev = new;
}

void DFB() {
	new = head;
	head = new->next;
	head->prev = NULL;
	printf("The element deleted is: %d.\n", new->data);
	free (new);
}

void DFE() {
	if (tail == head) {
		printf("The element deleted is: %d.\n", tail->data);
		free(tail);
		tail = NULL;
		head = NULL;
		return;
	}
	new = tail;
	printf("The element deleted is: %d", tail->data);
	tail = new->prev;
	tail->next = NULL;
	free(new);
}

void DFP() {
	int i=0, pos;
	printf("Enter the position of element to delete: ");
	scanf("%d", &pos);
	if (pos == 0) {
		DFB();
		return;
	}
	struct node *it;
	it = head;
	while((i != pos-1) && (it->next != NULL)) {
		it = it->next;
		i++;
	}
	if (it->next == NULL) {
		printf("The element you want to delete is out of bounds.\n");
		return;
	}
	if (it->next == tail) {
		DFE();
		return;
	}
	printf("The element deleted is: %d\n", it->next->data);
	struct node *temp;
	temp = it->next;
	it->next = it->next->next;
	temp->next->prev = it;
	free(temp);
}

void display() {
	if (head == NULL) {
		printf("The list is empty.\n");
		return;
	}
	new = head;
	printf("The linked list is: ");
	while(new->next != NULL) {
		printf("%d ", new->data);
		new = new->next;
	}
	printf("%d\n", new->data);
}

void revdisplay() {
	if (head == NULL) {
		printf("The list is empty.\n");
		return;
	}
	new = tail;
	printf("The linked list in reverse order is: ");
	while(new->prev != NULL) {
		printf("%d ", new->data);
		new = new->prev;
	}
	printf("%d\n", new->data);
}

void main() {
	int ch;
	head = NULL;
	tail = NULL;
	do {
		printf("Enter one of these: \n1: Insert at beginning\n2: Insert at end\n3: Insert at a specific position\n4: Delete from beginning\n5: Delete from end\n6: Delete from a specific node\n7: Display the linked list\n8: Display in reverse order\n9: Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: 
				if (head == NULL)
					create();
				else
					IAB();
				break;
			case 2: 
				if (head == NULL)
					create();
				else
					IAE();
				break;
			case 3:
				if(head == NULL) {
					printf("No existing nodes. Enter the new node as the first one.\n");
					create();
				}
				else
					IAP();
				break;
			case 4:
				if (head == NULL) 
					printf("The list is empty.\n");
				else
					DFB();
				break;
			case 5:
				if (head == NULL)
                                        printf("The list is empty.\n");
                                else
                                        DFE();
				break;
			case 6:
				if (head == NULL)
                                        printf("The list is empty.\n");
                                else
                                        DFP();
				break;
			case 7: 
				display();
				break;
			case 8:
				revdisplay();
				break;
			case 9:
				break;
			default: 
				printf("Invalid input. Try again.\n");
		}
	} while (ch != 9);
}
