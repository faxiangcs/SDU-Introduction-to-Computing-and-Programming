#include<stdio.h>
int main()
{
	int n,seed,a,b,m;
	int x[10000];
	int r[10000];
	scanf("%d",&n);
	scanf("%d",&seed);
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&m);
	x[0]=seed;
	r[0]=x[0];
	for(int i=0;i<n;i++)
	{
		x[i+1]=(a*x[i]+b)%m;
		r[i+1]=x[i+1];
	}
	for(int i=1;i<=n;i++)
	    printf("%d ",r[i]);
	return 0;
		
}
int f(int n)
{
	
}
