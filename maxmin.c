#include <stdio.h>
typedef struct {
    int max;
    int min;
}pair;

pair maxmin(int *a,int i,int j) {
    int max;
    int min;
    
    if(i == j ) {printf("*\n");max=a[i];min=a[i];}
    else if(j == i+1) {
        printf("&\n");
        if(a[i]>a[j]) {max = a[i],min= a[j];}
        else {min = a[i],max= a[j];}
    }
    else {
        printf("(\n");
        int mid = (i+j)/2;
        pair p1 = maxmin(a,i,mid);
        pair p2 = maxmin(a,mid+1,j);
        if(p1.max > p2.max) max = p1.max;
        else max = p2.max;
        if(p1.min < p2.min) min = p1.min;
        else  min = p2.min;
    }
    pair p = {max,min};
    return p;
}

int main()
{
    int a[] = {1,3,5,7,9};
    int n = 5;
    pair p = maxmin(a,0,n-1);
    printf("max = %d min = %d",p.max,p.min);

    return 0;
}
