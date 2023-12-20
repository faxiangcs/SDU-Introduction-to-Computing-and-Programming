#include<stdio.h>
int main()
{
	int a[10001]={0};
	int n,max;
	scanf("%d",&n);   
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]); 
	}
	max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("%d",max);
	return 0;
}
