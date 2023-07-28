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
//    if it is adjacent  and has the same color, return 0;
    
    
    return 1;  //else return 1;
}

int util(int graph[V][V],int m, int color[V], int v) {
   if(v == V) return 1;   //all the vertices are covered
    for(int c =1;c<=m;c++) {
        if(issafe(graph,v,color,c)) {   //if it is safe to use that color
        color[v] = c;  //set the color
        //try for next vertex
        if(util(graph,m,color,v+1)) return 1;  //if possible, then return true;
        color[v] = 0;  //else reset the color;
    }
}   
    //this happens in the loop. If no color can be assigned to vertex, return false
    return 0;
}

int graphcolor(int graph[V][V],int m) {
   int  color[V];
   for(int i=0;i<V;i++) color[i] = 0;   //intialising the color array to 0;
   
   if(util(graph,m,color,0) == 0) {printf("\n no soln exists\n"); return 0;}  //if no color can be assigned, print no solution
    printarray(color);  //if solution exists, print it
    return 1;  //return true;
}


int main()
{
    int m = 4;      //max m colors
    int graph[][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};   
    
    graphcolor(graph,m);
  // printgraph(graph);
   
    
    return 0;
}
