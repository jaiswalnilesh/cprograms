/* Program to convert the given Int to String */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main()
{
	int no,c;
	char* str;
	int IntToStr(char* str,int* no);
	
	str=(char*)malloc(6*sizeof(char));// User can Enter maximum Five Digits
	//Get the Integer
	do
	{
	fflush(stdin);
	printf("Enter any Integer:(max five digits) ");
	scanf("%d",&no);
	}while(no<0 || no>99999);

	c = IntToStr(str,&no);

	printf("The no.is %s \n",(str+c));

}

/*
*Function to convert the given integer into its string representation
*Parameters	: Base address of resultant String.
			  Base address of the no to b converted.
*Returns	: Offset to which String has to travel to avoid zeros			  
*/
int IntToStr(char* str,int* no)
{
	 char done='y';
	 int j=0,temp=*no,c=0;
	 int i=10000;	

	  if(temp==0)
	 {
		 *str='0';
		 *(str+1)='\0';
		 return 0;
	 }

	 while (temp !=0)
	 {
		j=temp/i;// Get the respective position digit 
		 *str++=j+48;//convert it to String 
		 temp=temp%i;
		 i=i/10;		
		 c++;
	 }
	*str='\0';
	str=str-c;// Bring the pointer to its Start Position
	c=0;
	while(*(str++) == '0')//Loop to calulate offset 
		c++;
	return c;
 
}