/* Program that will printout all the rotations typed into it */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	unsigned int len,i,j=0;
	char *str,temp;
	str=(char*)malloc(1000);
	
	printf("ENTER A STRING\n");
	gets(str);
	len=strlen(str);
	realloc(str,len*sizeof(char)+1);
	
	for(i=0;i<len-1;i++)
	{
		temp=str[0];
		for(j=0;j<len-1;j++)//shift the String to right by one Char.
			str[j]=str[j+1];
		str[j]=temp;// Copy Frst Char. Of The String To The End.
		puts(str);
	}

}
	