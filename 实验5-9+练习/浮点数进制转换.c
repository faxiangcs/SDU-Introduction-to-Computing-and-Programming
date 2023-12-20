#include<stdio.h>

#include<string.h>

#include<math.h>

int main()

{
	double ten2=0.0; 
	int a=0,b=0,i=0,m=0,h=0,ten1=0,u=0,v=0,z=0,count=0;
	char ax[999]="\0",dx[999]="\0",cx[999]="\0",fx[9]="\0";
	int bx[999]={0},ex[999]={0};
	scanf("%d%d",&a,&b);
	scanf("%s",ax);
	m=strlen(ax);
	for(i=0;i<m;i++)
	{
		if(ax[i]=='.')
	    {
	        h=i;
	        break;
		}	
	}
	if(ax[0]=='0'&&h==1)
	printf("0");
	else
	{
		for(i=0;i<h;i++)
	{
		if(ax[h-1-i]>='0'&&ax[h-1-i]<='9')
		bx[i]=ax[h-1-i]-48;
		else
		bx[i]=ax[h-1-i]-87;
		ten1=ten1+bx[i]*pow(a,i);
	}
	i=0;
	while(ten1!=0)
	{
		if(ten1%b>=0&&ten1%b<=9)
		cx[i]=ten1%b+48;
		else
		cx[i]=ten1%b+87;
		ten1=ten1/b;
		i++;
		}

	z=strlen(cx);
	for(i=0;i<z;i++)
	dx[i]=cx[z-1-i];
	printf("%s",dx);}
	printf(".");//整数进制转化

	for(i=h+1;i<m;i++)
	{  if(ax[i]>='0'&&ax[i]<='9')
		ex[i-h-1]=ax[i]-48;
		else
		ex[i-h-1]=ax[i]-87;
		ten2=ten2+ex[i-h-1]*pow(a,(h-i));

	}//小数十进制转化
	i=0;
	while(ten2!=0.0&&count<8)
	{   v=ten2*b;
		if(ten2*b>=0&&ten2*b<10)
		u=ten2*b+48;
		else
		u=ten2*b+87;
		fx[i]=u;
		ten2=ten2*b-v;
		i++;
		count++;

	}
	printf("%s",fx);//小数进制转化及输出 
	return 0;
}
