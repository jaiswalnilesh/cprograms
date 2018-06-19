//PROGRAM TO COUNT THE OCCURANCE OF CONSECUTIVE VOWELS IN THE GIVEN STRING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char again='n',*str=(char *)malloc(50*sizeof(char));
	int countConVowels(char *str);
	do
	{
		printf("Enter A String To Check Occurance of Vowels : ");
		fflush(stdin);
		gets(str);
		realloc(str,(strlen(str)+1)*sizeof(char));
		printf("Consecative Occurance Of Vowels in string ");
		puts(str);
		printf(" is %d",countConVowels(str));
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
METHOD TO COUNT THE OCCURANCE OF CONSECUTIVE VOWELS IN THE GIVEN STRING
@param str : the string to be parsed
@return int : the count of occurance of consecutive vowels in the string
*/
int countConVowels(char *str)
{
	int sum=0;
	while(*str!='\0')
	{
		if(*str=='a' || *str=='A' || *str=='e' || *str=='E' || *str=='i' || *str=='I' 
			|| *str=='o' || *str=='O'|| *str=='u' || *str=='U')
		{

			if((*str!='\0')&&(*(str+1)=='a' || *(str+1)=='A' || 
				*(str+1)=='e' || *(str+1)=='E' || *(str+1)=='i' || *(str+1)=='I' || 
				*(str+1)=='o' || *(str+1)=='O' || *(str+1)=='u' || *(str+1)=='U'))
			{				
				sum++;
			}
		}
		str++;
	}
	return sum;
}