#include<stdio.h>
int main()
{
	int n,t=0;
	int a[1001]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)       //ð�����򼴿ɣ�ע��j��ȡֵ 
		{
			if(a[j]>a[j+1])          
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
