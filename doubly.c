#include<stdio.h>
#include<stdlib.h>
struct doubly{
int data;
struct doubly *next;
struct doubly *prev;
}*head=NULL, *tail=NULL, *new;

void insert_at_beg()
  {
int val;
new=(struct doubly*)malloc(sizeof(struct doubly));
printf("Enter the value:");
scanf("%d",&val);
new->data=val;
new->prev=NULL;
if(head==NULL) //first node being inserted
{
  tail=new;
  head=new;
  new->next=NULL;
  return; 
}
new->next=head;
head->prev=new;
head=new;

   }//end

void insert_at_end()
  {
int val;
new=(struct doubly*)malloc(sizeof(struct doubly));
printf("Enter the value:");
scanf("%d",&val);
new->data=val;
new->next=NULL;
if(head==NULL) //first node being inserted
{
  
  head=new;
  tail=new; 
  new->prev=NULL;
  return; 
}
else
{
new->prev=tail;
tail->next=new;
tail=new;

}

   }//end

void insert_at_pos()
  {
int val,p;
new=(struct doubly*)malloc(sizeof(struct doubly));
printf("Enter the value and position to insert the value:");
scanf("%d %d",&val,&p);
new->data=val;
if(p==0)
{
  new->prev=NULL;
  new->next=head;
  if(head==NULL) //first node being inserted
  {
  tail=new; 
  }
  head->prev=new;
  head=new;
  return;
}
else{

struct doubly *temp, *temp1;
temp=head;
int i=1;
while(i<p)
	{
  if(temp==NULL)
  {
     printf("\nPosition is out of index.");
     exit(1);
  }
  temp=temp->next;
        i++;
	}//end while
if(temp->next==NULL)
{
   new->prev=tail;
   new->next=NULL;
   tail->next=new;
   tail=new; //to be inserted at last
   return;
}
temp1=temp->next;
new->prev=temp;
new->next=temp->next;
temp1->prev=new;
temp->next=new;

}//end else

   }//end function

void del_at_beg()
  {
if(head == NULL)
printf("\nList Empty");
else
{
printf("Deleted = %d",head->data);
if(head==tail)//only 1 node is there
{
tail=NULL;
head=NULL;
return;
}

head=head->next;
head->prev=NULL;

}
   }//end 

void del_at_end()
  {
if(head == NULL)
printf("\nList Empty");
else
{

printf("Deleted = %d",tail->data);
  if(head==tail)//only 1 node is there
	{
	head=NULL;
	tail=NULL;
	}
   else
	{
           struct doubly *temp;
           temp=head;
            while(temp->next!=tail)
                temp= temp->next; //to reach last second node
           
           tail->prev=NULL;
           temp->next=NULL;
           tail=temp;

	}

}
   }//end 

void del_at_pos()
  {
int p;
if(head == NULL)
{
printf("\nList Empty");
return;
}
printf("\nEnter position to delete node:(Position starts from 0) ");
scanf("%d",&p);


if(p==0)
{del_at_beg();
return;
}

else
{
struct doubly *temp, *temp1;
temp=head;
int i=1;
while(i<p)
{
  if(temp->next==NULL)
  {
     printf("\nPosition is out of index.");
     return;
  }
  temp=temp->next;
  i++;
}
 if(temp->next==NULL)
  {
     printf("\nPosition is out of index.");
     return;
  }

if(temp->next->next==NULL)
{
  del_at_end(); //last node to be deleted
  return;
}
printf("Deleted = %d",temp->next->data);
temp1=temp->next;
temp1->next->prev=temp;
temp->next=temp->next->next;
temp1->next=NULL;
temp1->prev=NULL;
free(temp1);


}
   }//end 

void display()
{
struct doubly *temp;
temp=head;
printf("Dispalying Linked List:");

while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
if(head == NULL) //check empty list
{
printf("\nList is empty");
}
free(temp);
}//end display

void rdisplay()
{
struct doubly *temp;
temp=tail;
printf("Dispalying Linked List in Reverse Order:");

while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->prev;
}
if(head == NULL) //check empty list
{
printf("\nList is empty");
}
free(temp);
}//end display

void main ()
{
int ch;
printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert at a specific position\n4. Delete from beginning\n5. Delete from end\n6. Delete from a specific node\n7. Display the linked list\n8. Display Linked list in Reverse Order\n9. Exit\n");
do
     {
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
 {
case 1:insert_at_beg(); 
	break;
case 2:insert_at_end(); 
	break;
case 3:insert_at_pos(); 
	break;
case 4:del_at_beg(); 
	break;
case 5:del_at_end(); 
	break;
case 6:del_at_pos(); 
	break;
case 7:display(); 
	break;
case 8: rdisplay();
	break;
case 9:exit(0);
default:printf("\nInvalid Choice Entered.");
 }
     }while(ch<9);
}//end main
