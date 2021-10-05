#include<stdio.h>
void clock(int x)
{
	int s,m,h;
	s=x%60;
 	m=(x%3600)/60;
 	h=x/3600;
 	printf("%d:%d:%d",h,m,s); 
}
int main(){	
	int t;
	printf("input time : ");
	scanf("%d",&t);
  	clock(t);
  	
   return 0;
}
