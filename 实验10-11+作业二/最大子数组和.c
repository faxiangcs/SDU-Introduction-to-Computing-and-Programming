#include<stdio.h>
int main()
{
	int nums[200001];
	int max(int a[],int numssize);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nums[i]);
	}
	m=max(nums,n);
	printf("%d",m);
	return 0;
}
int max(int a[],int numssize)
{
	int i=0,sum=0,max1=a[0];
	for(i=0;i<numssize;i++)
	{
		sum=sum+a[i];
		if(sum>max1)
		    max1=sum;
		else if(sum<0)
		    sum=0;
	}
	return max1;
}
