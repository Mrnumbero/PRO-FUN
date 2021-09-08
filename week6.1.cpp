#include<stdio.h>
void Max(int x ,int y)
{
	if(x>y)printf("%d",x);
	if(x<y)printf("%d",y);
	else printf("ERROR");
}
int main(){
	int a,b;
 	scanf("%d%d",&a,&b);
	Max(a,b);
	return 0;
}

