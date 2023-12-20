#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char x[1000]={0};
	char t[1000]={0};
    char m[1000]={0};
	long long a,b,n=0,d=0,k=0;
	scanf("%lld %lld",&a,&b);
    scanf("%s",x);	
    n=strlen(x);
	for(int i=0;i<n;i++)
	{
		t[i]=x[n-1-i];
	}
	if(a==10)
	{
	    for(int i=0;i<n;i++)
		{
			d+=(t[i]-48)*pow(10,i);
		}
	}
    if(a==2)
	{
	    for(int i=0;i<n;i++)
		{
			d+=(t[i]-48)*pow(2,i);
		}
	}
	if(a==8)
	{
		for(int i=0;i<n;i++)
		{
			d+=(t[i]-48)*pow(8,i);
		}
	}
	if(a==16)
	{
		for(int i=0;i<n;i++)
		{
			if(t[i]>='a'&&t[i]<='f')
			{
				d+=(t[i]-'a'+10)*pow(16,i);
			}
		    else
				d+=(t[i]-48)*pow(16,i);	
		}	
	}
	if(b==10)
	{
	    printf("%lld",d);	
	}
	if(b==2)
	{
		while(d!=0)
		{
		    k++;
			m[k]=d%2;
		    d=d/2;
		}
		for(int i=k;i>0;i--)
		    printf("%d",m[i]);
	} 
	if(b==8)
		{
			while(d!=0)
			{
			    k++;
				m[k]=d%8;
			    d=d/8;
			}
			for(int i=k;i>0;i--)
			    printf("%d",m[i]);
		} 
	if(b==16)
		{
			while(d!=0)
			{
			    if(d%16<10)
				{
					k++;
					m[k]=d%16+48;
					d=d/16;
				}
				if(d%16==10) 
				{
					k++;
					m[k]='a';
				    d=d/16;
				}
				if(d%16==11) 
				{
					k++;
					m[k]='b';
				    d=d/16;
				}
			    if(d%16==12)
				{
					k++;
					m[k]='c';
				    d=d/16;
				}
				if(d%16==13)
				{
					k++;
					m[k]='d';
				    d=d/16;
				}
				if(d%16==14)
				{
					k++;
					m[k]='e';
				    d=d/16;
				}
				if(d%16==15)
				{
					k++;
					m[k]='f';
				    d=d/16;
				}
			}
			for(int i=k;i>0;i--)
				printf("%c",m[i]);
		} 
	return 0;
}
