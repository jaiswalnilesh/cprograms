//PROGRAM TO REMOVE THE "the" OCCURANCES FROM THE STRING
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

//METHOD TO REMOVE THE "the" OCCURANCES FROM THE STRING
/*
@param char * : the strig from which the "the" is to be removed
@return char * : the "the" removed string
*/
char *removeThe(char *str)
{
	char *str1=str,*retStr=str;//str1 used to copy the data sequentially
								//retstr is constantly pointing to start
	while(*str)
	{
		if(*str!='\0' && (*str=='t' || *str=='T'))
			if(*(str+1)!='\0' && (*(str+1)=='h' || *(str+1)=='H'))
				if(*(str+2)!='\0' && (*(str+2)=='e' || *(str+2)=='E'))
					if(((str==retStr)||(*(str-1)==' ')) && ((*(str+3)=='\0')||(*(str+3)==' ')))
					{
						if(*(str+3)=='\0')//if the end is recieved then stop
								//copying and the space that we ignored,revoke that
						{
							str1--;
							break;
						}
						str+=4;
					}
		*str1++=*str++;
	}
	*str1='\0';
	return retStr;
}



/*char *removeThe(char *str)
{
	char *str1=str,*retStr=str;
	int i,j;
	while(*str)
	{
		if(*str!='\0' && (*str=='t' || *str=='T'))
			if(*(str+1)!='\0' && (*(str+1)=='h' || *(str+1)=='H'))
				if(*(str+2)!='\0' && (*(str+2)=='e' || *(str+2)=='E'))
					if(((str==retStr)||(*(str-1)==' ')) && ((*(str+3)=='\0')||(*(str+3)==' ')))
					{
						i=0;
						str1=str+4;
						while(!(( (*str1=='t' || *str1=='T') && (*(str1+1)=='h' || *(str1+1)=='H') && (*(str1+2)=='e' || *(str1+2)=='E') &&(((*(str1-1)==' ')&&((*(str1+3)=='\0')||(*(str1+3)==' ')))))||(*str1=='\0')))
						{
							str1++;
							i++;
						}
						for(j=0;j<i;j++)
							*(str+j)=*(str+3+j);
						
						str+=(j-1);
					}
			str++;
	}
	return retStr;
}
*/
