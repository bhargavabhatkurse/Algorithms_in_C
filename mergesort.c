//merge sort
#include <stdio.h>

void print(int *a) {
for(int i=0;i<5;i++) printf("%d ",a[i]);
}

int merge(int *a, int low,int mid,int high) {
  int i = low, j = mid+1,k = low;
  int b[5];
  while(i<=mid && j<=high) 
  if(a[i]<a[j]) b[k++] = a[i++];
  else  b[k++] = a[j++];
  
  if(i>mid)
    while(j<=high)  b[k++] = a[j++];
  else 
      while(i<=mid)  b[k++] = a[i++];
      
     for(int i=low;i<=high;i++) a[i] = b[i];
}


void mergesort(int *a,int low, int high) {
    if(low<high) {
        int mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{   int n =5;
   int a[] = {4,5,3,2,1};
 
 mergesort(a,0,n-1);
 print(a);
 
  return 0;
}
