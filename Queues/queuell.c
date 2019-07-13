#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

struct queue{
 struct node *front;
 struct node *rear;
};

struct queue *createqueue(){
 struct queue *q;
 struct node *temp;
 q = malloc(sizeof(struct queue));
 if(!q)
 return NULL;
 temp = malloc(sizeof(struct node));
 q->front = q->rear=NULL;
 return q;
}

int isempty(struct queue *q){
 return (q->front==NULL);
}

void enqueue(struct queue *q, int x){
 struct node *newnode;
 newnode = malloc(sizeof(struct node));
 if(!newnode)
 return;
 newnode->data = x;
 newnode->next = NULL;
 if(q->rear) q->rear->next = newnode;
 q->rear = newnode;
 if(q->front==NULL)
 q->front = q->rear;
}

int dequeue(struct queue *q){
 int dat = 0;
 struct node *temp;
 if(isempty(q)){
 printf("Queue is empty");
 return 0; 
 }
 else{
 temp = q->front;
 dat = q->front->data;
 q->front = q->front->next;
 free(temp);
 }
 return dat;
}

void delqueue(struct queue *q){         //function not working properly. it will be fixed in some time
 struct node *temp;
 while(q){
 temp = q->front;
 q->front = q->front->next;
 free(temp);
 }
 free(q);
}

int main(){
 int ch,xi,ele;
 struct queue *q = createqueue();
 do{
  printf("\nMenu Options:\n1.Enqueue\n2.Dequeue\n3.Create queue\n4.Delete queue\n5.Exit\nEnter choice: ");
  scanf("%d",&ch);
  switch(ch){
   case 1: printf("Enter element to be inserted: ");
           scanf("%d",&xi);
           enqueue(q,xi);
           break;
   case 2: ele = dequeue(q);
           printf("Dequeued element is %d",ele);
           break;
   case 3: createqueue();
           break;
   case 4: delqueue(q);
           break;
   case 5: exit(0);
           break;
  }
 }while(ch!=5);
return 0;
}
 




