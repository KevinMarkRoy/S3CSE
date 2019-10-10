#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}node;
node *top=NULL;
void push(int data){
  node *newnode;
  newnode=(node*)malloc(sizeof(node));
  if (newnode==NULL){
    printf("Insufficient Memory");
    exit(0);
  }
  else{
    newnode->data=data;
    node *t=top;
    newnode->link=t;
    top=newnode;
  }
}
void pop(){
  node *t=top;
  if (t==NULL)
    printf("Empty Stack");
  else{
    int x;
    x=t->data;
    top=t->link;
    free(t);
    printf("%d is popped\n",x);
  }
}
void display(){
  node *t=top;
  if (t==NULL){
    printf("Empty Stack");
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
    printf("Enter Option\n1.Push\n2.Pop\n3.Display\n0.Exit\n");
    scanf("%d",&x);
    printf("\n");
    if (x==1){
      printf("Enter data: ");
      scanf("%d",&data);
      push(data);
    }
    else if (x==2)
      pop();
    else if (x==3)
      display();
    printf("\n");
  }
  return 0;
}
