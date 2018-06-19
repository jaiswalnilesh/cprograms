#include "stdio.h"
#include "stdlib.h"

void rev(char *str,char *res);

void main()
{
	char *str,*res;
	str=(char*)malloc(100);
	res=(char*)malloc(100);
	printf("\nEnter a String");
	gets(str);
	rev(str,res);
	puts(res);
}

void rev(char* str,char* res)
{
	if(*str)
		rev(++str,res);
	*res=*str;
	res++;
	res='\0';
	return;

}