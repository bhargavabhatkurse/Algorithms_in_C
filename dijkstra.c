#include <stdio.h>
#define V 9
#define max 9999
typedef enum{false, true}bool;

void print(int dist[V]) {
    
    for(int i=0;i<V;i++)
    printf("%d ",dist[i]);   //print dist matrix
    printf("\n");   
}

int min(int dist[V],bool sptset[V]) {
   int min = max,min_index;
   
   for(int i=0;i<V;i++)
    if(sptset[i] == false && min >dist[i])   //vertex not selected and dist is smaller than min
        {min = dist[i]; min_index = i;}
    
    return min_index;
}


void dijkstra(int graph[][V],int source) {
    int dist[V];   //minimum distances 
    bool sptset[V];  //set of vertices which are already selected
    
    for(int i=0;i<V;i++) {
     dist[i] = max; sptset[i] = false;     //set all distances to infinity and no vertex is selected yet aka false.
    }
    
    dist[source] = 0;    //distance of source from itself is 0
    
    for(int count=0;count<V-1;count++) {
    
    int u = min(dist,sptset);  //choosing the minimum vertex to explore next
    sptset[u]= true;
    
    for(int v=0;v<V;v++)   //for every vertex 
//if edge exists b/w v and u and v is not already explored and there is a shorter path to v through u
    if(graph[v][u] && sptset[v] == false && dist[v] > dist[u] + graph[u][v])
            dist[v] = dist[u] + graph[u][v];  //update the estimate.
   
      print(dist);
    }
   
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}
