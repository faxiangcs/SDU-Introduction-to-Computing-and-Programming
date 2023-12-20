#include<stdio.h>
int main()
{
	int n,i,sum=0;
	int a[1001]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(j*j==a[i])
			{
				sum=sum+1;
			}
		}
	}
	printf("%d",sum);
	return 0;
} 
