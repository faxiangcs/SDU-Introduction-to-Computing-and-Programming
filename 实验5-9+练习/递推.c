#include<stdio.h>
int main()
{
	int m,n;
	int f(int n,int x,int y); 
	scanf("%d",&n);
    m=f(n,1,2);
	printf("%d",m);
	return 0;
}
int f(int n,int x,int y)//y���浱ǰ�����ʱx=0��y=1����ʾ��ǰ��Ϊ1
{
    if(1 == n) 
	    return 1;
	if(2 ==n)
	    return 2;
    if(3==n)
	    return x+y;
	return f(n-1,y,y+x);
}
