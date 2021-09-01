#include <stdio.h>
#include <string.h>
int main()
{
	char str[20];
    scanf("%s", str);
    //int i=strlen(str); 
	//while(i--)
	for(int i=strlen(str);i>=0;i--)
	putchar(str[i]);
	
return 0;
}
