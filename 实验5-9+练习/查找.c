#include<stdio.h>
int main()
{
	int n,m,flag=0;
	int a[1000001];
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);	
	}
	for(int i=0;i<n;i++)
	{
		if(m==a[i])
		{
			printf("%d",i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("-1");
	}
	
	return 0;
}
