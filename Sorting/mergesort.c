#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int m, int r){

}

void mergesort(int a[], int l, int r){
if(l<r){
mergesort(a,l,m);
mergesort(a,m+1,r);
merge(a,l,m,r);
 }
}

int main(){
int *a,i,j,n;
printf("Enter the no. of elements: ");
scanf("%d",&n);
a = malloc(n*sizeof(int));
printf("Enter the elements: ");
for(i=0;i<n;i++)
scanf("%d",a+i);
mergesort(a,0,n-1);
printf("Sorted array: ");
for(j=0;j<n;j++)
printf("%d ",*(a+j));
return 0;
}
