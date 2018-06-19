#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void revStr(char* str,char* result);
void main()
{
	char *str,*result;
	str=(char*)malloc(100);
	printf("Enter a String: ");
	gets(str);
	
	realloc(str,sizeof(char)*(strlen(str)+1));
	result=(char*)malloc(sizeof(char)*(strlen(str)+1));
	revStr(str,result);
	printf("%s",result);
	printf("\n\n");

}

void revStr(char* str,char* result)
{
	if(*str!='\0')
		revStr(++str,result);	
	*(result++)=*(str);
}
