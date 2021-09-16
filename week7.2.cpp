#include<stdio.h>
int Max(int x ,int y)
{
	int i;
	if(x>y) i=x;
	if(x<y) i=y;
	if(x=y) i=x;
	 return i;
}
int main(){
	int a,b,c,d,e;
	int max;
 	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
 	max=Max(Max(Max(a,b),Max(c,d)),e);
	printf("%d",max);
	return 0;
}

