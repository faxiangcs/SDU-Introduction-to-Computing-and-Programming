#include<stdio.h>
#include<math.h>
int main()
{
	int n,b=1;
	double c=1.0;
	double pi=0.0;
	scanf("%d",&n);
	double a =pow(10,-n);
	while((1/c)>a)
	{
		pi=pi+4*(b*(1/c));
		b=-b;
		c=c+2;
	}
	printf("%lf",pi);
	return 0;
}
