#include<stdio.h>
#include<math.h>
int main()
{
	int a[10001]={0};
	int n,m,min,num=0;
	scanf("%d",&n);
	m=pow(2,n);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]); 
	}
	min=a[0];
	for(int i=0;i<m;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			num=i;
		}
	}
	printf("%d",num);
	return 0;
}
