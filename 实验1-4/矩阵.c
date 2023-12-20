#include<stdio.h>
#include<math.h>
int main()
{
	int a1,a2,a3,a4,a5,a6,a7,a8,a9;
	int b1,b2,b3,b4,b5,b6,b7,b8,b9;
	// ‰»Î 
	scanf("%d %d %d\n%d %d %d\n%d %d %d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9);
	scanf("%d %d %d\n%d %d %d\n%d %d %d",&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8,&b9);
	//A+B
	printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n\n",a1+b1,a2+b2,a3+b3,a4+b4,a5+b5,a6+b6,a7+b7,a8+b8,a9+b9);
	//A-B
	printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n\n",a1-b1,a2-b2,a3-b3,a4-b4,a5-b5,a6-b6,a7-b7,a8-b8,a9-b9);
	//A*B
	printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n\n",a1*b1+a2*b4+a3*b7,a1*b2+a2*b5+a3*b8,a1*b3+a2*b6+a3*b9,a4*b1+a5*b4+a6*b7,a4*b2+a5*b5+a6*b8,a4*b3+a5*b6+a6*b9,a7*b1+a8*b4+a9*b7,a7*b2+a8*b5+a9*b8,a7*b3+a8*b6+a9*b9);
	//A◊™÷√
	printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n\n",a1,a4,a7,a2,a5,a8,a3,a6,a9); 
	return 0;
	
} 
