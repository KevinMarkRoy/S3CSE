#include<stdio.h>
#define MAX 5
int push1(int stack[],int max,int top1,int top2,int data){
  if (top1+1==top2)
    printf("Stack is full");
  else{
    top1++;
    stack[top1]=data;
  }
  return top1;
}
int push2(int stack[],int max,int top1,int top2,int data){
  if (top2-1==top1)
    printf("Stack is full");
  else{
    top2--;
    stack[top2]=data;
  }
  return top2;
}
int pop1(int stack[],int top1){
  if (top1==-1)
    printf("Empty Stack");
  else
    top1--;
  return top1;
}
int pop2(int stack[],int top2,int max){
  if (top2==max)
    printf("Empty Stack");
  else
    top2++;
  return top2;
}
void display(int stack[],int top1,int top2,int max){
  if (top1==-1)
    printf("Empty Stack");
  else
    for (int i=top1;i>=0;i--)
      printf("%d ",stack[i]);
  printf("\n");
  if (top2==max)
    printf("Empty Stack");
  else
    for (int i=top2;i<max;i++)
      printf("%d ",stack[i]);
}
int main(){
  int top1=-1,top2=MAX,stack[MAX],data,x=1;
  printf("1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Display\n0.Exit\n");
  while(x){
    printf("Enter option: ");
    scanf("%d",&x);
    if(x==1){
      printf("\nEnter data: ");
      scanf("%d",&data);
      top1=push1(stack,MAX,top1,top2,data);
    }
    else if(x==2){
      printf("\nEnter data: ");
      scanf("%d",&data);
      top2=push2(stack,MAX,top1,top2,data);
    }
    else if(x==3)
      top1=pop1(stack,top1);
    else if(x==4)
      top2=pop2(stack,top2,MAX);
    else if(x==5)
      display(stack,top1,top2,MAX);
    printf("\n");
  }
  return 0;
}
