//PROGRAM TO REMOVE VOWELS IN A STRING
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char again='n';
	char * str=(char *)malloc(sizeof(char)*100);
	char *removeVowels(char *str);
	do
	{
		printf("Enter A String To Delete All Vowels From It : ");
		fflush(stdin);
		gets(str);		
		realloc(str,((strlen(str)+1)*sizeof(char)));
		printf("The String After Removing All Vowels is \n\t");
		puts(removeVowels(str));
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}
/*
METHOD TO REMOVE VOWELS IN A STRING
@param str : input string to remove vowels
@return char * : the vowels removed string
*/
char *removeVowels(char *str)
{
	char * result1=str,*result=str;
	result=result1;
	while(*str)
	{
		if(!(*str=='a' || *str=='A' || *str=='e' || *str=='E' || *str=='i' || *str=='I' || *str=='o' || *str=='O' || *str=='u' || *str=='U'))
			*result1++=*str;
		str++;
	}
	*result1='\0';
	return result;
}
