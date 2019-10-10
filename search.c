#include<stdio.h>
#include<stdlib.h>
int linear(int a[],int n,int key){
  int i;
  for(i=0;i<n;i++){
    if(a[i]==key){
      return i;
    }
  }
  return -1;
}
void sort(int a[],int n){
  int temp;
  for (int i=0;i<n;i++)
    for (int j=0;j<n-1-i;j++){
      if (a[j]>a[j+1]){
	temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
      }
    }
  printf("\nSorted Array:");
  for (int i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}
int binary(int a[],int n,int key){
  sort(a,n);
  int mid,l,u;
  l=0;
  u=n-1;
  while(l<=u){
    mid=(l+u)/2;
    if(a[mid]==key)
      return mid;
    else if(a[mid]>key)
      u=mid-1;
    else
      l=mid+1;
  }
  return -1;
}
int recbinary(int a[],int n, int key,int l,int u){
  int mid;
  if(l>u)
    return -1;
  mid=(l+u)/2;
  if(a[mid]==key)
    return mid;
  else if(a[mid]>key)
    return recbinary(a,n,key,0,mid-1);
  else
    return recbinary(a,n,key,mid+1,n-1);
}
int main(){
  int a[20],n,key,x,c,i;
  printf("1.Linear Search\n2.Binary Search\n3.Recursive Binary Search\n4.Exit\n");
  while(1){printf("\n");
  scanf("%d",&x);
  if (x==4)break;
  else{
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for (i=0;i<n;i++)scanf("%d",&a[i]);
    printf("\nEnter element to be searched: ");
    scanf("%d",&key);
    switch(x){
    case 1:c=linear(a,n,key);
      if(c==-1)
	printf("\nElement not found");
      else
	printf("\nElement is at index %d",c);
      break;
      
    case 2:c=binary(a,n,key);
      if(c==-1)
	printf("\nElement not found");
      else
	printf("\nElement is at index %d",c);
      break;
      
    case 3:
      sort(a,n);
      c=recbinary(a,n,key,0,n-1);
      if(c==-1)
	printf("\nElement not found");
      else
	printf("\nElement is at index %d",c);
      break;
      
    default:printf("\nInvalid choice");
    }
  }
  }
  printf("\n");
  return 0;
}
