#include <stdio.h>
#include <string.h>
int main()
{
	char str[20];
    scanf("%s", str);
    int i=strlen(str); 
	while(i--)
	putchar(str[i]);
	
return 0;
}
