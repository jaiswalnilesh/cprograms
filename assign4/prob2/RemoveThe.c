#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char str[50],again;
	char *removeThe(char *str);
	do
	{
		printf("Enter Any String");
		fflush(stdin);
		gets(str);
		printf("The \"the\" Removed String is \n");
		puts(removeThe(str));
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

char *removeThe(char *str)
{
	char *retStr=(char *)malloc(sizeof(char)*50),*retStr1,*str1=str;
	retStr1=retStr;
	while(*str)
	{
		if(*str!='\0' && (*str=='t' || *str=='T'))
		{
			if(*(str+1)!='\0' && (*(str+1)=='h' || *(str+1)=='H'))
			{
				if(*(str+2)!='\0' && (*(str+2)=='e' || *(str+2)=='E'))
				{
					if(((str==str1)||(*(str-1)==' ')) && ((*(str+3)=='\0')||(*(str+3)==' ')))
					{
						str=str+3;
					}
					else
						*retStr++ = *str;
				}
				else
					*retStr++ = *str;
			}
			else
				*retStr++ = *str;
		}
		else
			*retStr++ = *str;
		if(*str!='\0')
			str++;
	}
	*retStr='\0';
	return retStr1;
}

