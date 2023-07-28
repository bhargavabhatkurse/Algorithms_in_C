
#include <stdio.h>
typedef struct {
    int p;
    int w;
}node;

void sortPW( node *object,int n) {
float ratio[5];
for(int i=0;i<n;i++) {
    ratio[i] = (float)object[i].p/object[i].w;   //calculating the P/W ratio

}

for(int i=1;i<n;i++) {
    float r = ratio[i];
    node k = object[i];
    
    int j = i-1;
    while(j>=0 && ratio[j]<r) {
    ratio[j+1] = ratio[j];   //exchanging in float array and object array
    object[j+1] = object[j];
    j--;
    }
    ratio[j+1] = r;
    object[j+1] = k;
    
   
   }   
}

void sortP( node *object,int n) {
for(int i=1;i<n;i++) {
    node k = object[i];
    
    int j = i-1;
    while(j>=0 && object[j].p<k.p) {  //max profit(descending order)
    object[j+1] = object[j];
    j--;
    }
    object[j+1] = k;
}
}

void sortW( node *object,int n) {
for(int i=1;i<n;i++) {
    node k = object[i];
    
    int j = i-1;
    while(j>=0 && object[j].w>k.w) { //min weight(ascending order)
    object[j+1] = object[j];
    j--;
    }
    object[j+1] = k;
}
    
}

void print(float *x,int n,float profit) {
    for(int i=0;i<n;i++) printf("%f ",x[i]);
    printf("\nprofit = %f \n\n",profit);
}

void knapsack(int n,int m,node *object) {
int i;
float x[n];
for(int i=0;i<n;i++) x[i] =0.0;
int u = m;
float profit=0.0;

for(i=0;i<n;i++) {
    if(object[i].w>u) break;
    x[i] = 1.0;
    profit += object[i].p;
    u-=object[i].w;
}
if(i<=n) {
    x[i] = (float)u/object[i].w;
    profit += x[i]*object[i].p;
}

    print(x,n,profit);
}


int main()
{
   int n = 3;
   int m = 20;
   
   node object[] = {{25,18},{24,15},{15,10}};
   
   //max profit
sortP(object,n);  
knapsack(n,m,object);
   
   //min weight
sortW(object,n);
knapsack(n,m,object);
 
  //p/w ratio 
sortPW(object,n);
knapsack(n,m,object);
   
    return 0;
}
