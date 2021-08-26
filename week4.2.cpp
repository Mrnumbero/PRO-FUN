#include <stdio.h>
main(){
	int d,b=0,i,m,n=1;
	scanf("%d",&d);
	for(i=d;i>0;i=i/2)
	{
		m=i%2;
		b=b+(m*n);
		n=n*10;
	}
	
	printf("%d",b);

}
