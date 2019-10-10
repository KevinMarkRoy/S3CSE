#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int coe,exp;
  struct node *link;
}node;
node *h1=NULL,*h2=NULL,*hr=NULL;

void polyadd(){
  node *ptr1,*ptr2;
  ptr1=h1;
  ptr2=h2;
  //polyadd start
  while(ptr1!=NULL&&ptr2!=NULL){
    node *r;
    r=(node*)malloc(sizeof(node));
    if (r==NULL){
      printf("Insufficient Memory");
      exit(0);
    }
    if(ptr1->exp>ptr2->exp){
      r->coe=ptr1->coe;
      r->exp=ptr1->exp;
      r->link=NULL;
      if(hr==NULL){
	hr=r;
      }
      else{
	r->link=hr;
	hr=r;
      }
      ptr1=ptr1->link;
    }
    else if(ptr2->exp>ptr1->exp){
      r->coe=ptr2->coe;
      r->exp=ptr2->exp;
      r->link=NULL;
      if(hr==NULL){
	hr=r;
      }
      else{
	r->link=hr;
	hr=r;
      }
      ptr2=ptr2->link;
    }
    else{
      r->coe=ptr1->coe + ptr2->coe;
      r->exp=ptr1->exp;
      r->link=NULL;
      if(hr==NULL){
	hr=r;
      }
      else{
	r->link=hr;
	hr=r;
      }
      ptr1=ptr1->link;
      ptr2=ptr2->link;
    }
  }
  while(ptr1!=NULL){
    node *r;
    r=(node*)malloc(sizeof(node));
    if (r==NULL){
      printf("Insufficient Memory");
      exit(0);
    }
    r->coe=ptr1->coe;
    r->exp=ptr1->exp;
    r->link=NULL;
      if(hr==NULL){
	hr=r;
      }
      else{
	r->link=hr;
	hr=r;
      }
      ptr1=ptr1->link;
  }
  while(ptr2!=NULL){
    node *r;
    r=(node*)malloc(sizeof(node));
    if (r==NULL){
      printf("Insufficient Memory");
      exit(0);
    }
    r->coe=ptr2->coe;
    r->exp=ptr2->exp;
    r->link=NULL;
      if(hr==NULL){
	hr=r;
      }
      else{
	r->link=hr;
	hr=r;
      }
      ptr2=ptr2->link;
  }
  //polyadd end
  printf("\nSum of the 2 polynomials: ");
  node *t;
  t=hr;
  while (t!=NULL){
     printf("%dx^%d+ ",t->coe,t->exp);
     t=t->link;
  }
}

int main(){
  int e,c;
  
  printf("Enter highest exponent in first polynomial: ");
  scanf("%d",&e);
  printf("\n");
  if (e<0){
    printf("Invalid polynomial");
    exit(0);
  }
  while(e>-1){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL){
      printf("Insufficient Memory");
      exit(0);
    }
    newnode->exp=e;
    newnode->link=NULL;
    printf("Enter coefficient for %dth exponent: ",e);
    scanf("%d",&c);
    if (c==0){
      e--;
      continue;
    }
    newnode->coe=c;
    if (h1==NULL)
      h1=newnode;
    else{
      newnode->link=h1;
      h1=newnode;
    }
    e--;
  }
  printf("\n");
  node *t;
  t=h1;
  while (t!=NULL){
     printf("%dx^%d+ ",t->coe,t->exp);
     t=t->link;
  }
  printf("\n\n");

  printf("Enter highest exponent in second polynomial: ");
  scanf("%d",&e);
  printf("\n");
  if (e<0){
    printf("Invalid polynomial");
    exit(0);
  }
  while(e>-1){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL){
      printf("Insufficient Memory");
      exit(0);
    }
    newnode->exp=e;
    newnode->link=NULL;
    printf("Enter coefficient for %dth exponent: ",e);
    scanf("%d",&c);
    if (c==0){
      e--;
      continue;
    }
    newnode->coe=c;
    if (h2==NULL)
      h2=newnode;
    else{
      newnode->link=h2;
      h2=newnode;
    }
    e--;
  }
  printf("\n");
  t=h2;
  while (t!=NULL){
     printf("%dx^%d+ ",t->coe,t->exp);
     t=t->link;
  }
  printf("\n\n");

  polyadd();

  printf("\n");return 0;
}

