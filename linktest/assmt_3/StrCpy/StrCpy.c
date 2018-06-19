/* Program to copy n chars of first string to another*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int no;
	char *str1,*str2;
	void xstrncpy(char* str1,char* str2,int no);
	
	str2=(char*)malloc(1000);
	// Get The String	
	printf("\nEnter the String:  ");
	gets(str2);
	// Get the number of characters to be copied
	printf("\nEnter Number of Chars To Be copied:  ");
	scanf("%d",&no);

	realloc(str2,sizeof(char)*(strlen(str2)+1));
	str1 = malloc(sizeof(char)*(no+1));


	xstrncpy(str1,str2,no);
    puts(str1);
}

/*
* Function which copies n characters of source String to the target String
* Parameters : Base add. of Source String.
			 : Base add. of Target String.
			 : Integer indicating no. of charecters to be copied.
* Returns	 : Void
*/ 
void xstrncpy(char* str1,char* str2,int no)
{
	for(;no!=0;no--,str1++,str2++)// Copy n charecters.
		if(str2 != '\0')
		*str1=*str2;
		*str1='\0';
}