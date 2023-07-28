#include<stdio.h>
int n,m,count=0;
int last[256];

void lastfunc(char pattern[])
{
    for(int i = 0;i<256;i++) {
	
	    last[i] = -1;
	}
	for(int i = 0;i<m;i++) {
	
	    last[(int)pattern[i]] = i;
	}
}

int min(int a, int b)
{
	return(a<b)? a:b;
}


void BM(char text[], char pattern[])
{   lastfunc(pattern);
	int j=m-1,i=m-1;
	
do {
		if(pattern[j]==text[i])
		{  
			if(j==0)
			{
				count+=2;
				printf("Pattern match found at index %d\n", i);
				return;
			}	
			else
			{
				i--; j--;	
			}	
		}
		else
		{  
			i=i+m-min(j, 1+last[(int)text[i]]);
			j=m-1;
		}
	}while(i<=n-1);
	
	printf("Pattern not found\n");
}

void main()
{
	printf("Enter length of text: ");
	scanf("%d", &n);
	printf("Enter length of pattern: ");
	scanf("%d", &m);
	char text[n],pattern[m];
	printf("Enter text: ");
	scanf("%s", &text);
	printf("Enter pattern: ");
	scanf("%s", &pattern);
	count++;
	BM(text,pattern);
	printf("\nStep count= %d", count);
}

