#include <stdio.h>
typedef struct{
    int u;
    int v;
    int w;
}edgestruct;

void print(edgestruct *A,int n) {
   printf("\nedges to include: \n");
   for(int i =0;i<n-1;i++)
    printf("%d %d %d\n",A[i].u,A[i].v,A[i].w);
    printf("\n");
}

void sort(edgestruct *edge,int n) {

for(int i=1;i<n;i++) {
   edgestruct k = edge[i];
    int j = i-1;
    while(j>=0 && edge[j].w>k.w) {   //ascending order of weights sort
    edge[j+1] = edge[j];
    j--;
    }
    edge[j+1] = k;
   }   
}


int find(int x, int *parent) {
    if(parent[x] == x) return x;  //if it is the parent of itself, return it
    else return find(parent[x],parent);  //else find the parent of parent[x]
}

void kruskal(edgestruct *edge,int n) {

edgestruct A[n-1];   //n-1 edges are needed to connect n  nodes

int parent[n];
for(int i=0;i<n;i++) parent[i] = i;   //every node is the parent of itself in the beginning

int count = 0;
int i = 0;

//union and find method
while(count != n-1) {  //n-1 edges are included 
    
    edgestruct currentedge;
           currentedge = edge[i]; //selected an edge
           
int sourceparent = find(currentedge.u,parent);  //parent of u
int destparent = find(currentedge.v,parent);    //parent of v

if(sourceparent != destparent) {  //if they don't belong to the same set
   
    A[count] = currentedge;   //add the edge to answer
    count++;  //count only increased when we add a new edge
    parent[sourceparent] = destparent; //union
}
i++;  //i will increase even if the current edge is not included so that we get the new edge.

}
print(A,n);
}

int main()
{   int n = 4;
    int E = 4;
    edgestruct edge[20];
    for(int i=0;i<E;i++)
        scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);

sort(edge,n);
kruskal(edge,n);
    return 0;
}

/*
0 1 2
0 2 3
1 3 4
2 3 5

unsorted order
0 2 3
0 1 2
2 3 5
1 3 4
*/
