#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue(int data){
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if (newnode==NULL){
    printf("Insufficient Memory");
    exit(0);
  }
  else{
    newnode->data=data;
    newnode->link=NULL;
    if (front==NULL)
      front=rear=newnode;
    else{
      rear->link=newnode;
      rear=newnode;
    }
  }
}
void dequeue(){
  node *t=front;
  if (t==NULL)
    printf("Empty Queue");
  else{
    int x;
    x=t->data;
    front=t->link;
    free(t);
    if(front==NULL)
      rear=NULL;
    printf("%d is dequeued\n",x);
  }
}
void display(){
  node *t=front;
  if (t==NULL){
    printf("Empty Queue");
  }
  else{
    while(t!=NULL){
      printf("%d ",t->data);
      t=t->link;
    }
  }
  printf("\n");
}
int main(){
  int x,data;
  while (x){
    printf("Enter Option\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    scanf("%d",&x);
    printf("\n");
    if (x==1){
      printf("Enter data: ");
      scanf("%d",&data);
      enqueue(data);
    }
    else if (x==2)
      dequeue();
    else if (x==3)
      display();
    printf("\n");
  }
  return 0;
}
