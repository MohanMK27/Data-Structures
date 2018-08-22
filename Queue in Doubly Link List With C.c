#include<stdio.h>
#include<stdlib.h>
struct node {
int value;
struct node *next,*prev;
};
struct node *head,*tail;

//en-queue th value
void enqueue(int value)
{
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->value=value;
newnode->next=NULL;
newnode->prev=NULL;
if(!head)
  {
     head=tail=newnode;
      return;
  }
else
  {
      tail->next=newnode;
      newnode->prev=tail;
      tail=newnode;
      return;
   }
}

//de-queue the value
void dequeue()
{
     if(!head)
     {
         printf("Empty!!!");
     }
     else
     {
         head=head->next;
         printf("%d is deleted",head->prev->value);
         free(head->prev);
         head->prev=NULL;
         return;
      }
}
void display()
{
struct node *tmp;
tmp=head;
while(tmp!=NULL)
{
printf("%d-->",tmp->value);
tmp=tmp->next;
}
}

void search(int v) {
struct node * tmp;
tmp=head;
while(tmp!=NULL) {
if(tmp->value==v) {
printf("The value %d is found\n",v);
return;
}
tmp=tmp->next;
}
printf("The value %d is not found\n",v);
}

void main()
{
int ch, m;
  do {
printf("Enter the choice: 1.insert 2.Search 3:Delete 4:Display 5:exit\n");

scanf ("%d", &ch);
switch (ch)
 {
case 1:  {
printf ("Enter the element to Insert: ");
scanf ("%d", &m);
 enqueue(m);
}
break;
case 2:   {
printf ("Enter the element to be searched: ");
scanf ("%d", &m);
search (m);
}
break;

case 3:   {
dequeue();
}
break;
case 4:
 {
printf ("Elements are:\n");
display ();
}
break;
}
}
while (ch < 5);
   
    
}