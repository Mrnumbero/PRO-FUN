#include <stdio.h>
main(){
	int d;
	scanf("%d",&d);
	int m,b=0,n=1;
	while(d>0)
 	{
		m=d%2;
		b=b+(m*n);
		n=n*10;
		d=d/2; 
	}
	printf("%d",b);

}
