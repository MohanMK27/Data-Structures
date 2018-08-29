#include<stdio.h>
#include<string.h>
struct node
{
char name[20];
struct node *prev,*next;
};
struct node *head,*tail;


void add(char name[])
{
struct node *newnode,*tmp=head;
newnode=(struct node*)malloc(sizeof(struct node));
strcpy(newnode->name,name);
newnode->prev=NULL;
newnode->next=NULL;
if(!head)
{
head=tail=newnode;
 return;
}
 /* if(tmp==tail)
  {
  newnode->prev=tmp;
  tmp->next=newnode;
  tail=newnode;
  }*/
else
{
while(tmp!=NULL&&strcmp(name,tmp->name)>=0)
{
tmp=tmp->next;
}//while close
if(tmp==NULL)
{
  tail->next=newnode;
  newnode->prev=tail;
  tail=newnode;
  return;
}
else if(tmp==head)
{
newnode->next=head;
head->prev=newnode;
head=newnode;
return;
}
else 
tmp->prev->next=newnode;
newnode->prev=tmp->prev;
tmp->prev=newnode;
newnode->next=tmp;
return;
}
}

void display()
{
struct node *tmp=head;
while(tmp!=NULL)
{
printf("%s-->",tmp->name);
tmp=tmp->next;
}
}
void main()
{
add("m");
add("d");
add("a");
add("s");
add("c");
add("u");
display();

}
