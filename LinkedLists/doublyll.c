#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
 struct node *prev;
};

void print(struct node *head){
 struct node *temp = head;
 while(temp!=NULL){
 printf("%d ", temp->data);
 temp = temp->next;
 }
}

void length(struct node *head){
  struct node *current = head;
  int count = 0;
  while(current!=NULL){
  count++;
  current = current->next;
  }
 printf("%d",count);
}


void insert(struct node **head, int x, int pos){
 int k=1;
 struct node *temp, *newnode;
 newnode = (struct node *)malloc(sizeof(struct node));
 if(!newnode){
 printf("Memory error");
 return;
 }
 newnode->data = x;
 if(pos == 1){
 newnode->next = *head;
 newnode->prev = NULL;
 if(*head)
  (*head)->prev = newnode;
   *head = newnode;
   return;
 }
 temp = *head;
 
 //After this loop, temp will point to either the last node or the previous node of the position at which we want to insert a node
 while((k<pos)&&(temp->next!=NULL)){
  temp = temp->next;
  k++;
 }
 
 if(k!=pos){
 printf("Desired position does not exist\n");
 }
 
 newnode->next = temp->next;
 newnode->prev = temp;
 if(temp->next)
  temp->next->prev = newnode;
  temp->next = newnode;
 
 return;
}

void delete(struct node **head, int pos){
 struct node *temp,*temp2;
 temp = *head;
 int k=1;
 if(*head==NULL){
 printf("Linked list is empty");
 return;
 }
 if(pos==1){
 *head = (*head)->next;
 if(*head!=NULL)
 (*head)->prev = NULL;
  free(temp);
 return;
 }
 
 while((k<pos-1)&&(temp->next!=NULL)){
  temp = temp->next;
  k++;
  }
 
 if(k!=pos-1){
 printf("Desired position does not exist");
 }
 
 temp2 = temp->prev;
 temp2->next = temp->next;
 if(temp->next)  //Deletion from intermediate node
  temp->next->prev = temp2;
 free(temp);
 
 return;
}

int main(){
 int ch,x,poi,pod;
 struct node *head = NULL;
 do{
  printf("\nMenu Options:\n1.Insert element\n2.Delete element\n3.Find length of linked list\n4.Print contents of linked list\n5.Exit\nEnter choice: ");
  scanf("%d",&ch);
  switch(ch){
   case 1: printf("Enter element to be inserted: ");
           scanf("%d",&x);
           printf("Enter it's position: ");
           scanf("%d",&poi);
           insert(&head,x,poi);
           break;
   case 2: printf("Enter position of element to be deleted: ");
           scanf("%d",&pod);
           delete(&head,pod);
           break;
   case 3: length(head);
           break;
   case 4: print(head);
           break;
   case 5: exit(0);
           break;
  }
 }while(ch!=5);
return 0;
}
 

