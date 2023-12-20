#include<stdio.h>
#include<math.h>
int main()
{
	long n,a,i,x,flag=1;
	long c[10000];
	scanf("%ld %ld",&n,&a);
	for(i=0;i<n;i++)
	    scanf("%ld",&c[i]);
	for(i=0;i<n-1;i++)
	{
		x=abs(c[i]-c[i+1]);
		if(x>=a)
		    {flag=0;
		    break;}
	}
	if(flag==1)
	    printf("Yes");
	else
	    printf("No");
	return 0;
} 
