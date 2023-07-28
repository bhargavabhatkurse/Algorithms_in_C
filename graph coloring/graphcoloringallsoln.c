#include <stdio.h>
int V = 4;
int printgraph(int graph[V][V]) {                  //not really required but for testing
     for(int i =0;i<V;i++) {
      for(int j =0;j<V;j++)
            printf("%d ",graph[i][j]);
             printf("\n");
    }
}


int printarray(int color[V]) {                  //not really required but for testing
     for(int i =0;i<V;i++) 
            printf("%d ",color[i]);
             printf("\n");
    
}

int issafe(int graph[V][V],int v, int color[V], int c) {
    for(int i = 0; i<V;i++)
    if(graph[v][i]  && c == color[i]) return 0;
    
    return 1;
}

void util(int graph[V][V],int m, int color[V], int v) {
   if(v == V) {printarray(color);;return;}
    for(int c =1;c<=m;c++) {
        if(issafe(graph,v,color,c)) {
        color[v] = c;
        util(graph,m,color,v+1);
        color[v] = 0;
    }
}
    return;
}

void graphcolor(int graph[V][V],int m) {
   int  color[V];
   for(int i=0;i<V;i++) color[i] = 0;   //intialising the color array to 0;
   
   util(graph,m,color,0);
    
}


int main()
{
    int m = 4;      //max m colors
    int graph[][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};   
    
    graphcolor(graph,m);
  // printgraph(graph);
   
    
    return 0;
}
