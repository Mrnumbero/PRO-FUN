#include<stdio.h>
int main(){	
	 int t,h,m,s;
	 printf("input time : ");
	 scanf("%d",&t);
 	s=t%60;
 	m=(t%3600)/60;
 	h=t/3600;
 	printf("%d:%d:%d",h,m,s);
	return 0;
}
