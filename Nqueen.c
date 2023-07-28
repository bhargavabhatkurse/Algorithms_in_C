#include <stdio.h>
#include <stdlib.h>

int N;
int count = 0;

void print(int arr[][N]) {
   for(int i=0;i<N;i++) {
   for(int j=0;j<N;j++)
   printf("%d ",arr[i][j]);
   printf("\n");
    }
printf("\n");
}
int issafe(int arr[][N],int row,int col) {
    
    for(int i = row;i>=0;i--)       //checking the column
    if(arr[i][col]) return 0;
    
    for(int i = row,j=col;i>=0 && j>=0;i--,j--)    // checking left diagonal
       if(arr[i][j]) return 0;
    
    for(int i = row,j=col;i>=0 && j<N;i--,j++)    // checking right diagonal
       if(arr[i][j]) return 0;
    
    return 1;
}


void nqueen(int arr[][N],int row) {
   if(row == N) {count++;print(arr);return;}
    for(int col = 0;col<N;col++)
        if(issafe(arr,row,col)) {
        arr[row][col] = 1;
        nqueen(arr,row+1); 
        arr[row][col] = 0;
        }
    return;
}

int main() {
   N = 9;
   int arr[N][N];
   
   for(int i=0;i<N;i++) 
   for(int j=0;j<N;j++)
   arr[i][j] = 0;
   
   nqueen(arr,0);
   printf("the number of solutions are: \n%d",count);
    return 0;
}
