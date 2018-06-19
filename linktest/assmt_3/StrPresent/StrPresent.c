/* Program to Check that whether the given String is Present in another or not */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	
	char *str1,*str2;
	int xstrstr(char* str1,char* str2);
	
	str1=(char*)malloc(100);
	str2=(char*)malloc(100);
	// Get the Strings from the user
	printf("\nEnter First String:  ");
	gets(str1);

	printf("\nEnter Second String:  ");
	gets(str2);

	realloc(str1,sizeof(char)*(strlen(str1)+1));
	realloc(str2,sizeof(char)*(strlen(str2)+1));


	printf("\n\t\tPosition = %d\n",xstrstr(str1,str2));
   
}
/*
*Function which checks whether the given String is present in another or not.
*Parameters : Base add. of Frst String.
			: Base add. of Second String.
* Returns	: Integer indicating position where the string is present in frst String.
			: Returns -1 if String is not Present in the Frst String.
*/

int xstrstr(char* str1,char* str2)
{
	int i,j,pos=-1,len1,len2;
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1>len2)//Check only if length of frst String is greater then second
	{
		for(i=0;len2<=(len1-i);i++)
		{
			// Check whether the first elemnet of secon tring is present in the frst or not.
			if(str1[i] == str2 [0])
			{//If yes Compare rest of the String with the following charechters.
					pos=i;
					for(j=0;j<len2;j++)
					{//
						if(!(str1[i+j]==str2[j]))// If string doesn't match break make pos=-1.
						{
							pos=-1;
							break;
						}
					}
			}
		
		}
		return pos;
	}
	else
		return-1;
	
}
