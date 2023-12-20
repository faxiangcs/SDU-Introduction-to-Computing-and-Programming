#include<stdio.h>
int main()
{
	struct good
	{
	    float weight;  //物品重量
	    float value;   //物品价值
	    float pw;    //物品单位重量的价值； pw=value/weight
	};
	int c,n;
	float W=0.0,V=0.0;
	scanf("%d %d",&n,&c);
	struct good goods[1000]; // goods[]为n种物品的结构数组；
	struct good k; 
	for(int i=0;i<n;i++)
	{
		scanf("%f %f",&goods[i].weight,&goods[i].value);
		goods[i].pw=(goods[i].value)/(goods[i].weight);
	}
	for(int j=0;j<n-1;j++)
	{
		for(int i=0;i<n-j-1;i++)
		{
			if (goods[i].pw<goods[i+1].pw)
			{
				k=goods[i];
				goods[i]=goods[i+1];
				goods[i+1]=k;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		W=W+goods[i].weight;
		V=V+goods[i].value;
		if(W>c)
		{
			W=W-goods[i].weight;
			V=V-goods[i].value;
			break;
		}
	}
	printf("%.0f\n%.0f",W,V);
}
