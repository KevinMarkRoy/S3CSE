#include<stdio.h>
#define MAX 5
int push(int stack[],int max,int top,int data){
  if (top+1==max)
    printf("Stack is full");
  else{
    top++;
    stack[top]=data;
  }
  return top;
}
int pop(int stack[],int max,int top){
  if (top==-1)
    printf("Empty Stack");
  else{
    top--;
  }
  return top;
}
void display(int stack[],int top){
  if (top==-1)
    printf("Empty Stack");
  else
    for (int i=top;i>=0;i--)
      printf("%d ",stack[i]);
}
int main(){
  int stack[MAX],top=-1,data,x=1;
  printf("1.Push\n2.Pop\n3.Display\n0.Exit\n");
  while(x){
    printf("Enter option: ");
    scanf("%d",&x);
    if(x==1){
      printf("\nEnter data: ");
      scanf("%d",&data);
      top=push(stack,MAX,top,data);
    }
    else if(x==2)
      top=pop(stack,MAX,top);
    
    else if(x==3)
      display(stack,top);
    printf("\n");
  }
  return 0;
}
