#include<stdio.h>
void insort(int a[],int n){
  int i,j,key;
  for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }
}
int main(){
  int a[10],n,i;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  printf("\nEnter elements:\n");
  for (i=0;i<n;i++)scanf("%d",&a[i]);
  printf("\nSorted Array: ");
  insort(a,n);
  for (i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
