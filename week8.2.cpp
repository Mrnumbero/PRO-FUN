#include<stdio.h> 
void permutation(int x,int y)
{
	int p,n=1,f2=1,r;
	for(int i=1;i<=x;i++){n=n*i;}
	r=x-y;
	for(int a=1;a<=r;a++){f2=f2*a;}
	p=n/f2;
 	printf("Permutation : %d\n",p);
}
void combination(int x,int y)
{
	int c,n=1,r=1,f2=1,d,s;
 	for(int i=1;i<=x;i++){n=n*i;}
  	for(int b=1;b<=y;b++){r=r*b;}
	d=x-y;
	for(int a=1;a<=d;a++){f2=f2*a;}
	s=f2*r;
	c=n/s;
	printf("Combination : %d\n",c);
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	permutation(n,r);
	combination(n,r);
	return 0;
}
