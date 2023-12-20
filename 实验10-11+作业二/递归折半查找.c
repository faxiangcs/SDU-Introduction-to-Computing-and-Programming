#include<stdio.h>
int main()
{
	int n,m,ans;
	int a[10001];
    int f(int a[],int key,int low,int high);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    ans=f(a,m,0,n);
    printf("%d",ans);
    return 0;
}
int f(int a[],int key,int low,int high)
{
	int mid=(low+high)/2;
	if(low>high)
	{
		return -1;
	}
	if(key==a[mid])
	{
		return mid;
	}
	else if(key>a[mid])
	{
		return f(a,key,mid+1,high);
	}
	else
	{
		return f(a,key,low,mid-1);
	}
}
