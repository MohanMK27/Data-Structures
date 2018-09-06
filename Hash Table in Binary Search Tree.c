

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 9
struct node {
int value;
struct node *left,*right;
};
struct node *hasharray[SIZE];
void add(int value)
{
int index;
struct node *newnode,*tmp,*pre;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=value;
newnode->left=NULL;
newnode->right=NULL;
index=value%SIZE;
if(!hasharray[index])
{
hasharray[index]=newnode;
return;
}
else
{
tmp=hasharray[index];
while(tmp!=NULL)
{
pre=tmp;
if(value>tmp->value)
tmp=tmp->right;
else if(value<tmp->value)
tmp=tmp->left;
else
{
printf("Element is already present\n");
return;
}
}//while close
if(value<pre->value)
pre->left=newnode;
else
pre->right=newnode;
}//else close
}
void inorder(struct node *tmp) {
 if(tmp==NULL)
 return;

 inorder(tmp->left);
 printf("%d--> ",tmp->value);
 inorder(tmp->right);
}

void main()
{
int i,v,ch;
clrscr();
do
{
printf("Enter the element: ");
scanf("%d",&v);
add(v);
printf("Continue press 1 or press 0 to display\n ");
scanf("%d",&ch);
}while(ch==1);
  for(i=0;i<SIZE;i++)
    {
    printf("hash[%d] :",i);
    inorder(hasharray[i]);
    printf("\n");

    }
    getch();
}
