//abdul bari channel dynamic 0/1 knapsack
#include <stdio.h>
int max(int a,int b) {return a>b?a:b;}

int  knapsack(int *p, int *wt, int W, int n) {
 int k[n+1][W+1];    //n+1 rows(0-n) and w+1 columns(0-W)
 for(int i=0;i<=n;i++)
 for(int w=0;w<=W;w++) {
 if(i == 0 || w==0) k[i][w] = 0;
 else if(wt[i-1]<=w) k[i][w] = max(p[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);  //max of previous column and profit 
 else k[i][w] =  k[i-1][w];  //same as the previous column 
 }
 
 /*
 //printing the array k
 for(int i=0;i<=n;i++) {
 for(int w=0;w<=W;w++)
 printf("%d ",k[i][w]);
 printf("\n");
 }
 */
 
 
 return k[n][W];
}

int main()
{ int p[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = 3;
    
   printf("max profit = %d",knapsack(p,wt,W,n));
    return 0;
}
