#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX],i,j,top=-1;

void push ()
  {
int val;
if (top == MAX-1)
printf("\nStack Overflow");
else
{
printf("Enter the value:");
scanf("%d",&val);
stack[++top] = val;
}
   }//end push


void pop ()
  {
if(top == -1)
printf("\nStack Underflow");
else
{
printf("Value Popped = %d",stack[top--]);
}
   }//end pop

void display()
{
printf("Dispalying Stack:");
for (i=top;i>=0;i--)  //last element entered is displayed first
{
printf("%d ",stack[i]);
}
if(top == -1) //check empty stack
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


