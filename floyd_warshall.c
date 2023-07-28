#include <stdio.h>
#define inf 9999

void printfunc(int dist[4][4]) {
    for(int i=0;i<4;i++) {
      for(int j=0;j<4;j++) 
        printf("%d ",dist[i][j]);
         printf("\n");
    }
}
void fw(int graph[4][4]) {
    int dist[4][4];
    for(int i=0;i<4;i++) 
      for(int j=0;j<4;j++) 
        dist[i][j] = graph[i][j];
        
          for(int k=0;k<4;k++) 
            for(int i=0;i<4;i++) 
              for(int j=0;j<4;j++) 
                if(dist[i][j] > dist[i][k] + dist[k][j])
                         dist[i][j] = dist[i][k] + dist[k][j];
   
   printfunc(dist); 
}
int main()
{
    int graph[4][4] = {{0,3,inf,7},{8,0,2,inf},{5,inf,0,1},{2,inf,inf,0}};
    fw(graph);
    return 0;
}
