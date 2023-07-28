#include <stdio.h>

void exchange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *arr,int n) {
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void select(int *a, int n){
    for(int i=0;i<n-1;i++) { //n-1 iterations
         int min = i;
    for(int j =i+1;j<n;j++) {//n-1 comparisons each time
   if(a[j]<a[min]) min = j;   //finding minimum
    }
    exchange(&a[min],&a[i]);
    }
    
}

void bubble(int *a, int n){
    for(int i=0;i<n-1;i++) { //n-1 iterations
    for(int j =0;j<n-i-1;j++) //n-1 comparisons each time
    if(a[j]>a[j+1]) exchange(&a[j],&a[j+1]);
    //after inner for loop is complete, last element is the greatest element 
    }
    
}

int main()
{   int n = 5;
    int a[] = {3,5,2,1,6};
    int b[] = {3,5,2,1,6};
    
    bubble(a,n);
    print(a,n);
    
    select(b,n);
    print(b,n);

    return 0;
}
