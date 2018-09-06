#include<stdio.h>
#include<stdlib.h>
//Declaring structure
struct stu {
int a;
struct stu * next;
}; struct stu *head,*tail;

void add(int);
void search(int);
void del(int);
void insert(int,int);
void print();
void rev();
void main() {

add(3);
add(7);
add(5);
add(6);
add(9);

search(9);
search(7);
search(6);
search(11);

del(3);
del(17);
del(19);

insert(10,2);
insert(20,100);

print();

rev();

print();

}
//adding new value

void add(int v)
{
struct stu *new;
new=(struct stu *)malloc(sizeof(struct stu));
new->a=v;
new->next=NULL;
if(head==NULL) {
head=tail=new;
}
else {
tail->next=new;
tail=new;
}
}

//searching a element
void search(int v) {
struct stu * tmp;
tmp=head;
while(tmp!=NULL) {
if(tmp->a==v) {
printf("The value %d is found\n",v);
return;
}
tmp=tmp->next;
}
printf("The value %d is not found\n",v);
}

//Delete an element
void del(int v) {
struct stu *tmp, *pre;
pre=head;
tmp=head->next;
if(tail==NULL) {
printf("The link list is empty");
return;}
else if(head==tail) {
free(pre);
head=tail=NULL;
return;
}
else if(head->a==v) {
printf("Value %d is found",v);
free(head);
head=tmp;
return;
}
 else {
 while(tmp!=NULL) {
 if(tmp->a==v) {
 pre->next=tmp->next;
 free(tmp);
 return;
 }
 tmp=tmp->next;
 pre=pre->next;
 }
 printf("No sunch elements in list\n");
 }

//Inserting element at a specific position
}
void insert(int v,int p) {
int i=0;
struct stu * tmp ,*new;
new=(struct stu *)malloc(sizeof(struct stu));
new->a=v;
new->next=NULL;
tmp=head;
if(p==0) {
  new->next=head;
  head=new;
  return;
}
else {
while(i<(p-1)){
if(tmp==NULL) {
printf("No such position");
return;
}
tmp=tmp->next;
i++;}
new->next=tmp->next;
tmp->next=new;
}}

//display
void print() {
struct stu *tmp;
tmp=head;
while(tmp!=NULL)
{
printf("%d->",tmp->a);
tmp=tmp->next;
}
}

//Reversing a string
void rev() {
struct stu *i,*j,*k,*tmp;;
i=head;
j=i->next;
if(j!=NULL)
k=j->next;
while(j!=NULL)
{
if(i==NULL)
{
printf("No elements");
return;
}
else if(j==NULL)
{
  return;
}
else
{
 j->next=i;
}
i=j;
j=k;
if(k!=NULL)
k=k->next;

}
tmp=tail;
tail=head;
head=tmp;
tail->next=NULL;
}
