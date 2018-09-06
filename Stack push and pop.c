#include<stdio.h>
#include<stdlib.h>

/*structure for the stack*/
struct node {
int value;
struct node *next,*prev;
};
struct node *top;

//push function

void push(int value) {
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->value=value;
newnode->next=NULL;
newnode->prev=NULL;
if(!top) {
top=newnode;
return;
}
else {
top->next=newnode;
newnode->prev=top;
top=newnode;
return;
}
}

//pop function

void pop() {
if(!top) {
printf("Empty!!!");
}
else
{
  top=top->prev;
  printf("%d is deleted",top->next->value);
  free(top->next);
  top->next=NULL;
  return;
}
}


void main() {
push(4);
push(7);
push(9);
push(6);
pop();
pop();
}
