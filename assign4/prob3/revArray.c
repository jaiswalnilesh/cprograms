//PROGRAM TO REVERSE A STRING
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char source[50],again='n';
	char* reverseString(char *source);
	do
	{
		printf("Enter A String To Reverse : ");
		fflush(stdin);
		gets(source);
		printf("The Reversed String is \t\t");
		puts(reverseString(source));
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
METHOD TO REVERSE A STRING
@param source : the string to be reversed
@return char * : the reversed string
*/
char* reverseString(char *source)
{
	int count,len=strlen(source);
	char ch;
	for(count=0;count<len/2;count++)
	{
		ch=source[len-count-1];
		source[len-count-1]=source[count];
		source[count]=ch;
	}
	return source;
}