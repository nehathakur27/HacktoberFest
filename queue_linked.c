#include<stdio.h>
#include<stdlib.h>
struct queue{
int data;
struct queue *next;
}*front=NULL, *rear=NULL;

void enqueue()
  {
struct queue *temp;
int val;
temp=(struct queue*)malloc(sizeof(struct queue));
if (temp == NULL)
printf("\nStack Overflow");
else
{

printf("Enter the value:");
scanf("%d",&val);

if(front==NULL) //empty queue
front=temp;
else
rear->next=temp;

temp->data =val;
temp->next =NULL;
rear=temp;
}
   }//end enqueue


void dequeue()
  {
if(front == NULL)
printf("\nStack Underflow");
else
{
printf("Value Popped = %d",front->data);
front=front->next;
}
   }//end dequeue


void display()
{
struct queue *temp;
temp=front;
printf("Dispalying Queue:");

while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
if(front == NULL) //check empty queue
{
printf("\nQueue is empty");
}
}//end display


void main ()
{
int ch;
printf("\n\n\n1.Enqueue\n2.Dequeue\n3.Dispaly Queue\n4.Exit\n");
do
     {
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
 {
case 1:enqueue(); 
	break;
case 2:dequeue(); 
	break;
case 3:display(); 
	break;
case 4:exit(0);
default:printf("\nInvalid Choice Entered.");
 }
     }while(ch<4);
}//end main
