#include<stdio.h>
int partition(int a[],int lb,int ub){
  int pivot=a[lb],right=ub,left=lb,temp;
  while (left<right){
    while((a[left]<=pivot)&&left<ub)
      left++;
    while((a[right]>pivot))
      right--;
    if(left<right){
      temp=a[left];
      a[left]=a[right];
      a[right]=temp;
    }
  }
  temp=a[lb];
  a[lb]=a[right];
  a[right]=temp;
  return right;
}
void quicksort(int a[],int lb,int ub){
  int p;
  if(lb<ub){
    p=partition(a,lb,ub);
    quicksort(a,lb,p-1);
    quicksort(a,p+1,ub);
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
  quicksort(a,0,n-1);
  printf("\n");
  for (i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
