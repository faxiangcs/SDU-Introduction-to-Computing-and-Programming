#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int main()
{
    int seed,n;
    float s,m;
	scanf("%d",&seed);  //seed种子此处需要自己设置 
	scanf("%d",&n);
	srand(seed);
    for(int k=0;k<n;k++)
    {
		float x=(float)rand()/RAND_MAX +1;
		float y=(float)rand()/RAND_MAX;
		if(y<=(1/x))
		{
			m++;
		}
		s=m/n;
	} 
	printf("%f",s);
    return 0;
}
