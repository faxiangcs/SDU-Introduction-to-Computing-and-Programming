#include<stdio.h>
main()
{
	float a,b,c,t=0.0;
	scanf("%f %f %f",&a,&b,&c);
	if(a<b)	
	{
		t=a;
		a=b;
		b=t;
	}
	if(a<c)
	{
		t=a;
		a=c;
		c=t;
	}
	if(b<c)
	{
		t=b;
		b=c;
		c=t;
	}
	printf("%.1f",(a+c)/2);

}
