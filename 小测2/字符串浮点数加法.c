#include<stdio.h>
#include<string.h>
int main()
{
	int n=0,m=0,i=0,pa=0,pb=0,k=0,enda=0,endb=0,endc=0,flag=0,a1=2,b1=2;
	char a[10001]={0},b[10001]={0},c[10001]={0},d[10001]={0};
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%d",&m);
	scanf("%s",b);
	for(i=0;i<=n;i++)  //1代表整数，2代表浮点数 
	{if(a[i]=='.')
	        {a1=1;
	        break;}
	}
	for(i=0;i<=m;i++)
		{if(b[i]=='.')
		    {b1=1;
		    break;}
		}
	if(a1==2&&b1==2)    //整数加整数 
	{
		if(n>=m)
		{   k=n-m;
		    for(i=0;i<k;i++)
		    c[i]='0';
		    for(i=0;i<n;i++)
		    {
				c[i+k]=b[i];
			}
			for(i=n-1;i>=0;i--)
			{
			    if(a[i]+c[i]+flag>48+48+9)
				{
					d[i]=a[i]+c[i]+flag-10-48;
					flag=1;
				}
				if(a[i]+c[i]+flag<=48+48+9)
				{
					d[i]=a[i]+c[i]+flag-48;
					flag=0;
				}
			}
			if(flag==1)
			{
				printf("1");
				printf("%s",d);
			}
			else
			{
				printf("%s",d);
			}
		}	        
	    if(n<m)
	    {k=m-n;
		for(i=0;i<k;i++)
		    c[i]='0';
		for(i=0;i<n;i++)
		{
			c[i+k]=a[i];
		}
		for(i=m-1;i>=0;i--)
		{
		    if(b[i]+c[i]+flag>48+48+9)
			{
				d[i]=b[i]+c[i]+flag-10-48;
				flag=1;
			}
			if(b[i]+c[i]+flag<=48+48+9)
			{
				d[i]=b[i]+c[i]+flag-48;
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("1");
			printf("%s",d);
		}
		else
		{
			printf("%s",d);
		}
	    }
	}	        
	if(a1==2&&b1==1)  //整数加小数 
	{for(i=0;a[i]!='\0';i++)          
		pa++;
	for(i=0;b[i]!='.';i++)
		pb++;
	if(pa>=pb)
	{
		k=pa-pb;
		for(i=0;i<k;i++)
		{
			c[i]='0';
		}
		for(i=0;i<m;i++)
		{
			c[i+k]=b[i];           //整体右移，将小数点放在同一位置 
		}	
	for(i=0;c[i]!='\0';i++)
		{
			endc++;                
		}
	for(i=endc-1;i>=pb+k;i--)
	{
		d[i]=c[i];
	}
	for(i=pb+k-1;i>=0;i--)
	{
	    if(a[i]+c[i]+flag>48+48+9)
		{
			d[i]=a[i]+c[i]+flag-10-48;
			flag=1;
		}
		if(a[i]+c[i]+flag<=48+48+9)
		{
			d[i]=a[i]+c[i]+flag-48;
			flag=0;
		}	
	}
	if(flag==1)
	{
		printf("1");
		printf("%s",d);
	}
	else
	{
		printf("%s",d);
	}
	}
    if(pb>pa)
	{
		k=pb-pa;
		for(i=0;i<k;i++)
		{
			c[i]='0';
		}
		for(i=0;i<n;i++)
		{
			c[i+k]=a[i];           //整体右移，将小数点放在同一位置 
		}	
    for(i=0;b[i]!='\0';i++)
		{
			endb++;                
		}
	for(i=endb-1;i>=pb;i--)
	{
		d[i]=b[i];
	}
	for(i=pb-1;i>=0;i--)
	{
	    if(b[i]+c[i]+flag>48+48+9)
		{
			d[i]=b[i]+c[i]+flag-10-48;
			flag=1;
		}
		if(b[i]+c[i]+flag<=48+48+9)
		{
			d[i]=b[i]+c[i]+flag-48;
			flag=0;
		}	
	}
    if(flag==1)
	{
		printf("1");
		printf("%s",d);
	}
	else
	{
		printf("%s",d);
	}	
	}
	}
	if(a1==1&&b1==2)  //整数加小数 
	{for(i=0;b[i]!='\0';i++)          
		pb++;
	for(i=0;a[i]!='.';i++)
		pa++;
	if(pb>=pa)
	{
		k=pb-pa;
		for(i=0;i<k;i++)
		{
			c[i]='0';
		}
		for(i=0;i<n;i++)
		{
			c[i+k]=a[i];           //整体右移，将小数点放在同一位置 
		}	
	
	for(i=0;c[i]!='\0';i++)
	{
		endc++;                
	}
	for(i=endc-1;i>=pa+k;i--)
	{
		d[i]=c[i];
	}
	for(i=pa+k-1;i>=0;i--)
	{
		if(b[i]+c[i]+flag>48+48+9)
		{
			d[i]=b[i]+c[i]+flag-10-48;
			flag=1;
		}
		if(b[i]+c[i]+flag<=48+48+9)
		{
			d[i]=b[i]+c[i]+flag-48;
			flag=0;
		}	
	}
	if(flag==1)
	{
		printf("1");
		printf("%s",d);
	}
	else
	{
		printf("%s",d);
	}
	}
	if(pa>pb)
	{
        k=pa-pb;
		for(i=0;i<k;i++)
		{
			c[i]='0';
		}
		for(i=0;i<m;i++)
		{
			c[i+k]=b[i];           //整体右移，将小数点放在同一位置 
		}	
	for(i=0;a[i]!='\0';i++)
	{
		enda++;                
	}
	for(i=enda-1;i>=pa;i--)
	{
		d[i]=a[i];
	}
	for(i=pa-1;i>=0;i--)
	{
		if(a[i]+c[i]+flag>48+48+9)
		{
			d[i]=a[i]+c[i]+flag-10-48;
			flag=1;
		}
		if(a[i]+c[i]+flag<=48+48+9)
		{
			d[i]=a[i]+c[i]+flag-48;
			flag=0;
		}	
	}
	if(flag==1)
	{
		printf("1");
		printf("%s",d);
	}
	else
	{
		printf("%s",d);
	}		
	}
	}	
	if(a1==1&&b1==1)        //浮点数加浮点数 
	{for(i=0;a[i]!='.';i++)         //找到小数点的位置 
	    pa++;
	for(i=0;b[i]!='.';i++)
	    pb++;
	if(pa>=pb)
	{
		k=pa-pb;
		for(i=0;i<k;i++)
		{
			c[i]='0';
		}
		for(i=0;i<m;i++)
		{
			c[i+k]=b[i];           //整体右移，将小数点放在同一位置 
		}
		for(i=0;a[i]!='\0';i++)
		{
			enda++;
		}
		for(i=0;c[i]!='\0';i++)
		{
			endc++;                //判断谁的小数位数更多 
		}
		if(endc>enda)
		{
			for(i=endc-1;i>pa;i--)               //小数部分相加 
			{
				if(i>enda-1)
				{
					d[i]=c[i];
					flag=0;	
				}
				else if(a[i]+c[i]+flag>48+48+9)
				{
					d[i]=a[i]+c[i]+flag-10-48;
					flag=1;
				}
				else if(a[i]+c[i]+flag<=48+48+9)
				{
					d[i]=a[i]+c[i]+flag-48;
					flag=0;
				}
			}
			d[pa]=a[pa];             //小数点 
			for(i=pa-1;i>=0;i--)   //整数部分相加 
			{
				if(a[i]+c[i]+flag>48+48+9)
				{
					d[i]=a[i]+c[i]+flag-10-48;
					flag=1;
				}
				else
				{
					d[i]=a[i]+c[i]+flag-48;
					flag=0;
				}
			}
			for(i=strlen(d)-1;i>=0;i--)
			{
			    if(d[i]=='0')
				{
					d[i]='\0';
					if(d[i-1]=='.')
					    d[i-1]='\0';
				}
				else
					break;
			}
			if(flag==1)
			{
				printf("1");
				printf("%s",d);
			}
			else
			{
				printf("%s",d);
			}
		}
		else
		{
		    for(i=enda-1;i>pa;i--)               //小数部分相加 
		    {
			    if(i>endc-1)
			    {
				    d[i]=a[i];
				    flag=0;	
			    }
			    else if(a[i]+c[i]+flag>48+48+9)
			    {
				    d[i]=a[i]+c[i]+flag-10-48;
				    flag=1;
			    }
			    else if(a[i]+c[i]+flag<=48+48+9)
			    {
				    d[i]=a[i]+c[i]+flag-48;
				    flag=0;
			    }
		    }
		    d[pa]=a[pa];             //小数点 
		    for(i=pa-1;i>=0;i--)   //整数部分相加 
		    {
			if(a[i]+c[i]+flag>48+48+9)
			{
				d[i]=a[i]+c[i]+flag-10-48;
				flag=1;
			}
			else
			{
				d[i]=a[i]+c[i]+flag-48;
				flag=0;
			}
	        }
	    for(i=strlen(d)-1;i>=0;i--)
		{
			if(d[i]=='0')
			{
				d[i]='\0';
				if(d[i-1]=='.')
					d[i-1]='\0';
			}
			else
				break;
		}	
		if(flag==1)
		{
			printf("1");
			printf("%s",d);
		}
		else
		{
			printf("%s",d);
		}	
		}
	}
	else
	{
	        k=pb-pa;
			for(i=0;i<k;i++)
			{
				c[i]='0';
			}
			for(i=0;i<m;i++)
			{
				c[i+k]=a[i];           //整体右移，将小数点放在同一位置 
			}
			for(i=0;b[i]!='\0';i++)
			{
				endb++;
			}
			for(i=0;c[i]!='\0';i++)
			{
				endc++;                //判断谁的小数位数更多 
			}
			if(endc>endb)
			{
				for(i=endc-1;i>pb;i--)               //小数部分相加 
				{
					if(i>endb-1)
					{
						d[i]=c[i];
						flag=0;	
					}
					else if(b[i]+c[i]+flag>48+48+9)
					{
						d[i]=b[i]+c[i]+flag-10-48;
						flag=1;
					}
					else if(b[i]+c[i]+flag<=48+48+9)
					{
						d[i]=b[i]+c[i]+flag-48;
						flag=0;
					}
				}
				d[pb]=b[pb];             //小数点 
				for(i=pb-1;i>=0;i--)   //整数部分相加 
				{
					if(b[i]+c[i]+flag>48+48+9)
					{
						d[i]=b[i]+c[i]+flag-10-48;
						flag=1;
					}
					else
					{
						d[i]=b[i]+c[i]+flag-48;
						flag=0;
					}
				}
				for(i=strlen(d)-1;i>=0;i--)
							{
							    if(d[i]=='0')
								{
									d[i]='\0';
									if(d[i-1]=='.')
									    d[i-1]='\0';
								}
								else
									break;
							}
				if(flag==1)
				{
					printf("1");
					printf("%s",d);
				}
				else
				{
					printf("%s",d);
				}
			}
			else
			{
			    for(i=endb-1;i>pb;i--)               //小数部分相加 
			    {
				    if(i>endc-1)
				    {
					    d[i]=b[i];
					    flag=0;	
				    }
				    else if(b[i]+c[i]+flag>48+48+9)
				    {
					    d[i]=b[i]+c[i]+flag-10-48;
					    flag=1;
				    }
				    else if(b[i]+c[i]+flag<=48+48+9)
				    {
					    d[i]=b[i]+c[i]+flag-48;
					    flag=0;
				    }
			    }
			    d[pb]=b[pb];             //小数点 
			    for(i=pb-1;i>=0;i--)   //整数部分相加 
			    {
				if(b[i]+c[i]+flag>48+48+9)
				{
					d[i]=b[i]+c[i]+flag-10-48;
					flag=1;
				}
				else
				{
					d[i]=b[i]+c[i]+flag-48;
					flag=0;
				}
			    }
			for(i=strlen(d)-1;i>=0;i--)
						{
						    if(d[i]=='0')
							{
								d[i]='\0';
								if(d[i-1]=='.')
								    d[i-1]='\0';
							}
							else
								break;
						}
			if(flag==1)
			{
				printf("1");
				printf("%s",d);
			}
			else
			{
				printf("%s",d);
			}	
			}	
	}
	}
	return 0;
}
