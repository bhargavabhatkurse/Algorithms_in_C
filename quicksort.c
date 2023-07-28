//quick sort
#include <stdio.h>

void print(int *a) {
for(int i=0;i<5;i++) printf("%d ",a[i]);
}

void exchange(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}


int partition(int *a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    
    do {
    while(i<high && a[i]<=pivot) i++;
    while(j>=0 && a[j]>pivot) j--;
    
    if(i<j) {
    exchange(&a[i],&a[j]);
    }
    }while(i<=j);
    
    if(i>j) {
   exchange(&a[low],&a[j]);
    }
    return j;
}


void quick(int *a,int low, int high) {
    if(low<high) {
        int partition_index = partition(a,low,high);
        quick(a,low,partition_index-1);
        quick(a,partition_index+1,high);
    }
    
}

int main()
{   int n =5;
   int a[] = {4,5,3,2,1};
 
  quick(a,0,n-1);
  print(a);
  return 0;
}
