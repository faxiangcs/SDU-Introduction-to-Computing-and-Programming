#include<stdio.h>
#include<string.h>
int main()
{
    int n,t,i=0;
    int a[1001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
    for(int j=0;j<n;j++)
    {
		for(int i=0;i<n-j-1;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	    printf("%d ",a[i]);
	return 0;
}
