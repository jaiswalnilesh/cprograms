/* Program to Compare at most 'n' Characters of one String with another*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int no;
	char *str1,*str2;
	int xstrncmp(char* str1,char* str2,int no);
	// Get both the strings from the user
	str1=(char*)malloc(1000);
	str2=(char*)malloc(1000);
	
	printf("\nEnter First String:  ");
	gets(str1);

	printf("\nEnter Second String:  ");
	gets(str2);

	printf("\nEnter Number of Chars To Be Compared:  ");
	scanf("%d",&no);

	realloc(str1,sizeof(char)*(strlen(str1)+1));
	realloc(str2,sizeof(char)*(strlen(str2)+1));


	printf("\n\t\t%d\n",xstrncmp(str1,str2,no));
   
}

/*
*Function which compares 'n' characters of one String With Another
*Parameters : Base add. of 1st String.
			: Base add. of 1st String.
			: Integer representing no. of characters to be compared.
*Returns	: Integer indicating the diff, of Strings.
*/ 			
int xstrncmp(char* str1,char* str2,int no)
{
	int d;
	while(no>0)//Compare n characters  
	{
		if(!(*str1==*str2))// Wheter chars are equal or not.
		{
			d=(*str1-*str2);// If not equal take the diff. and return -1 or 1. 
			if(d>0)
				return 1;
			else
				return -1;
		}
		no--;
		str1++;
		str2++;
	}
	
	return 0;// if numbers are equal return zero.
}
