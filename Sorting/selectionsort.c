#include<stdio.h>

int main(){
  
  int n,i,j,*a,temp,min;
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0;i<n;i++)
  scanf("%d",a+i);
  for(i=0;i<n-1;i++){
   min =i;
  for(j=i+1;j<n;j++){
   if(*(a+j)<*(a+min))
    min = j;
  }
   temp = *(a+min);
    *(a+min) = *(a+i);
    *(a+i) = temp;
  for(int k=0;k<n;k++)
  printf("%d ",*(a+k));
  printf("\n");
 }
  return 0;
}
