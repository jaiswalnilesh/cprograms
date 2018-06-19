/* Program to copy n chars of first string to end of another String*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int no;
	char *str1,*str2;
	void xstrncat(char* str1,char* str2,int no);
	
	str1=(char*)malloc(1000);
	str2=(char*)malloc(1000);
	
	// Get the Strings from the user
	printf("\nEnter First String:  ");
	gets(str1);

	printf("\nEnter Second String:  ");
	gets(str2);

	printf("\nEnter Number of Chars To Be copied:  ");
	scanf("%d",&no);

	realloc(str1,sizeof(char)*(strlen(str1)+1+n));
	realloc(str2,sizeof(char)*(strlen(str2)+1));


	xstrncat(str1,str2,no);
    puts(str1);
}

/*
*Function which copies n chaechters of String2 at the end of String1.
*Parameters : Base add. of String1(Target String)
			: Base add. of String2(Source String)
			: Integer representing no. of charecters to be copied.
*Returns	: void			
*/
void xstrncat(char* str1,char* str2,int no)
{
	while(*(str1++) !='\0');// Take Pointer to the end of target String.
	// Copy n charecters of Source String to the Target String.
	for(str1--;no!=0;no--,str1++,str2++)
		if(str2 != '\0')
		*str1=*str2;
		*str1='\0';
}
