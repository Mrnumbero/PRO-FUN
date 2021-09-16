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
	int m1,m2,m3,m4;
 	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	m1=Max(a,b);
	m2=Max(c,d);
	m3=Max(m1,m2);
	m4=Max(m3,e);
	printf("%d",m4);
	return 0;
}

