#include<stdio.h>
#include<string.h>
int main()
{
	char w[1001];
	char *a= "es";
	char *b="s";
	int i;
	scanf("%s",&w);
	i = strlen(w);
	if(w[i-1]=='s'||w[i-1]=='x'||w[i-1]=='o')
	{
		strcat(w,a);
		printf("%s",w);
	}
	else if(w[i-1]=='y')
	{
		w[i-1]='i';
		strcat(w,a);
		printf("%s",w);
	}
	else if(w[i-1]=='h')
	{
		if(w[i-2]=='c'||w[i-2]=='s')
		{
			strcat(w,a);
			printf("%s",w);
		}
		else
		{
			strcat(w,b);
			printf("%s",w);
		}
	}
    else
		{
			strcat(w,b);
			printf("%s",w);
		}
	return 0;
	

	

}
