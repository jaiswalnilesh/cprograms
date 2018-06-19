/* Program to convert the given SRTING to FLOAT */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main()
{
	int no;
	char* str;
	char ok;
	char StrToInt(char* str,int* no);
	
	str=(char*)malloc(1000);
	// Collect the number in String
	printf("Enter any Integer:  ");
	scanf("%s",str);

	realloc(str,sizeof(char)*(strlen(str)+1));

	ok=StrToInt(str,&no);

	if(ok=='y')
		printf("The no.is %d \n",no);
	else
		printf("Enter a valid No.\n");
}
/*
*Function to Convert the given String to Integer
*Parameters : Base Address of the Source String
			: Base Address of the integer in which result need to be stored.

*Returns	: Character indicating whether the task is done successfully or not.
			: 'y' if success and 'n' in other case.
*/

char StrToInt(char* str,int* no)
{
	 char done='y';
	 *no=0;

	 while (*str != '\0')//tILL THE END OF THE sTRING
	 {
		if(*str>=48 && *str<58)// Check whether the character is a digit or not.
		{
			*no=(*no)*10+(*str-48);//Convert Charecter to digit and store in the number. 
			done='y';				
		}
		else
		{
			return 'n';		
		}
		str++;
	 }


	return done;
}