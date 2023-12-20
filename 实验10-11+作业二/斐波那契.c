#include<stdio.h>
int main()
{
	int n,m=1;
	int f(int n);
	scanf("%d",&n);
	m=f(n);
	printf("%d",m);
	return 0;
}
int f(int n)
{
	if(n==2||n==3)
	    return 1;
	else
	    return f(n-1)+f(n-2);
	
}
