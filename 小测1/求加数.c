#include<stdio.h>
int main()
{
	int a[10000];
	int n,s,i,j,flag=1;
	scanf("%d\n",&n);
	scanf("%d\n",&s);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n-i;j++)
		{
			if(a[i]+a[j]==s)
			    {printf("%d %d",i,j);
			    flag=0;
			    break;}
		}
	    if(flag==0)
	    break;
	}
	
return 0;
}
