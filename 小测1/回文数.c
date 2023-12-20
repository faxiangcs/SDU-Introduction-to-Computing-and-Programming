#include <stdio.h>
int main()
{
    char str[10001];
    int hi=0,lo=0,flag=1;
	scanf("%s",&str);
	while (str[hi]!='\0')
        hi++;
	hi--;
	while(lo<=hi) 
	 {
	 	if(flag==0)
		 	break;
		else
	 	    {
			 	if(str[lo]==str[hi])  
	           {
	  	        lo++;
	        	hi--;
		        }
                else
			        flag=0;
			}
	 }
	
	if(lo>hi)
	  printf("Yes");
	else
	  printf("No");
	return 0;
 } 
