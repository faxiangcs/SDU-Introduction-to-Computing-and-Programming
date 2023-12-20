#include<stdio.h>
int main()
{
	long a[101][1001]={0};
	int b[1001]={0};
	int m=0,n=0,temp=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%ld",&a[i][j]);
		}	
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[i][j]>a[i][j+1])
		    {
				temp=a[i][j];
				a[i][j]=a[i][j+1];
				a[i][j+1]=temp;
			}
			if(a[i][j]==a[i][j+1])
			{
				j++;
			}
			
	        if(a[i][n-2]==a[i][n-1])
			{
				b[i]=0;
			}
			else
			{
				b[i]=a[i][n-1];
			}
		}
	}
	temp=0;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<m-j-1;i++)
		{
			if(b[i]>b[i+1])
			{
				temp=b[i];
				b[i]=b[i+1];
				b[i+1]=temp;
			}
			if(b[i]==b[i+1])
			{
				i++;
			}
		}
	}
	if(b[m-2]==b[m-1])
	{
		printf("-1");
	}
	else
	{
		printf("%d",b[m-1]);
	}
	return 0;
}

	
	
