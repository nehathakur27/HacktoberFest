#include<stdio.h>
#include<stdlib.h>
struct stack{
int data;
struct stack *next;
}*top=NULL;

void push ()
  {
struct stack *temp;
int val;
temp=(struct stack*)malloc(sizeof(struct stack));
if (temp == NULL)
printf("\nStack Overflow");
else
{

printf("Enter the value:");
scanf("%d",&val);
temp->data =val;
temp->next =top;
top=temp;
}
   }//end push


void pop ()
  {
if(top == NULL)
printf("\nStack Underflow");
else
{
printf("Value Popped = %d",top->data);
top=top->next;
}
   }//end pop

void display()
{
struct stack *temp;
temp=top;
printf("Dispalying Stack:");

while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
if(top == NULL) //check empty stack
{
printf("\nStack is empty");
}
}//end display

void main ()
{
int ch;
printf("\n\n\n1.PUSH\n2.POP\n3.Dispaly\n4.Exit\n");
do
     {
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
 {
case 1:push(); 
	break;
case 2:pop(); 
	break;
case 3:display(); 
	break;
case 4:exit(0);
default:printf("\nInvalid Choice Entered.");
 }
     }while(ch<4);
}//end main


