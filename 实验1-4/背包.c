#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,n,temp,i,wi,vi;  //给定 n 种物品和一背包。物品i的重量（体积）是wi，其价值为vi，背包的容量为C
	int w[n],v[n],x[n],arr[];
	//开始赋值 
	scanf("%d %d",&c,&n); 
	for(a=0;a<n;a++)
	    scanf("%d",&w[a]);
	for(b=0;b<n;b++);
	    scanf("%d",&v[b]);
	//按01列出所有情况
	 for(i=0;i<=(pow(2,n)-1);i++)
	 {
	 	temp=i%2;
	 	i=i/2;
	 	arr[i++]=temp;
	 	
	 }
	 
	
}
