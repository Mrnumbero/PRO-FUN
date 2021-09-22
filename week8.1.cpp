#include<stdio.h>
int fac(int x)
{
	int f=1;
	for(int i=1;i<=x;i++)f=f*i;
	return f;
}
void permutation(int x,int y)
{
	int p;
	p=fac(x)/fac(x-y);
	printf("Permutation : %d\n",p);
}
void combination(int x,int y)
{
	int c,n;
	n=fac(y)*fac(x-y);
	c=fac(x)/n;
	printf("Combination : %d\n",c);
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	permutation(n,r);
	combination(n,r);
	return 0;
}
