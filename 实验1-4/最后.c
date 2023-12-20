#include<stdio.h> 
#include<math.h> 
int main() 
{ 
    int n=0,c=0,a=0,b=0,curw=0,curv=0;
	 scanf("%d%d",&c,&n); 
	 int w[n],v[n]; 
	 int t[n],r[n]; 
	 for(int k=0;k<n;k++) 
	 { 
	     scanf("%d",&w[k]);
		  } 
	for(int k=0;k<n;k++) 
	{ 
	    scanf("%d",&v[k]); }  
	for(int k=0;k<(pow(2,n)-1);k++) 
	{ 
	    for(int i=0;i<n;i++) 
		{ 
		    t[i]=(k&(1u<<i))>>i; 
			} 
		for(int i=0;i<n;i++) 
		{ if(t[i]==1) 
		    { curw+=w[i]; 
			 curv+=v[i]; } } 
		if(curw<=c&&curv>b) 
		{ a=curw;  
		  b=curv;
		   for(int i=0;i<n;i++) 
		   { r[i]=t[i]; } } 
		   curw=0; curv=0; } 
		   for(int i=0;i<n;i++) 
		   { if(r[i]==1) 
		   { printf("%d ",i+1); } } 
		   printf("%d %d",a,b); 
		   return 0;
}
