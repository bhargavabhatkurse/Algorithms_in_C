#include <stdio.h>
int V =8;
void print(int *path,int V) {
      printf("\n ");
      for (int i = 0; i < V; i++)
        printf("%d ",path[i]+1);  //adding 1 to display the first vertex as 1 instead of 0
         printf("%d ",path[0]+1); //first vertex display as 1 instead of 0
}

int issafe(int v, int G[][V],int *path,int pos) {
    if(G[path[pos-1]][v] == 0) {return 0;}  //if there is no edge between previously selected vertex in path[] and the current considered vertex v, then return false
    
     for (int i = 0; i < pos; i++)   //if already selected before, return false
        if(path[i] == v) {return 0;}
      
    return 1;  //it is safe
} 

int utility(int G[][V], int *path, int V,int pos) {
    if(pos == V) {   //after all vertex are selected, we will get v =  V
     if(G[path[pos-1]][path[0]]) return 1;  //if there is an edge from last vertex to first vertex, return 1
     else return 0;  //else 0;
    }
    
    for(int v=1;v<V;v++)   //not staring from 0 as 0 is assumed to be the first vertex already selected
    if(issafe(v,G,path,pos)) {  //if safe
    path[pos] = v;  //set that position in the path[] as that vertex v
    if(utility(G,path,V,pos+1) == 1) return 1;  //check for the possible selection for next position in path[]
    path[pos] = -1;  //if not, reset
 
    }
    return 0;  //no solution is found, return 0;
}

void hamiltonian(int G[][V],int V) {
    int path[V];
    for(int i=0;i<V;i++) path[i] = -1;   //set all paths to -1 initially
    path[0] = 0;  //starting vertex is assumed to be 0;
    if(utility(G,path,V,1) == 0) {printf("\nno soln");return;} //starting from pos=1 in path[] as path[0] is 0
    print(path,V);
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
                  
    int G1[][5] =       {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0}};

hamiltonian(G,V); 

hamiltonian(G1,5);  //no solution for this graph
    return 0;
}
