#include<stdio.h>
#include<math.h>
#define M 10001
int main()
{
	int a[M],b[M],c[M];
	char s1[M],s2[M];
	int n,m,i,j,k;
	scanf("%d%s%d%s",&n,s1,&m,s2);
	k=m+n;   //位数 
	for(i=0;i<n;i++)     //逆序存放，转化成数字 
	    a[i]=s1[n-1-i]-'0';
	for(i=0;i<m;i++)
	    b[i]=s2[m-i-1]-'0';
	for(i=0;i<n;i++)    //乘法运算，认真理解 
	{
		for(j=0;j<m;j++)
		{
			c[i+j]+=a[i]*b[j];
		} 
	} 
	for(i=0;i<k;i++)
	{
		if(c[i]>10)
		{
			c[i+1]+=c[i]/10;
			c[i]=c[i]%10;
		}
	}
	  //判断第一位是否是0，是就去掉 
	i=k;
	while(c[i]==0) 
	    i--;
	if(i<0) 
	    printf("0");
	else
	{
	    for(; i>=0; i--)
	    printf("%d",c[i]);
    }
	return 0;
}
	   
