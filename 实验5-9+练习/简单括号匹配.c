#include<stdio.h>
#include<string.h>
int main()
{
	int n=0,a1=0,a2=0;
	char str[1001];
	scanf("%d\n",&n);
	gets(str);
	if(n%2!=0)
	    printf("No");
	else
	{
		for(int i=0;i<n;i++)
		{
			if(str[i]=='(')
			{
				a1++;
			}
			else
			    a2++;
			if(a1<a2)
			    {
			        break;  //过程中左括号必须大于右括号 
			    }
		}
		if(a1==a2)
		    printf("Yes");  ///最后比较左右括号个数是否一致 
		else
		    printf("No");  
	}
	return 0;
	
	
}
