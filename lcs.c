#include <stdio.h>
#include <string.h>

int max(int a,int b) {return a>b?a:b;}


int recursion(char *str1, char* str2,int i, int j){  //i and j are 0,0 initially
    if(str1[i] =='\0' || str2[j] == '\0') return 0;
    else if(str1[i]== str2[j]) return 1+recursion(str1,str2,i+1,j+1);  //1 + next character
    else return max(recursion(str1,str2,i,j+1),recursion(str1,str2,i+1,j));  //max(next of column, next of row)
}



int dynamic(char *str1, char* str2,int m, int n) {
    int lcs[m+1][n+1]; //first row and column will be 0;
    
    for(int i=0;i<m+1;i++)
    for(int j=0;j<n+1;j++)
    if(i ==0 || j==0) lcs[i][j] = 0;  //first row and first column is initialised to 0
    else if(str1[i-1] == str2[j-1]) lcs[i][j] = 1+lcs[i-1][j-1]; //previos diagonal + 1
    else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]); //max(previous row or column)
    
    return lcs[m][n];  //this element has the length of longest common subsequence
}

int main()
{
    char str1[] = "LONGEST";
    char str2[] = "STONE";
    
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    
    printf("the length of the longest subsequence: %d\n",recursion(str1,str2,0,0));
    printf("the length of the longest subsequence: %d\n",dynamic(str1,str2,str1len,str2len));
    
    return 0;
}
