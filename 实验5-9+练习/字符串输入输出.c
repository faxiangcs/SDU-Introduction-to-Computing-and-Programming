#include<stdio.h>
int main()
{
	char str[10001];
	int n,i=0;
	scanf("%d\n",&n);
    for(i=0;i<n;i++)
		{scanf("%[^\n]",str);
	    getchar();
	    printf("%s\n",str);}
	return 0;
} 
