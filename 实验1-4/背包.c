#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,n,temp,i,wi,vi;  //���� n ����Ʒ��һ��������Ʒi���������������wi�����ֵΪvi������������ΪC
	int w[n],v[n],x[n],arr[];
	//��ʼ��ֵ 
	scanf("%d %d",&c,&n); 
	for(a=0;a<n;a++)
	    scanf("%d",&w[a]);
	for(b=0;b<n;b++);
	    scanf("%d",&v[b]);
	//��01�г��������
	 for(i=0;i<=(pow(2,n)-1);i++)
	 {
	 	temp=i%2;
	 	i=i/2;
	 	arr[i++]=temp;
	 	
	 }
	 
	
}
