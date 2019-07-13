#include<stdio.h>                     //Changes yet to be made for program to work properly
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void length(struct node *head){
 struct node *current = head;
 int count = 0;
 if(head==NULL)
  return;
 do{
  current = current->next;
  count++;
 }while(current!=head);
 printf("%d",count);
}

void print(struct node *head){
 struct node *current = head;
 int count = 0;
 if(head==NULL)
  return;
 do{
 printf("%d ",current->data);
 current = current->next;
 }while(current!=head);
}

//Insert new node at the end of Circular Linked List
void insertend(struct node **head, int xe){
 struct node *current = *head;
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 if(!newnode){
 printf("Memory error");
 return;
 }
 newnode->data=xe;
 while(current->next!=head)
 current=current->next;
 newnode->next = newnode;
 if(*head==NULL)
 *head = newnode;
 else{
 newnode->next = *head;
 current->next = newnode;
 }
}

//Insert new node at the front of Circular Linked List
void insertfront(struct node **head, int xf){
 struct node *current = *head;
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 if(!newnode){
 printf("Memory error");
 return;
 }
 newnode->data=xf;
 while(current->next!=head)
 current=current->next;
 newnode->next = newnode;
 if(*head==NULL)
 *head = newnode;
 else{
 newnode->next = *head; 
 current->next = newnode;
 *head = newnode;
 }
 return;
}

//Delete last node from Circular Linked List
void deletelast(struct node **head){
 struct node *temp = *head;
 struct node *current = *head;
 if(*head==NULL){
 printf("List empty");
 return;
 }
 while(current->next!=head){
 temp = current;
 current = current->next;
 }
 temp->next = current->next;
 free(current);
 return;
}

//Delete first node from Circular Linked List
void deletefirst(struct node **head){
 struct node *temp =*head;
 struct node *current = *head;
 if(*head==NULL){
 printf("List empty");
 return;
 }
 while(current->next!=head)
  current = current->next;
  current->next = (*head)->next;
  *head = (*head)->next;
  free(temp);
  return;
}

int main(){
 int ch,x,y;
 struct node *head = NULL;
 do{
  printf("\nMenu Options:\n1.Insert element at the beginning of Circular Linked List\n2.Insert element at the end of Circular Linked List\n3.Delete element at the front of Circular linked list\n4.Delete element at the end of Circular linked list\n5.Find length of Circular linked list\n6.Print contents of Circular linked list\n7.Exit\nEnter choice: ");
  scanf("%d",&ch);
  switch(ch){
   case 1: printf("Enter element to be inserted at the front: ");
           scanf("%d",&x);
           insertfront(&head,x);
           break;
   case 2: printf("Enter element to be inserted at the end: ");
           scanf("%d",&y);
           insertend(&head,y);
           break;
   case 3: deletefirst(&head);
           break;
   case 4: deletelast(&head);
           break;
   case 5: length(head);
           break;
   case 6: print(head);
           break;
   case 7: exit(0);
           break;
  }
 }while(ch!=7);
return 0;
}
 



 

