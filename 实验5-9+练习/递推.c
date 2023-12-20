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
int f(int n,int x,int y)//y保存当前项，调用时x=0，y=1，表示当前项为1
{
    if(1 == n) 
	    return 1;
	if(2 ==n)
	    return 2;
    if(3==n)
	    return x+y;
	return f(n-1,y,y+x);
}
