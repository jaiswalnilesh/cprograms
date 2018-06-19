/* Program to convert the given SRTING to FLOAT */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main()
{
	double no=0;
	char* str;
	char ok;
	char StrToFloat(char* str,double* no);
	str=(char*)malloc(1000);
	// Get a String from the user
	printf("Enter any float No.:  ");
	scanf("%s",str);
	realloc(str,sizeof(char)*(strlen(str)+1));

	ok=StrToFloat(str,&no);// Call the function which converts String to Float

	if(ok=='y')
		printf("The no.is %f \n",no);
	else
		printf("No. is not valid \n");
}

/*
* Function to convert given String to a float variable
* Parameters : Accepts the base Address of the given String
			   Base address of the no. in which result is going to be Stored
* Returns	 : Character representing whether the task is done successfully or not.
*/			   
char StrToFloat(char* str,double* no)
{
	 double j,temp=0.00;
	 char done='y';
	 int i=strlen(str);
	 
	 *no=0.00;
	 //First convert the digits before the decimal point
	 while (*str != '.' && *str != '\0')
	 {
		
		if(*str >= 48 && *str < 58)//Check whether the digit is an integer digit or not
		{
			*no=(*no)*10+(*str-48);// Change the digit to integer 
			done='y';				
		}
		else
			return 'n';
		str++;
		i--;
		}

	 if(done == 'y' && *str != '\0')
	 {	
		 str=str+i-1;

		// For the digits after the decimal point		
		 for(;*str != '.';str--)
		 {
					
			if(*str >= 48 && *str < 58)
			{
				j=*str-48;
				temp=(temp/10)+j/10;
				done='y';
			}
			else
				return 'n';
		 }
	 }
		*no=*no+temp;// To get the final no. add the decimal digits and the final int.
		return done;
}