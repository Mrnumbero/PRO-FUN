#include<stdio.h>
int Max_num(int x ,int y)
{
 	 if(x>y)return x;
	 if(y>x)return y;
	 else return 0;
}
int main(){
	int a,b;
 	scanf("%d%d",&a,&b);
	printf("%d",Max_num(a,b));
	return 0;
}

