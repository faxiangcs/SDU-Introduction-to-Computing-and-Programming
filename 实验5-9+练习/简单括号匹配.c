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
			        break;  //�����������ű������������ 
			    }
		}
		if(a1==a2)
		    printf("Yes");  ///���Ƚ��������Ÿ����Ƿ�һ�� 
		else
		    printf("No");  
	}
	return 0;
	
	
}
