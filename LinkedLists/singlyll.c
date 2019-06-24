#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
}

void print(struct node *head){
 struct node *temp = head;
 while(temp!=NULL){
 printf("%d ", temp->data);
 temp = temp->next;
 }
}

//Inserting in linked list at the beginning, anywhere in between or end as specified by position
struct node *insert(struct node **head, int x, int pos){
 int k=1;
 struct node *p,*q,*newnode;
 newnode = (struct node *)malloc(sizeof(struct node));
 
 if(!newnode){
  printf("Memory error");
  return;
 }

 newnode->data = x;
 p = *head;

//Inserting at beginning
if(position==1){
 newnode->next = p;
 *head = newnode;
}
else{
 //Traverse the list until the position where we want to insert
 while((p!=NULL)&&(k<pos)){
 k++;
 q = p
 p = p->next;
 }
 q->next = newnode;
 newnode->next = p;
 }
}



