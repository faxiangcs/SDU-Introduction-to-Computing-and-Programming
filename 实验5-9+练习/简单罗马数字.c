#include<stdio.h>
int main()
{
	int n,sum=0;
	char a[100]={0};
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=0;i<n;i++)
	{
		    if(a[i]==73)
		    {
			sum=sum+1;
		    }
		    if(a[i]==86)
		    {
		    	if(a[i-1]!=73)
			        sum=sum+5;
			    else
			        sum=sum+3;
		    }
		    if(a[i]==88)
		    {   
			    if(a[i-1]!=73)
					sum=sum+10;
				else
					sum=sum+8;
		    }
	}
	printf("%d",sum);
	
}
