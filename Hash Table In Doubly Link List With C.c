#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node 
{
int value;
struct node *next, *prev;
};
 
struct node *hasharray[size];
 
//insert the element in hash
void insert (int value) 
{
int index;
struct node *newnode;
newnode = (struct node *) malloc (sizeof (struct node));
newnode->value = value;
newnode->next = NULL; 
newnode->prev = NULL; 
index = value % size; 
if (!hasharray[index])
    {
hasharray[index] = newnode;
return;
}
  else { 
hasharray[index]->prev = newnode;
newnode->next = hasharray[index];
hasharray[index] = newnode;
return;
}
}
 
//search elements in hash
void 
search (int value) 
{
struct node *tmp; 
int i = value % size;
tmp = hasharray[i]; 
while (tmp != NULL)    
    {   
if (tmp->value == value)
	{ 
printf ("%d value found\n", value); 
return; 
} 
}
printf ("Not found\n");
}

void del (int value) 
{
struct node *tmp;
int i = value % size;
tmp = hasharray[i]; 
if (hasharray[i]->value == value)
    { 
free (hasharray[i]); 
hasharray[i] = NULL;
printf ("%d value is deleted\n", value);
return; 
}
   else
    {
while (tmp != NULL) 
	{
if (tmp->value == value)
	    { 
tmp->next->prev = tmp->prev; 
tmp->prev->next = tmp->next; 
free (tmp);
printf ("%d value is deleted\n", value); 
return; 
} 
}
}
printf ("Not found\n"); 
}

void display () 
{
struct node *tmp;
int i; 
for (i = 0; i < size; i++)
    {
tmp = hasharray[i];
while (tmp != NULL)
	{
printf ("%d-->", tmp->value);
tmp = tmp->next;
}
} 
}
 
void main () 
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
 insert (m);
}
break;
case 2:	  {
printf ("Enter the element to be searched: ");
scanf ("%d", &m);
search (m);
}
break;

case 3:   {
printf ("Enter the element to delete: ");
scanf ("%d", &m);
del (m);
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
