#include<stdio.h>
int main ()
{
	int a[3][3],b[3][3],c[3][3];
	int i,j,m,sum=0;
	for(i=0;i<3;i++)
	   { 
	     for(j=0;j<3;j++)
	    {
			scanf("%d",&a[i][j]); 
		}
		}
	for(i=0;i<3;i++)
		    {
				for(j=0;j<3;j++)
		           scanf("%d",&b[i][j]); 
			}
			       
	//A+B
	for(i=0;i<3;i++)
	{    for(j=0;j<3;j++)
	    {
			c[i][j]=a[i][j]+b[i][j];
		    printf("%d\t",c[i][j]);
		}
	    printf("\n");
	}
	printf("\n");
	//A-B
	for(i=0;i<3;i++)
		{    for(j=0;j<3;j++)
		    {
				c[i][j]=a[i][j]-b[i][j];
			    printf("%d\t",c[i][j]);
			}
		    printf("\n");
		}
	printf("\n");
	//A*B
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(int d=0;d<3;d++)
			{
				m=(a[i][d])*(b[d][j]);
				sum=sum+m;
			}
		c[i][j]=sum;
		sum=0;	
		printf("%d\t",c[i][j]);
		}
	printf("\n");
	}
	printf("\n");
	//A×ªÖÃ
	for(i=0;i<3;i++)
		{    for(j=0;j<3;j++)
		    {
				c[i][j]=a[j][i];
			    printf("%d\t",c[i][j]);
			}
		    printf("\n"); 
		}
	printf("\n");
    return 0 ;
}
