#include <stdio.h>
int m = 30;
int w[] = {5,10,12,13,15,18};
int x[] = {0,0,0,0,0,0};

void sum(int s,int k,int r) {
  x[k] = 1;
  if(s + w[k] == m) {
            printf("\n");
            for(int i=0;i<=k;i++) 
                printf("%d ",x[i]);
  }
else if(s + w[k] + w[k+1] <=m)  
            sum(s+w[k],k+1,r - w[k]);
    
if((s+r-w[k]) >=m && s+w[k+1]<=m) {
                x[k] = 0; 
                sum(s,k+1,r - w[k]);
        }
}


int main()
{
   sum(0,0,73);
   
    return 0;
}
