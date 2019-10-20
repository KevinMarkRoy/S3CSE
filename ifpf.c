#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
  char character;
  struct node *link;
}node;
typedef struct eval{
  int number;
  struct eval *link;
}eval;
node *top=NULL;
node *front=NULL,*rear=NULL;
eval *start=NULL;
char infix[50];
void convert(){
  printf("\n");
  for (int i=0;infix[i]!='\0';i++){
    if (isalpha(infix[i])){
        node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	if (front==NULL){
	  front=rear=newnode;
	}
	else{
	  rear->link=newnode;
	  rear=newnode;
	}
	newnode->character=infix[i];
    }
    else if (infix[i]=='('){
        node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	if (top==NULL){
	  top=newnode;
	}
	else{
	  newnode->link=top;
	  top=newnode;
	}
	newnode->character=infix[i];
    }
    else if (infix[i]==')'){
      while (top->character!='('){
	node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	if (front==NULL){
	  front=rear=newnode;
	}
	else{
	  rear->link=newnode;
	  rear=newnode;
	}
	newnode->character=top->character;
	top=top->link;
      }
      top=top->link;
    }
    else if (infix[i]=='+'||infix[i]=='-'){
      int flag=0;
      if (top==NULL)flag=1;
      while(flag==0){
	if (top->character=='+'||top->character=='-'||top->character=='*'||top->character=='/'||top->character=='^'){
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL){
	    front=rear=newnode;
	  }
	  else{
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL){
	top=newnode;
      }
      else{
	newnode->link=top;
	top=newnode;
      }
    }
    else if(infix[i]=='*'||infix[i]=='/'){
      int flag=0;
      if (top==NULL)flag=1;
      while(flag==0){
	if (top->character=='*'||top->character=='/'||top->character=='^'){
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL){
	    front=rear=newnode;
	  }
	  else{
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL){
	top=newnode;
      }
      else{
	newnode->link=top;
	top=newnode;
      }
    }
    else if(infix[i]=='^'){
      int flag=0;
      if (top==NULL)flag=1;
      while(flag==0){
	if (top->character=='^'){
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL){
	    front=rear=newnode;
	  }
	  else{
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL){
	top=newnode;
      }
      else{
	newnode->link=top;
	top=newnode;
      }
    }
    else{
      printf("Invalid Expression\n");
      exit(0);
    }
  }
  while(top!=NULL){
    node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
    newnode->character=top->character;
    rear->link=newnode;
    rear=newnode;
    top=top->link;
  }
}
void evl(){
  printf("\n");
  node *t;
  eval *n,*n2;
  int a,b,r;
  for (t=front;t!=NULL;t=t->link){
    if (isalpha(t->character)){ 
	eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
	printf("Enter value of %c: ",t->character);
	scanf("%d",&newnode->number);
	if (start==NULL)
	  start=newnode;
	else{
	  newnode->link=start;
	  start=newnode;
	}
    }
  }
  for (t=front;t!=NULL;t=t->link){
    if (t->character=='+'){
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      a=n->number;
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      b=n->number;
      r=a+b;
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
    else if(t->character=='-'){
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      a=n->number;
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      b=n->number;
      r=a-b;
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
    else if(t->character=='*'){
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      a=n->number;
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      b=n->number;
      r=a*b;
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
    else if(t->character=='/'){
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      a=n->number;
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      b=n->number;
      r=a/b;
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
    else if(t->character=='^'){
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      a=n->number;
      n=start;
      n2=n;
      while(n->link!=NULL){
	n2=n;
	n=n->link;
      }
      n2->link=NULL;
      b=n->number;
      r=1;
      for(int i=0;i<b;i++)
	r=a*r;
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
  }
}
int main(){
  printf("Enter expression: ");
  scanf("%s",infix);
  convert();
  
  node *t;
  printf("\n");
  for (t=front;t!=NULL;t=t->link)
    printf("%c",t->character);

  evl();
  printf("\nResult: %d",start->number);
  printf("\n");
  return 0;
}
