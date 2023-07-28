//refer to comments of previous one solution example
#include <stdio.h>
int V=8;
void print(int *path,int V) {
      printf("\n ");
      for (int i = 0; i < V; i++)
        printf("%d ",path[i]+1);
         printf("%d ",path[0]+1);           //print the first vertex again 
}

int issafe(int v, int G[][V],int *path,int pos) {
    if(G[path[pos-1]][v] == 0) {return 0;}
    
     for (int i = 0; i < pos; i++) 
        if(path[i] == v) {          //if that vertex has already been visited,return false
            return 0;
        }
      
    return 1;
}

void utility(int G[][V], int *path, int V,int pos) {
    if(pos == V) {
     if(G[path[pos-1]][path[0]]) print(path,V);
     return;
    }
    
    for(int v=1;v<V;v++) 
    if(issafe(v,G,path,pos)) {
    path[pos] = v;
    utility(G,path,V,pos+1);
    path[pos] = -1;   //after finding the answer, we have to reset it 
    }
}

void hamiltonian(int G[][V],int V) {
    int path[V];
    for(int i=0;i<V;i++) 
        path[i] = -1;
    
    path[0] = 0;
    
   utility(G,path,V,1);
}

int main()
{

    int G[][8] = {{0,1,1,0,0,0,1,0},
                  {1,0,1,0,0,0,0,1},
                  {1,1,0,1,0,1,0,0},
                  {0,0,1,0,1,0,0,0},
                  {0,0,0,1,0,1,0,0},
                  {0,0,1,0,1,0,1,0},
                  {1,0,0,0,0,1,0,1},
                  {0,1,0,0,0,0,1,0}};
                  
   
hamiltonian(G,V);

    return 0;
}
