#include <stdio.h>
#define max 9999
typedef struct {
    int u;
    int v;
}edgestruct;

void print(int *distance,int V) {
    printf("\nthe distances: ");
    for(int i=0;i<V;i++)
        printf("%d ",distance[i]);
        printf("\n");
}
void bellmanford(int V,int source,int G[][20], edgestruct *edge,int k) {
    
    int distance[20],u,v;
    
    for(int i=0;i<=V-1;i++) {
    distance[i] = max;
    }
    
    distance[source] = 0;
    
    for(int count =0;count<V-1;count++) {  //relax the edges v-1 times
    for(int i=0;i<k;i++) {   //for every edge 
    u = edge[i].u; v = edge[i].v;
    if(distance[v] > distance[u] + G[u][v])
        distance[v] = distance[u] + G[u][v];
    }
    print(distance,V);
    }
    
   
}

int main()
{
    int V,G[20][20],i,j,k=0;
    edgestruct edge[20];
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                edge[k].u=i,edge[k++].v=j;
        }

    int source = 0;
    bellmanford(V,source,G,edge,k);
    return 0;
}
