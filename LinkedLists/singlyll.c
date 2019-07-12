#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
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

//Inserting in linked list at the beginning, anywhere in between or end as specified by position
void insert(struct node **head, int x, int pos){
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
if(pos==1){
 newnode->next = p;
 *head = newnode;
}
else{
 //Traverse the list until the position where we want to insert
 while((p!=NULL)&&(k<pos)){
 k++;
 q = p;
 p = p->next;
 }
 q->next = newnode;
 newnode->next = p;
 }
}

void delete(struct node **head, int pos){
 int k=1;
 struct node *p, *q;
 if(*head==NULL){
  printf("Linked list is empty");
  return;
 }
 p = *head;
 if(pos==1){
 *head = (*head)->next;
 free(p);
 return;
 }
 else{
  //Traverse the list until the position of node we want to delete
  while((p!=NULL)&&(k<pos)){
   k++;
   q = p;
   p = p->next;
  }
  if(p==NULL)
   printf("Position does not exist");
  else{
   q->next = p->next;
   free(p);
   }
  }
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
 


  

 



