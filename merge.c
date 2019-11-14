#include<stdio.h>
void merge(int a[],int lb,int mid,int ub){
  int i=lb,j=mid+1,k=0,temp[10];
  while(i<=mid&&j<=ub){
    if (a[i]<a[j]){
      temp[k]=a[i];
      i++;k++;
    }
    else{
      temp[k]=a[j];
      j++;k++;
    }
  }
  while(i<=mid){
    temp[k]=a[i];
    i++;k++;
  }
  while(j<=ub){
    temp[k]=a[j];
    j++;k++;
  }
  for(i=lb,k=0;i<=ub;i++,k++)
    a[i]=temp[k];
}
void mergesort(int a[],int lb,int ub){
  int mid;
  if(lb<ub){
    mid=(lb+ub)/2;
    mergesort(a,lb,mid);
    mergesort(a,mid+1,ub);
    merge(a,lb,mid,ub);
  }
}
int main(){
  int a[10],n,i;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  printf("Enter elements: \n");
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  mergesort(a,0,n-1);
  printf("\n");
  for (i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
