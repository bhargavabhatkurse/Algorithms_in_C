#include <stdio.h>
void exchange(int *a, int *b) {
    //exchanges the value
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low,int high) {
    //same partition function like that of quicksort
 int pivot = a[low];
 int i=low+1;
 int j= high;

 do {
    while(a[i] <= pivot) i++;
    while(a[j]> pivot) j--;
    
    if(i<j)
        exchange(&a[i],&a[j]);
}while(i<j);

exchange(&a[j],&a[low]);
return j;
}

void ksmall(int *a,int k,int low, int high) {
    k = k-1;     //for eg second smallest will be on the index number 1 i.e one less than k value.
    int p;
    do {
    p = partition(a,low,high);   //gives the index of pth smallest value
    if(k == p){printf("%d ",a[p]);break;}   
    else if(k<p) high = p-1;      //consider only the left half
    else low = p+1;              //consider the right half
    }while(low<=high);
}
int main()
{
   int a[] = {7,9,10,6,5,8,11,16,99,77};
   int n = 10;  //number of elements
   int k = 6;  //6th smallest number
  
  ksmall(a,k,0,n-1); 

    return 0;
}
